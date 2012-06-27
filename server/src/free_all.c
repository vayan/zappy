/*
** free_all.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun 26 12:53:55 2012 yann vaillant
** Last update Tue Jun 26 12:53:56 2012 yann vaillant
*/

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
    //FREE TEAM
    free_buff_msg(all_client->buff_msg);
    all_client = all_client->next;
    if (tmp != NULL)
      free(tmp);
  }
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
return (0);
}

int   free_setting()
{
  t_setting *setting;

  setting = get_setting(NULL);
  //FREE ALL STRUCT TEAM
  if (setting != NULL)
    free (setting);
  return (0);
}
