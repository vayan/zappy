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
#include "setting.h"
#include "map.h"
#include "client.h"

void  free_close_client()
{
  t_client  *all_client;
  t_client  *tmp;

  all_client = get_all_client(NULL);
  while (all_client)
  {
    tmp = all_client;
    xclose(all_client->fd);
    if (all_client->team != NULL)
      free(all_client->team);
    free_buff_msg(all_client->buff_msg);
    all_client = all_client->next;
    if (tmp != NULL)
      free(tmp);
  }
}

int  free_buff_msg(t_buffer_msg *buff_msg)
{
  t_buffer_msg *tmp;

  if (buff_msg == NULL)
    return (1);
  while (buff_msg)
  {
    tmp = buff_msg;
    if (buff_msg->msg != NULL)
      free(buff_msg->msg);
    buff_msg = buff_msg->next;
    if (tmp != NULL)
      free(tmp);
  }
  return (0);
}

int   free_client_map(t_pl_case *client)
{
 t_pl_case *tmp;

 if (client == NULL)
  return (0);
while (client)
{
  tmp = client;
  if (client->client != NULL)
    free(client->client);
  client = client->next;
  if (tmp != NULL)
    free (tmp);
}
free(client);
return (1);
}

int   free_map()
{
 t_map_case ***map;
 t_map_case *tmp;
 t_setting    *setting;
 int x;
 int y;

 y = 0;
 tmp = NULL;
 map = get_map(NULL);
 setting = get_setting(NULL);
 if (map != NULL && setting != NULL)
 {
   while (y < setting->height_map)
   {
    x = 0;
    while (x < setting->width_map)
    {
      tmp = MAP;
      if (MAP->rsrc != NULL)
        free (MAP->rsrc);
      free_client_map(MAP->client);
      x++;
      if (tmp != NULL)
        free(tmp);
    }
    if (map[y] != NULL)
      free(map[y]);
    y++;
  }
  free(map);
}
}

int   free_setting()
{
  t_setting *setting;
  int   i;

  i = 0;
  setting = get_setting(NULL);
  if (setting->name_teams != NULL)
  {
    while (setting->name_teams[i])
    {
      if (setting->name_teams[i] != NULL)
        free (setting->name_teams[i]);
      i++;
    }  
  }
  if (setting != NULL)
    free (setting);
  return (0);
}