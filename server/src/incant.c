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

int   count_pl_on_case(t_pl_case *all_cl_case)
{
  int i ;

  i = 0;
  while(all_cl_case)
  {
    i++;
    all_cl_case = all_cl_case->next;
  }
  return (i);
}

void  init_tab_req(char *val, int *req)
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

int   do_elev(int *req, t_client *cl, t_map_case *cas)
{
  int   nb_pl;

  nb_pl = count_pl_on_case(cas->client);
  if (nb_pl < req[0] || (int)req[Linemate] < (int)cas->rsrc[Linemate] || 
    (int)req[Deraumere] < (int)cas->rsrc[Deraumere] || (int)req[Sibur] < (int)cas->rsrc[Sibur] ||
    (int)req[Mendiane] < (int)cas->rsrc[Mendiane] || (int)req[Phiras] < (int)cas->rsrc[Phiras] ||
    (int)req[Thystame] < (int)cas->rsrc[Thystame])
    return(0);

  cas->rsrc[Linemate] -= req[Linemate];
  cas->rsrc[Deraumere] -= req[Deraumere];
  cas->rsrc[Sibur] -= req[Sibur]; 
  cas->rsrc[Mendiane] -= req[Mendiane];
  cas->rsrc[Phiras] -= req[Phiras]; 
  cas->rsrc[Thystame] -= req[Thystame];
  cl->level++;
  return (1);
}

int do_incant(t_client *cl)
{
  t_map_case  ***map;
  t_pl_case   *all_cl_case;
  int     *req;
  char    *msg;

  msg = xmalloc (200 * sizeof(char));
  req = xmalloc (10 * sizeof(int));
  memset(req, 0, 10);
  map = get_map(NULL);
  all_cl_case = (map[cl->x][cl->y])->client;
  if (cl->level == 1)
    init_tab_req("1100000", req);
  if (cl->level == 2)
    init_tab_req("2111000", req);
  if (cl->level == 3)
    init_tab_req("2201020", req);
  if (cl->level == 4)
    init_tab_req("4112010", req);
  if (cl->level == 5)
    init_tab_req("4121300", req);
  if (cl->level == 6)
    init_tab_req("6123010", req);
  if (cl->level == 7)
    init_tab_req("6222221", req);
  pie(cl, do_elev(req,cl, (map[cl->x][cl->y])));
  plv(NULL, cl);
  bct(NULL, cl);
  sprintf(msg, "niveau actuel : %d\n", cl->level);
  broadcast_to_one_client(msg, all_cl_case->client);
  free(msg);
  return (0);
}

int   start_incant_all_on_case(t_client *cl)
{
  t_map_case  ***map;
  t_pl_case   *all_cl_case;

  map = get_map(NULL);
  all_cl_case = (map[cl->x][cl->y])->client;
  pic(cl, (map[cl->x][cl->y]));
  while(all_cl_case)
  {
      broadcast_to_one_client("elevation en cours\n", all_cl_case->client);
    if (all_cl_case->client != cl)
      incant(all_cl_case->client);
    all_cl_case = all_cl_case->next;
  }
  return (0);
}

int incant(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Incant)
    return (1);
  if (cl->stm->in_use == -1)
  { 
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