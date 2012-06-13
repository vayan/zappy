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

void  MoveClient(t_client *cl)
{
  t_setting *setting;

  rm_pl(cl->x, cl->y, cl);
  setting = get_setting(NULL);
  switch (cl->dir)
  {
    case Up:
    cl->y += 1;
    if (cl->y > setting->height_map)
      cl->y = 0;
    break;
    case Down:
    cl->y -= 1;
    if (cl->y < 0)
      cl->y = setting->height_map;
    break;
    case Right:
    cl->x += 1;
    if (cl->x > setting->width_map)
      cl->x = 0;
    break;
    case Left:
    cl->x -= 1;
    if (cl->x < 0)
      cl->x = setting->width_map;
    break;
  }
  add_pl(cl->x, cl->y, cl);
}

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
    cl->dir -= 1;
    if (cl->dir == 0)
      cl->dir = Left;
  }
}

int   turnLeft(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != TurnLeft)
    return (0);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = TurnLeft;
    start_timer(cl->stm);
    printf("Start timer turn left %ld\n", cl->stm->in_nsec);
    return (0);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == TurnLeft &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    printf("turn left %ld \n",cl->stm->in_nsec );
    cl->stm->in_use = -1;
    TurnClient(cl, 0);
    broadcast_to_one_client("ok", cl);
    return (1);
  }
  return (0);
}

int   turnRight(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != TurnRight)
    return (0);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = TurnRight;
    start_timer(cl->stm);
    printf("Start timer turn right %ld\n", cl->stm->in_nsec);
    return (0);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == TurnRight &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    printf("turn right %ld \n",cl->stm->in_nsec );
    cl->stm->in_use = -1;
    TurnClient(cl, 1);
    broadcast_to_one_client("ok", cl);
    return (1);
  }
  return (0);
}

int   MoveFront(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != GoFront)
    return (0);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = GoFront;
    start_timer(cl->stm);
    printf("Start timer move front %ld\n", cl->stm->in_nsec);
    return (0);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == GoFront &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    printf("Can move front %ld \n",cl->stm->in_nsec );
    cl->stm->in_use = -1;
    MoveClient(cl);
    broadcast_to_one_client("ok", cl);
    return (1);
  }
  return (0);
}