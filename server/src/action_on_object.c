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

void  do_take_obj(t_client *cl, Ressource obj)
{
  t_map_case ***map;

  map = get_map(NULL);
  if ((map[cl->x][cl->y])->rsrc[obj] > 0)
  {
    (map[cl->x][cl->y])->rsrc[obj]--;
    cl->rsrc[obj]++;
    broadcast_to_one_client("ok\n", cl);
    pdr(obj, cl);
  }
  else
    broadcast_to_one_client("ko\n", cl);
}

void  do_drop_obj(t_client *cl, Ressource obj)
{
  t_map_case ***map;

  map = get_map(NULL);
  if (cl->rsrc[obj] > 0)
  {
    (map[cl->x][cl->y])->rsrc[obj]++;
    cl->rsrc[obj]--;
    broadcast_to_one_client("ok\n", cl);
    pgt(obj, cl);
  }
  else
    broadcast_to_one_client("ko\n", cl);
}

int   Take_Object(t_client *cl, Ressource obj)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Take)
    return (1);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = Take;
    start_timer(cl->stm);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Take &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    do_take_obj(cl, obj);
    return (0);
  }
  return (1);
}

int   Drop_Object(t_client *cl, Ressource obj)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != Drop)
    return (1);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = Drop;
    start_timer(cl->stm);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Drop &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    do_drop_obj(cl, obj);
    return (0);
  }
  return (1);
}