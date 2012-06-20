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

void TurnClient(t_client *cl, int turn)
{
  if (turn == 1) //right
  {
    cl->dir += 1;
    if (cl->dir > Left)
      cl->dir = Up;
  }
  if (turn == 0) //left
  {
    if (cl->dir == 0)
      cl->dir = Left;
    else
      cl->dir -= 1;
  }
}

int   turnLeft(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != TurnLeft)
    return (1);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = TurnLeft;
    start_timer(cl->stm);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == TurnLeft &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    TurnClient(cl, 0);
    broadcast_to_one_client("ok\n", cl);
    return (0);
  }
  return (1);
}

int   turnRight(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != TurnRight)
    return (1);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = TurnRight;
    start_timer(cl->stm);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == TurnRight &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    TurnClient(cl, 1);
    broadcast_to_one_client("ok\n", cl);
    return (0);
  }
  return (1);
}