/*
** utils_incant.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:56:05 2012 yann vaillant
** Last update Tue Jul 10 17:55:42 2012 yann vaillant
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

int	count_pl_on_case(int lvl_me, t_pl_case *all_cl_case)
{
  int	i;

  i = 0;
  while (all_cl_case)
  {
    if (lvl_me == all_cl_case->client->level)
      i++;
    all_cl_case = all_cl_case->next;
  }
  return (i);
}

void	init_tab_req(char *val, int *req)
{
  req[0] = val[0] - '0';
  req[1] = val[1] - '0';
  req[2] = val[2] - '0';
  req[3] = val[3] - '0';
  req[4] = val[4] - '0';
  req[5] = val[5] - '0';
  req[6] = val[6] - '0';
  req[7] = val[7] - '0';
  req[8] = val[8] - '0';
}

void	fill_tab_req(int *req, int level)
{
  if (level == 1)
    init_tab_req("1100000", req);
  if (level == 2)
    init_tab_req("2111000", req);
  if (level == 3)
    init_tab_req("2201020", req);
  if (level == 4)
    init_tab_req("4112010", req);
  if (level == 5)
    init_tab_req("4121300", req);
  if (level == 6)
    init_tab_req("6123010", req);
  if (level == 7)
    init_tab_req("6222221", req);
}

void  incant_broad(t_client *cl, t_map_case ***map, int *req, int dead)
{
  char    *msg;

  msg = xmalloc (200 * sizeof(char));
  pie(cl, 
    do_elev(req, cl, 
      (map[cl->x][cl->y]), dead));
  plv(NULL, cl);
  bct(NULL, cl);
  sprintf(msg, "niveau actuel : %d\n", cl->level);
  broadcast_to_one_client(msg, cl);
  xfree(msg);
}
