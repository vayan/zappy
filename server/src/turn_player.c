/*
** turn_player.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:56:08 2012 yann vaillant
** Last update Sat Jul 14 16:03:37 2012 robin maitre
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

void		turn_client(t_client *cl, int turn)
{
  if (turn == 1)
    {
      cl->dir += 1;
      if (cl->dir > Left)
        cl->dir = Up;
    }
  if (turn == 0)
    {
      if (cl->dir == 0)
        cl->dir = Left;
      else
        cl->dir -= 1;
    }
  ppo(NULL, cl);
}

int		turn_left(t_client *cl)
{
  t_setting	*setting;

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
      ((cl->stm->in_nsec) >= (7000000000 / setting->delay)))
    {
      cl->stm->in_use = -1;
      turn_client(cl, 0);
      broadcast_to_one_client("ok\n", cl);
      return (0);
    }
  return (1);
}

int		turn_right(t_client *cl)
{
  t_setting	*setting;

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
      ((cl->stm->in_nsec) >= (7000000000 / setting->delay)))
    {
      cl->stm->in_use = -1;
      turn_client(cl, 1);
      broadcast_to_one_client("ok\n", cl);
      return (0);
    }
  return (1);
}
