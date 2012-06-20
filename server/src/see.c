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

void strcat_player(t_pl_case *tmp, char *msg)
{
  while (tmp)
  {
    strcat(msg," joueur ");
    tmp = tmp->next;
  }  
}

void  strcat_rsrc(Ressource *rsrc, char *msg)
{ 
  int i;

  i = 0;
  while (rsrc[i])
  {
    strcat(msg, " ");
    strcat(msg, Ressource_to_char(rsrc[i]));
    strcat(msg, " ");
    i++;
  }
}

char  *get_see_one_case(int x, int y)
{
  t_map_case ***map;
  map = get_map(NULL);
  char *msg;

  msg = xmalloc(500 * sizeof(*msg));
  memset(msg, 0, 500);
  if (MAP->client != NULL)
    strcat_player(MAP->client, msg);
  if (MAP->rsrc != NULL)
    strcat_rsrc(MAP->rsrc, msg);
  return(msg);
}

int do_see(t_client *cl)
{
  t_setting *setting;
  t_map_case ***map;
  char  *msg;

  msg = xmalloc (100000 * sizeof(*msg));
  memset(msg, 0, 100000);
  map = get_map(NULL);
  setting = get_setting(NULL);
  strcat(msg, "{");
  strcat(msg, get_see_one_case(cl->x, cl->y));
  strcat(msg, "}\n");
  broadcast_to_one_client(msg, cl);
  free(msg);
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