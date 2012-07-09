/*
** correction_move.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:54:19 2012 yann vaillant
** Last update Mon Jul  9 12:40:24 2012 vailla_y
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

void	correction_move_down(t_client *cl, t_setting *setting)
{
  if (cl->dir == Down)
    {
      cl->y += 1;
      if (cl->y >= setting->height_map)
        cl->y = 0;
    }
}

void	correction_move_up(t_client *cl, t_setting *setting)
{
  if (cl->dir == Up)
    {
      cl->y -= 1;
      if (cl->y < 0)
        cl->y = setting->height_map - 1;
    }
}

void	correction_move_right(t_client *cl, t_setting *setting)
{
  if (cl->dir == Right)
    {
      cl->x += 1;
      if (cl->x >= setting->width_map)
        cl->x = 0;
    }
}

void	correction_move_left(t_client *cl, t_setting *setting)
{
  if (cl->dir == Left)
    {
      cl->x -= 1;
      if (cl->x < 0)
        cl->x = setting->width_map - 1;
    }
}
