/*
** move_player.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun 14 15:40:18 2012 yann vaillant
** Last update Mon Jul  9 12:54:41 2012 vailla_y
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

void		MoveClient(t_client *cl)
{
  t_setting	*setting;

  rm_pl(cl->x, cl->y, cl);
  setting = get_setting(NULL);
  correction_move_down(cl, setting);
  correction_move_up(cl, setting);
  correction_move_right(cl, setting);
  correction_move_left(cl, setting);
  add_pl(cl->x, cl->y, cl);
}

int		MoveFront(t_client *cl)
{
  t_setting	*setting;

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
      ppo(NULL, cl);
      return (0);
    }
  return (1);
}
