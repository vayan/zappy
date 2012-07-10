/*
** free_spec.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:54:11 2012 yann vaillant
** Last update Tue Jul 10 11:39:59 2012 anatole carlier
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

int		free_buff_msg(t_buffer_msg *buff_msg)
{
  t_buffer_msg	*tmp;

  if (buff_msg == NULL)
    return (1);
  while (buff_msg)
    {
      tmp = buff_msg;
      xfree(buff_msg->msg);
      buff_msg = buff_msg->next;
      xfree(tmp);
    }
  return (0);
}

int		free_client_map(t_pl_case *client)
{
  t_pl_case	*tmp;

  if (client == NULL)
    return (0);
  while (client)
    {
      tmp = client;
      xfree(client->client);
      client = client->next;
      xfree (tmp);
    }
  xfree(client);
  return (1);
}
