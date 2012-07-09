/*
** msg_buffer_client.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:55:02 2012 yann vaillant
** Last update Mon Jul  9 12:55:24 2012 vailla_y
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

void		rm_top_msg_from_buffer(t_client *cl)
{
  t_buffer_msg	*tmp;

  tmp = cl->buff_msg;
  if (cl->buff_msg->next != NULL)
    cl->buff_msg = cl->buff_msg->next;
  else
    cl->buff_msg = NULL;
  xfree(tmp->msg);
  xfree(tmp);
}

void	new_msg_to_buffer(t_client *cl, char *msg)
{
  cl->buff_msg = xmalloc(sizeof(t_buffer_msg));
  cl->buff_msg->msg = strdup(msg);
  cl->buff_msg->next = NULL;
}

char*	clean_msg(char *msg)
{
  char	*clean;
  int	i;
  int	j;

  i = 0;
  j = 0;
  clean = xmalloc (strlen(msg) + 1 * sizeof(*clean));
  memset(clean, 0, strlen(msg) + 1);
  while (msg[i] != '\0')
    {
      if ((msg[i] >= 31 && msg[i] <= 126) || msg[i] == '\n')
        {
          clean[j] = msg[i];
          j++;
        }
      i++;
    }
  clean[j] = 0;
  return (clean);
}

int		add_msg_to_buffer(t_client *cl, char *msg)
{
  int		i;
  t_buffer_msg	*tmp;

  tmp = cl->buff_msg;
  if (msg[strlen(msg) - 1] == '\n')
    msg[strlen(msg) - 1] = '\0';
  i = 0;
  if (tmp == NULL)
    {
      new_msg_to_buffer(cl, msg);
      return (1);
    }
  while (tmp->next)
    {
      tmp = tmp->next;
      i++;
    }
  if (i < 9)
    {
      tmp->next = xmalloc(sizeof(t_buffer_msg));
      tmp->next->msg = strdup(msg);
      tmp->next->next = NULL;
    }
  return (0);
}
