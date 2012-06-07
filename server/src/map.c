#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include "map.h"
#include "setting.h"
#include "xfunc.h"

t_map_case    ***get_map(t_map_case ***_map)
{
  static t_map_case ***map = NULL;

  if (_map != NULL)
    map = _map;
  return (map);
}

void  aff_rsrc(t_ressource *rsrc)
{
  while (rsrc)
  {
    printf("%d*%d | ", rsrc->type, rsrc->quantity);
    rsrc = rsrc->next;
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

t_ressource *gen_list_rsrc()
{
  int i;
  t_ressource *save;
  t_ressource *rsrc;
  t_ressource *tmp;

  i = 1;
  rsrc = xmalloc (1 * sizeof(t_ressource));
  rsrc->type = 0;
  rsrc->quantity = random() % 3;
  rsrc->next = NULL;
  save = rsrc;
  while (i < 8)
  {
    tmp = xmalloc (1 * sizeof(t_ressource));
    tmp->type = i;
    tmp->quantity = random() % 3;
    tmp->next = NULL;
    rsrc->next = tmp;
    rsrc = rsrc->next;
    i++;
  }
  return (save);
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
    newcase->rsrc = gen_list_rsrc();
    newcase->client = NULL;
    new_map[x][y] = newcase;
    x++;
  }
  y++;
}
new_map[x] = NULL;
get_map(new_map);
}