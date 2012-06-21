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

int   check_death_all_player()
{
  t_client *client;

  client = get_all_client(NULL);
  while (client)
  {
    start_dying(client);
    client = client->next;
  }
}

int   kill_player(t_client *cl)
{
  broadcast_to_one_client("mort\n", cl);
  remove_client(cl);
}

int start_dying(t_client *cl)
{
  t_setting *setting;

  if (cl->is_graphic == 1 || cl->death->in_use == 2)
    return (1);
  if (cl->death->in_use == -1)
  { 
    cl->death->in_use = 1;
    start_timer(cl->death);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->death);
  set_elapse_sec(cl->death);
  if (((cl->death->in_nsec) >= ((cl->rsrc[Nourriture] * 126000000000)/setting->delay)))
  {
    cl->death->in_use = -1;
    kill_player(cl);
    return (0);
  }
  return (1);
}