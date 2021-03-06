/*
** free_all.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:53:55 2012 yann vaillant
** Last update Sun Jul 15 21:21:13 2012 robin maitre
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

void		free_close_client()
{
  t_client	*all_client;
  t_client	*tmp;

  all_client = get_all_client(NULL, 0);
  while (all_client)
    {
      tmp = all_client;
      remove_client(tmp);
      all_client = all_client->next;
    }
}

int		free_map()
{
  t_map_case	***map;
  t_setting	*setting;
  int		y;

  y = 0;
  map = get_map(NULL);
  setting = get_setting(NULL);
  while (y < setting->height_map)
    {
      xfree(map[y]);
      y++;
    }
  xfree(map);
  return (0);
}

int		free_setting()
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL)
    xfree(setting);
  return (0);
}
