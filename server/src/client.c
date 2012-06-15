/*
** client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:37:52 2012 yann vaillant
** Last update Thu Jun  7 15:37:53 2012 yann vaillant
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
#include "option.h"

int   broadcast_to_one_client(char *msg, t_client *me)
{
  t_client  *tmp;
  char    *full_msg;

  full_msg = xmalloc(MAX_INPUT * sizeof(char*));
  memset(full_msg, 0, MAX_INPUT);
  strcat(full_msg, msg);
  tmp = me;
  xsend (tmp->fd, full_msg, strlen(full_msg), MSG_DONTWAIT);
  if (full_msg[strlen(full_msg) -1 ] == '\n')
    full_msg[strlen(full_msg) -1] = 0;
  printf("Send message to %d : '%s'\n", me->id, full_msg);
  free(full_msg);
  return (0);
}

int do_input_client(t_client *all_client)
{
  t_client  *tmp;
  t_option tab[26];

  init_tab(&tab);
  tmp = all_client;
  while (tmp)
  {
    if (tmp->buff_msg != NULL)
    {
        if (command_parser(&tab, tmp->buff_msg->msg) == 0)
          rm_top_msg_from_buffer(tmp);    
    }
    tmp = tmp->next;
  }
}