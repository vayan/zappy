/*
** fork_cl.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun 26 12:53:45 2012 yann vaillant
** Last update Tue Jun 26 12:53:45 2012 yann vaillant
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


int   do_fork_pl(t_client *cl)
{
  cl->teams->to_open += 1;
  broadcast_to_one_client("ok\n", cl);
  enw(cl->teams->to_open, cl);

}

int fork_cl(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Fork)
    return (1);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = Fork;
    start_timer(cl->stm);
    pfk(NULL, cl);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Fork &&
    ( (cl->stm->in_nsec) >= (42000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    do_fork_pl(cl);
    return (0);
  }
  return (1);
}
