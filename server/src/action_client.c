/*
** action_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:37:45 2012 yann vaillant
** Last update Thu Jun  7 15:37:46 2012 yann vaillant
*/

#define _XOPEN_SOURCE
#define _SVID_SOURCE
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

int   remove_client(t_client *to_remove)
{
  t_client  *tmp;

  xclose(to_remove->fd);
  tmp = get_all_client(NULL);
  if (tmp->fd == to_remove->fd)
  {
    tmp->fd = -1;
    return (0);
  }
  while (tmp)
  {
    if (tmp->next != NULL)
    {
      if (tmp->next->fd == to_remove->fd)
        tmp->next = tmp->next->next;
    }
    tmp = tmp->next;
  }
  return (1);
}

t_client  *add_client(t_client *all_client, int fd)
{
  t_client  *tmp;
  t_client  *new;
  static int  id = 0;

  new = xmalloc(sizeof(t_client));
  tmp = all_client;
  new->fd = fd;
  new->id = id++;
  new->next = NULL;
  if (tmp == NULL)
    return (new);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (NULL);
}
