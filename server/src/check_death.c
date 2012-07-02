/*
** check_death.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:53:02 2012 yann vaillant
** Last update Mon Jul  2 12:11:57 2012 yann vaillant
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
#include "map.h"
#include "setting.h"
#include "client.h"
#include "command_fonc.h"

int   kill_player(t_client *cl)
{
  if (cl->rsrc[Nourriture] <= 0)
    {
      broadcast_to_one_client("mort\n", cl);
      pdi(NULL, cl);
      remove_client(cl);
    }
  return (0);
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
  if (((cl->death->in_nsec) >= ((126000000000)/setting->delay)))
    {
      cl->rsrc[Nourriture] -= 1;
      cl->death->in_use = -1;
      kill_player(cl);
      return (0);
    }
  return (1);
}

int   check_death_all_player()
{
  t_client *client;

  client = get_all_client(NULL);
  while (client)
    {
      start_dying(client);
      client = client->next;
    }
  return (0);
}
