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

void    aff_pl_test()
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
      if (MAP->client != NULL)
      {
        printf("*");
      }
      else
        printf(".");
      x++;
    }
    printf("\n");
    y++;
  }
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

void  aff_player(t_pl_case* pl)
{
  t_pl_case *tmp;

  tmp = pl;
  if (pl == NULL)
    printf(" Aucun Player ");
  else
  {
    while (tmp)
    {
      printf(" Player %d |", tmp->client->id);
      tmp = tmp->next;
    }
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
      aff_player(MAP->client);
      printf("\n");
      x++;
    }
    printf("\n");
    y++;
  }
}