/*
** gen_map.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:54:27 2012 yann vaillant
** Last update Mon Jul  2 12:10:21 2012 yann vaillant
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

Ressource *gen_rsrc(int food, int other)
{
  Ressource *rsrc;

  rsrc = xmalloc(7 * sizeof(int));
  rsrc[Nourriture] = random() % food;
  rsrc[Linemate] = random() % other;
  rsrc[Deraumere] = random() % other;
  rsrc[Sibur] = random() % other;
  rsrc[Mendiane] = random() % other;
  rsrc[Phiras] = random() % other;
  rsrc[Thystame] = random() % other;
  return (rsrc);
}

void  init_map(t_map_case ***new_map, t_setting *setting)
{
  int          x;
  int          y;
  t_map_case   *newcase;

  y = 0;
  while (y < setting->height_map)
    {
      x = 0;
      while (x < setting->width_map)
        {
          newcase = xmalloc(1 * sizeof(t_map_case));
          newcase->x = x;
          newcase->y = y;
          newcase->rsrc = gen_rsrc(2, 2);
          newcase->client = NULL;
          new_map[x][y] = newcase;
          x++;
        }
      y++;
    }
  new_map[x] = NULL;
}

void    generate_new_map()
{
  t_setting    *setting;
  t_map_case   ***new_map;
  int i;

  i = 0;
  printf("\033[1;%sm--Generating new map...\033[0;0;00m\n", COLOR_BLU);
  setting = get_setting(NULL);
  srandom(time(NULL) * geteuid());
  new_map = xmalloc ((setting->width_map + 1) * sizeof(t_map_case*));
  while (i < setting->width_map)
    {
      new_map[i] = xmalloc(setting->height_map * sizeof(t_map_case*));
      i++;
    }
  init_map(new_map, setting);
  get_map(new_map);
  printf("\033[1;%sm--Done\033[0;0;00m\n", COLOR_BLU);
}
