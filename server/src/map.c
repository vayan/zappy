/*
** map.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:10 2012 yann vaillant
** Last update Thu Jun  7 15:38:11 2012 yann vaillant
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

t_map_case    ***get_map(t_map_case ***_map)
{
  static t_map_case ***map = NULL;

  if (_map != NULL)
    map = _map;
  return (map);
}

void  aff_rsrc(Ressource* rsrc)
{
  int i;

  i = 0;
  while (i < 7)
  {
    printf("%d*%d | ", i, rsrc[i]);
    i++;
  }
}

void  aff_map()
{
  t_map_case ***map;
  t_setting    *setting;
  int x;
  int y;

  y = 0;
  map = get_map(NULL);
  setting = get_setting(NULL);
  while (y < setting->height_map)
  {
    x = 0;
    while (x < setting->width_map)
    {
      printf("[%d][%d] -> Ressource : ", x, y);
      aff_rsrc(MAP->rsrc);
      printf("\n");
      x++;
    }
    printf("\n");
    y++;
  }
}

void  rm_pl(int x, int y, t_client *pl)
{
  t_map_case ***map;

  map = get_map(NULL);
  if (MAP->client != NULL)
  {
    t_pl_case  *tmp;
    t_pl_case  *new;

    tmp = MAP->client;

    if ((tmp->client->id == pl->id) && (tmp->client->next == NULL))
      MAP->client = NULL;
    else
    {
      while (tmp->next || tmp->next->client->id != pl->id)
        tmp = tmp->next; 
      if (tmp->next->next == NULL)
        tmp->next = NULL;
      else
        tmp->next = tmp->next->next;
    }
  }
}

void  add_pl(int x, int y, t_client *pl)
{
  t_map_case ***map;

  map = get_map(NULL);
  if (MAP->client == NULL)
  {
    MAP->client = xmalloc(sizeof(t_pl_case));
    MAP->client->next = NULL;
    MAP->client->client = pl;
  } 
  else 
  {
   t_pl_case  *tmp;
   t_pl_case  *new;

   tmp = MAP->client;
   while (tmp)
    tmp = tmp->next; 
  new = xmalloc(sizeof(t_pl_case));
  new->next = NULL;
  new->client = pl;
  tmp->next = new;
}
}

Ressource *gen_rsrc()
{
  Ressource *rsrc;

  rsrc = xmalloc(7 * sizeof(int));
  rsrc[Nourriture] = random() % 3;
  rsrc[Linemate] = random() % 3;
  rsrc[Deraumere] = random() % 3;
  rsrc[Sibur] = random() % 3;
  rsrc[Mendiane] = random() % 3;
  rsrc[Phiras] = random() % 3;
  rsrc[Thystame] = random() % 3;

  return (rsrc);
}

void    generate_new_map()
{
 t_setting    *setting;
 t_map_case   ***new_map;
 t_map_case   *newcase;
 int          i;
 int          x;
 int          y;

 i = 0;
 y = 0;
 setting = get_setting(NULL);
 srandom(time(NULL) * geteuid());
 new_map = xmalloc ((setting->width_map + 1) * sizeof(t_map_case*));
 while (i < setting->width_map)
 {
  new_map[i] = xmalloc(setting->height_map * sizeof(t_map_case*));
  i++;
}
while (y < setting->height_map)
{
  x = 0;
  while (x < setting->width_map)
  {
    newcase = xmalloc(1 * sizeof(t_map_case));
    newcase->x = x;
    newcase->y = y;
    newcase->rsrc = gen_rsrc();
    newcase->client = NULL;
    new_map[x][y] = newcase;
    x++;
  }
  y++;
}
new_map[x] = NULL;
get_map(new_map);
}
