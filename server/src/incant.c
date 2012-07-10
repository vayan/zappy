/*
** incant.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:54:43 2012 yann vaillant
** Last update Tue Jul 10 11:40:50 2012 anatole carlier
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

int	do_elev(int *req, t_client *cl, t_map_case *cas)
{
  int	nb_pl;

  nb_pl = count_pl_on_case(cas->client);
  if (nb_pl < req[0] || (int)req[Linemate] < (int)cas->rsrc[Linemate] ||
      (int)req[Deraumere] < (int)cas->rsrc[Deraumere] ||
      (int)req[Sibur] < (int)cas->rsrc[Sibur] ||
      (int)req[Mendiane] < (int)cas->rsrc[Mendiane] ||
      (int)req[Phiras] < (int)cas->rsrc[Phiras] ||
      (int)req[Thystame] < (int)cas->rsrc[Thystame])
    return (0);
  cas->rsrc[Linemate] -= req[Linemate];
  cas->rsrc[Deraumere] -= req[Deraumere];
  cas->rsrc[Sibur] -= req[Sibur];
  cas->rsrc[Mendiane] -= req[Mendiane];
  cas->rsrc[Phiras] -= req[Phiras];
  cas->rsrc[Thystame] -= req[Thystame];
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
  char		*msg;

  msg = xmalloc (200 * sizeof(char));
  req = xmalloc (10 * sizeof(int));
  memset(req, 0, 10);
  map = get_map(NULL);
  all_cl_case = (map[cl->x][cl->y])->client;
  fill_tab_req(req, cl->level);
  pie(cl, do_elev(req, cl, (map[cl->x][cl->y])));
  plv(NULL, cl);
  bct(NULL, cl);
  sprintf(msg, "niveau actuel : %d\n", cl->level);
  broadcast_to_one_client(msg, all_cl_case->client);
  xfree(msg);
  xfree(req);
  return (0);
}

int		start_incant_all_on_case(t_client *cl)
{
  t_map_case	***map;
  t_pl_case	*all_cl_case;

  map = get_map(NULL);
  all_cl_case = (map[cl->x][cl->y])->client;
  pic(cl, (map[cl->x][cl->y]));
  while (all_cl_case)
    {
      broadcast_to_one_client("elevation en cours\n", all_cl_case->client);
      if (all_cl_case->client != cl)
        incant(all_cl_case->client, 0);
      all_cl_case = all_cl_case->next;
    }
  return (0);
}

int		incant(t_client *cl, int first)
{
  t_setting	*setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Incant)
    return (1);
  if (cl->stm->in_use == -1)
    {
      if (first == 1)
        start_incant_all_on_case(cl);
      cl->stm->in_use = Incant;
      start_timer(cl->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Incant &&
      ( (cl->stm->in_nsec) >= (300000000000/setting->delay)))
    {
      cl->stm->in_use = -1;
      do_incant(cl);
      return (0);
    }
  return (1);
}
