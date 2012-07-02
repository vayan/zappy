/*
** see.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 12:01:39 2012 yann vaillant
** Last update Mon Jul  2 12:01:56 2012 yann vaillant
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

char  *get_see_one_case(int x, int y)
{
  t_map_case ***map;
  map = get_map(NULL);
  char *msg;
  t_setting *setting;

  setting = get_setting(NULL);
  if (y >= setting->height_map)
    y = y - setting->height_map;
  if (y < 0)
    y = setting->height_map -(y * -1);
  if (x >= setting->width_map)
    x = x - setting->width_map;
  if (x < 0)
    x = setting->width_map - (x * - 1);
  msg = xmalloc(500 * sizeof(*msg));
  memset(msg, 0, 500);
  if (MAP->client != NULL)
    strcat_player(MAP->client, msg);
  if (MAP->rsrc != NULL)
    strcat_rsrc(MAP->rsrc, msg);
  return (msg);
}

void  scan_case(t_client *cl, char *msg)
{
  int lvl;
  int base;
  int i;
  int x;
  int y;

  x = 0;
  y = 0;
  base = 3;
  lvl = 1;
  strcat(msg, get_see_one_case(cl->x, cl->y));
  while (lvl <= cl->level)
    {
      i = 0;
      while (i < base)
        {
          strcat(msg, ",");
          set_x_see(cl, &x, lvl, i);
          set_y_see(cl, &y, lvl, i);
          strcat(msg, get_see_one_case(x, y));
          i++;
        }
      lvl++;
      base += 2;
    }
}

int do_see(t_client *cl)
{
  char  *msg;

  msg = xmalloc (100000 * sizeof(*msg));
  memset(msg, 0, 100000);
  strcat(msg, "{");
  scan_case(cl, msg);
  strcat(msg, "}\n");
  broadcast_to_one_client(clean_see(msg), cl);
  free(msg);
  return (0);
}

int Want_See(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != See)
    return (1);
  if (cl->stm->in_use == -1)
    {
      cl->stm->in_use = See;
      start_timer(cl->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == See &&
      ( (cl->stm->in_nsec) >= (7000000000/setting->delay)))
    {
      cl->stm->in_use = -1;
      do_see(cl);
      return (0);
    }
  return (1);
}
