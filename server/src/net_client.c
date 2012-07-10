/*
** net_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:38:17 2012 yann vaillant
** Last update Tue Jul 10 11:51:46 2012 robin maitre
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

int		buffer_loop(char *cl_msg, t_client *tmp)
{
  char		*tmp_msg;

  while ((tmp_msg = decoupe_back(cl_msg)) != NULL)
    {
      cl_msg = cl_msg + strlen(tmp_msg) + 1;
      if (tmp_msg != NULL && tmp_msg[0] != 0
          && tmp_msg[0] != '\n' && strlen(tmp_msg) > 1)
        {
          add_msg_to_buffer(tmp, tmp_msg);
          printf("\033[1;%sm<--\tReceive message from %d : '%s'\033[0;0;00m\n",
		 DARK_RED, tmp->id, tmp_msg);
        }
      xfree(tmp_msg);
    }
  return (0);
}

int		process_msg(char *msg, t_client *tmp)
{
  char		*cl_msg;
  char		*save_to_free;

  cl_msg = clean_msg(msg);
  save_to_free = cl_msg;
  if (cl_msg != NULL && cl_msg[0] != 0 && cl_msg[0] != '\n'
      && strlen(cl_msg) > 1)
    {
      buffer_loop(cl_msg, tmp);
      xfree(save_to_free);
    }
  return (0);
}

void		get_data_from_client(t_client *all_client, fd_set *readfs)
{
  t_client	*tmp;
  char		msg[MAX_INPUT];
  int		ret;

  memset(msg, 0, MAX_INPUT);
  tmp = all_client;
  while (tmp)
    {
      if (FD_ISSET(tmp->fd, readfs))
        {
          if ((ret = recv(tmp->fd, msg, MAX_INPUT, MSG_DONTWAIT)) > 0)
            process_msg(msg, tmp);
          if (ret == 0)
            remove_client(tmp);
        }
      tmp = tmp->next;
    }
}

void		select_list(t_client *all_client, fd_set *readf)
{
  t_client	*tmp;

  tmp = all_client;
  FD_ZERO(readf);
  while (tmp)
    {
      FD_SET(tmp->fd, readf);
      tmp = tmp->next;
    }
}
