/*
** net_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:17 2012 yann vaillant
** Last update Thu Jun  7 15:38:17 2012 yann vaillant
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

void    show_all_msg(t_client *cl)
{
  int i;
  t_buffer_msg *tmp;

  tmp = cl->buff_msg;
  printf("----------\n");
  while (tmp)
  {
    printf("%d(%d) : '%s' \n", cl->id, i, tmp->msg);
    tmp = tmp->next;
    i++;
  }
}

void    get_data_from_client(t_client *all_client, fd_set *readfs)
{
  t_client  *tmp;
  char    msg[MAX_INPUT];
  int   ret;

  memset(msg, 0, MAX_INPUT);
  tmp = all_client;
  while (tmp)
  {
    if (FD_ISSET(tmp->fd, readfs))
    {
      if ((ret = recv(tmp->fd, msg, MAX_INPUT, MSG_DONTWAIT)) != 0)
      {
        if (msg[0] != 0 && msg[0] != '\n')
        {
          add_msg_to_buffer(tmp, msg);
          printf("\033[1;%sm<--\tReceive message from %d : '%s'\033[0;0;00m\n", DARK_RED, tmp->id, msg);
        }
      }
      if (ret == 0)
        remove_client(tmp);
    }
    tmp = tmp->next;
  }
}

int   get_higher_fd(t_client *all_client)
{
  t_client  *tmp;

  tmp = all_client;
  if (tmp == NULL)
    return (3);
  while (tmp->next)
    tmp = tmp->next;
  return (tmp->fd);
}

void    select_list(t_client *all_client, fd_set *readf)
{
  t_client  *tmp;

  tmp = all_client;
  FD_ZERO(readf);
  while (tmp)
  {
    FD_SET(tmp->fd, readf);
    tmp = tmp->next;
  }
}
