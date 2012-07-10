/*
** get_client_list.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:37:57 2012 yann vaillant
** Last update Tue Jul 10 11:40:31 2012 anatole carlier
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

t_client		*get_all_client(t_client *_all_client, int reset)
{
  static t_client	*client = NULL;

  if (_all_client != NULL)
    client = _all_client;
  if (reset == 1)
    client = NULL;
  return (client);
}
