/*
** incant.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:54:43 2012 yann vaillant
** Last update Sat Jul 14 13:34:12 2012 yann vaillant
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <time.h>
#include <signal.h>

#include "network.h"
#include "xfunc.h"
#include "map.h"
#include "setting.h"
#include "client.h"
#include "command_fonc.h"

int		can_elev(t_client *cl)
{
  int		nb_pl;
  t_map_case	***map;
  int		*req;
  t_map_case	*cas;

  req = xmalloc(10 * sizeof(int));
  memset(req, 0, 10);
  fill_tab_req(req, cl->level);
  map = get_map(NULL);
  cas = map[cl->x][cl->y];
  nb_pl = count_pl_on_case(cl->level, cas->client);
  if (nb_pl != req[0] || (int)req[Linemate] != (int)cas->rsrc[Linemate] ||
      (int)req[Deraumere]!= (int)cas->rsrc[Deraumere] ||
      (int)req[Sibur] !=(int)cas->rsrc[Sibur] ||
      (int)req[Mendiane] != (int)cas->rsrc[Mendiane] ||
      (int)req[Phiras] != (int)cas->rsrc[Phiras] ||
      (int)req[Thystame] != (int)cas->rsrc[Thystame])
    {
      broadcast_to_one_client("ko\n", cl);
      return (0);
    }
  return (1);
}

int	do_elev(int *req, t_client *cl, t_map_case *cas, int prec)
{
  if (prec == 0 || (int)req[Linemate] != (int)cas->rsrc[Linemate] ||
      (int)req[Deraumere] != (int)cas->rsrc[Deraumere] ||
      (int)req[Sibur] != (int)cas->rsrc[Sibur] ||
      (int)req[Mendiane] != (int)cas->rsrc[Mendiane] ||
      (int)req[Phiras] != (int)cas->rsrc[Phiras] ||
      (int)req[Thystame] != (int)cas->rsrc[Thystame])
    return (0);
  cl->level++;
  if (cl->level == 8)
    cl->teams->nb_lvl_max++;
  return (1);
}

int		do_incant(t_client *cl)
{
  t_map_case	***map;
  t_pl_case	*all_cl_case;
  int		*req;
  int		nb_pl;
  int		dead;

  dead = 0;
  req = xmalloc(10 * sizeof(int));
  map = get_map(NULL);
  memset(req, 0, 10);
  fill_tab_req(req, cl->level);
  all_cl_case = (map[cl->x][cl->y])->client;
  nb_pl = count_pl_on_case(cl->level, all_cl_case);
  if (nb_pl == req[0])
    dead = 1;
  while (all_cl_case)
    {
      incant_broad(all_cl_case->client, map, req, dead);
      all_cl_case = all_cl_case->next;
    }
  cl->stm->in_use = -1;
  xfree(req);
  return (0);
}

int		start_incant_all_on_case(t_client *cl)
{
  t_map_case	***map;

  map = get_map(NULL);
  pic(cl, (map[cl->x][cl->y]));
  broadcast_to_one_client("elevation en cours\n", cl);
  return (0);
}

int		incant(t_client *cl, int first)
{
  t_setting	*setting;

  first = first;
  if (cl->stm->in_use != -1 && cl->stm->in_use != Incant)
    return (1);
  if (cl->stm->in_use == -1)
    {
      if (can_elev(cl) == 0)
	return (0);
      start_incant_all_on_case(cl);
      cl->stm->in_use = Incant;
      start_timer(cl->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Incant &&
      ((cl->stm->in_nsec) >= (300000000000/setting->delay)))
    {
      cl->stm->in_use = -1;
      do_incant(cl);
      return (0);
    }
  return (1);
}
