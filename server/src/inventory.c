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

void  send_invent(t_client *cl)
{ 
  char *invent;
  char buff_int[16]; 
  
  invent = xmalloc(500 * sizeof(char*));
  memset(invent, 0, 500);
  strcat(invent, "{nourriture ");
  sprintf(buff_int, "%d", cl->rsrc[Nourriture]);
  strcat(invent, buff_int);
  strcat(invent, ",linemate ");
  sprintf(buff_int, "%d", cl->rsrc[Linemate]);
  strcat(invent, buff_int);
  strcat(invent, ",deraumere ");
  sprintf(buff_int, "%d", cl->rsrc[Deraumere]);
  strcat(invent, buff_int);
  strcat(invent, ",sibur ");
  sprintf(buff_int, "%d", cl->rsrc[Sibur]);
  strcat(invent, buff_int);
  strcat(invent, ",mendiane ");
  sprintf(buff_int, "%d", cl->rsrc[Mendiane]);
  strcat(invent, buff_int);
  strcat(invent, ",phiras ");
  sprintf(buff_int, "%d", cl->rsrc[Phiras]);
  strcat(invent, buff_int);
  strcat(invent, ",thystame ");
  sprintf(buff_int, "%d", cl->rsrc[Thystame]);
  strcat(invent, buff_int);
  strcat(invent, "}\n");

  broadcast_to_one_client(invent, cl);
  free(invent);
}

int Inventory(t_client *cl)
{
  t_setting *setting;

  if (cl->stm->in_use != -1 && cl->stm->in_use != TurnLeft)
    return (0);
  if (cl->stm->in_use == -1)
  { 
    cl->stm->in_use = Inventaire;
    start_timer(cl->stm);
    printf("Start timer Inventaire %ld\n", cl->stm->in_nsec);
    return (0);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (cl->stm->in_use == Inventaire &&
    ( (cl->stm->in_nsec) >= (1000000000/setting->delay)))
  {
    printf("send inv\n");
    cl->stm->in_use = -1;
    send_invent(cl);
    return (1);
  }
  return (0);
}