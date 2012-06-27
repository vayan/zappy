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
  //printf("Before correction x=%d y=%d\n", x, y);
  if (y >= setting->height_map)
    y = y - setting->height_map;
  if (y < 0)
    y = setting->height_map -(y * -1);
  if (x >= setting->width_map)
    x = x - setting->width_map;
  if (x < 0)
    x = setting->width_map - (x * - 1);
  //printf("After  correction x=%d y=%d\n", x, y);
  msg = xmalloc(500 * sizeof(*msg));
  memset(msg, 0, 500);
  if (MAP->client != NULL)
    strcat_player(MAP->client, msg);
  if (MAP->rsrc != NULL)
    strcat_rsrc(MAP->rsrc, msg);
  return(msg);
}

void set_y_see(t_client *cl, int *y, int lvl, int i)
{
  if (cl->dir == Down)
    *y = cl->y + lvl;
  if (cl->dir == Up)
    *y = cl->y - lvl;
  if (cl->dir == Right)
    *y = (cl->y - lvl) + i;
  if (cl->dir == Left)
   *y = (cl->y + lvl) - i;

}
void  set_x_see(t_client *cl, int *x, int lvl, int i)
{
  if (cl->dir == Down)
    *x = (cl->x + lvl) - i;
  if (cl->dir == Up)
    *x = (cl->x - lvl) + i;
  if (cl->dir == Right)
    *x = cl->x + lvl;
  if (cl->dir == Left)
    *x = cl->x - lvl;
}

void  scan_case(t_client *cl, char *msg)
{
  int lvl;
  int base;
  int i;
  int j; //debug
  int x;
  int y;

  x = 0;
  y = 0;
  j = 1;
  base = 3;
  lvl = 1;
  strcat(msg, get_see_one_case(cl->x, cl->y));
  //printf("sur la case %d (%d - %d)'%s'\n\n\n", 0 , cl->x, cl->y , get_see_one_case(cl->x, cl->y));
  while (lvl <= cl->level)
  {
    i = 0;
    while (i < base)
    {
      strcat(msg, ",");
      set_x_see(cl, &x, lvl, i);
      set_y_see(cl, &y, lvl, i);
      strcat(msg, get_see_one_case(x, y));
      //printf("sur la case %d (%d - %d)'%s'\n\n\n", j , x, y, get_see_one_case(x, y));
      j++;
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
    aff_map();
    aff_pl_test();
    do_see(cl);
    return (0);
  }
  return (1);
}
