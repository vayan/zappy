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
          gen_rsrc(MAP->rsrc, 3, 2);
          x++;
        }
      y++;
    }
}

void  incr_rsrc(Ressource *rsrc, int food, int other)
{
  rsrc[Nourriture] += random() % food;
  rsrc[Linemate] += random() % other;
  rsrc[Deraumere] += random() % other;
  rsrc[Sibur] += random() % other;
  rsrc[Mendiane] += random() % other;
  rsrc[Phiras] += random() % other;
  rsrc[Thystame] += random() % other;
}
