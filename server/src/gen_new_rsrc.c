/*
** gen_new_rsrc.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:54:30 2012 yann vaillant
** Last update Mon Jul  2 11:54:34 2012 yann vaillant
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include "map.h"
#include "setting.h"
#include "xfunc.h"
#include "client.h"
#include "network.h"
#include "command_fonc.h"

int  incr_rsrc(Ressource *rsrc, int food, int other)
{
  int change;

  change = 0;
  if (rsrc[Nourriture] == 0)
  {
    change = 1;
    rsrc[Nourriture] += random() % food;
  }
  if ((random() % 8) == 5)
  {
    if (rsrc[(random() % 7) + 1] == 0)
    {
      change = 1;
      rsrc[(random() % 7) + 1] += random() % other;
    }
  }
  return (change);
}

void  gen_new_rsrc()
{
  int          x;
  int          y;
  t_map_case   ***map;
  t_setting  *setting;

  setting = get_setting(NULL);
  map = get_map(NULL);
  y = 0;
  while (y < setting->height_map)
  {
    x = 0;
    while (x < setting->width_map)
    {
      if (incr_rsrc(MAP->rsrc, 2, 2) == 1)
        bct_int(x, y);
      x++;
    }
    y++;
  }
}


