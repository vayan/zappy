/*
** direction_sound.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun 26 12:53:30 2012 yann vaillant
** Last update Thu Jun 28 19:21:13 2012 randy lyvet
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
#include "case_to_go.h"

int			get_were(int from, int to, int limit)
{
  int			a;
  int			b;
  int			from_sav;

  if (from == to)
    return (0);
  from_sav = from - 1;
  a = 0;
  while (++from_sav != to)
  {
    if (from_sav == limit)
      from_sav = 0;
    a++;
  }
  from_sav = from + 1;
  b = 0;
  while (--from_sav != to)
  {
    if (from_sav == 0)
      from_sav = limit;
    b++;
  }
  if (a > b)
    return (-1);
  else
    return (1);
}

int			case_to_go(int fx, int fy, t_client *receiver)
{
  int			x;
  int			y;

  x = fx - receiver->x;
  y = fy - receiver->y;
  if (receiver->dir == 0)
    return (go_up(x, y));
  if (receiver->dir == 1)
    return (go_right(x, y));
  if (receiver->dir == 2)
    return (go_bot(x, y));
  if (receiver->dir == 3)
    return (go_left(x, y));
  return (0);
}

int			get_direction(t_client *emeter, t_client *receiver)
{
  t_setting		*infos;
  int			height;
  int			width;
  int			goX;
  int			goY;

  infos = get_setting(NULL);
  height = infos->height_map;
  width = infos->width_map;
  goX = get_were(receiver->x, emeter->x, width);
  goY = get_were(receiver->y, emeter->y, height);
  if (goY == 0 && goX == 0)
    return (0);
  return (case_to_go(goX, goY, receiver));
}
