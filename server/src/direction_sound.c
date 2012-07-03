/*
** direction_sound.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun 26 12:53:30 2012 yann vaillant
** Last update Tue Jul  3 13:33:09 2012 randy lyvet
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
      if (from_sav >= limit)
	from_sav = -1;
      a++;
    }
  from_sav = from + 1;
  b = 0;
  while (--from_sav != to)
    {
      if (from_sav <= 0)
	from_sav = limit + 1;
      b++;
    }
  if (a - b >= 0)
    return (-1);
  return (1);
}

int			case_to_go(int x, int y, t_client *receiver)
{
  if (receiver->dir == 0)
    return (go_up(x, y));
  else if (receiver->dir == 1)
    return (go_right(x, y));
  else if (receiver->dir == 2)
    return (go_bot(x, y));
  else if (receiver->dir == 3)
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
  int debug;

  printf("start direction\n");
  infos = get_setting(NULL);
  height = infos->height_map;
  width = infos->width_map;
  goX = get_were(receiver->x, emeter->x, width);
  goY = get_were(receiver->y, emeter->y, height);
  if (goY == 0 && goX == 0)
  {
    printf("fin direction 0\n");
    return (0);
  }
  debug = case_to_go(goX, goY, receiver);
  printf("fin direction\n");
  return (debug);
}
