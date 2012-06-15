/*
** move_player.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun 14 15:40:18 2012 yann vaillant
** Last update Thu Jun 14 15:40:19 2012 yann vaillant
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

void  MoveClient(t_client *cl)
{
  t_setting *setting;

  rm_pl(cl->x, cl->y, cl);
  setting = get_setting(NULL);
  switch (cl->dir)
  {
    case Down:
    cl->y += 1;
    if (cl->y >= setting->height_map)
      cl->y = 0;
    break;
    case Up:
    cl->y -= 1;
    if (cl->y < 0)
      cl->y = setting->height_map - 1;
    break;
    case Right:
    cl->x += 1;
    if (cl->x >= setting->width_map)
      cl->x = 0;
    break;
    case Left:
    cl->x -= 1;
    if (cl->x < 0)
      cl->x = setting->width_map - 1;
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

int   MoveFront(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != GoFront)
    return (1);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = GoFront;
    start_timer(cl->stm);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == GoFront &&
    ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    MoveClient(cl);
    broadcast_to_one_client("ok\n", cl);
    return (0);
  }
  return (1);
}
