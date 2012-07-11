/*
** utils_net_client.c for  in /home/haulot_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by alexandre haulotte
** Login   <haulot_a@epitech.net>
** 
** Started on  Tue Jul 10 11:20:50 2012 alexandre haulotte
** Last update Tue Jul 10 11:21:36 2012 alexandre haulotte
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

void		show_all_msg(t_client *cl)
{
  int		i;
  t_buffer_msg	*tmp;

  tmp = cl->buff_msg;
  printf("----------\n");
  while (tmp)
  {
    printf("%d(%d) : '%s' \n", cl->id, i, tmp->msg);
    tmp = tmp->next;
    i++;
  }
}

char	*decoupe_back(char *msg)
{
  int	i;
  int	j;
  char	*end;

  end = xmalloc(strlen(msg) * sizeof(char));
  i = 0;
  j = 0;
  while (msg[i])
  {
    if (msg[i] == '\n')
    {
      end[j] = 0;
      return (end);
    }
    end[j] = msg[i];
    i++;
    j++;
  }
  xfree(end);
  return (NULL);
}

int		get_higher_fd(t_client *all_client)
{
  t_client	*tmp;

  tmp = all_client;
  if (tmp == NULL)
    return (3);
  while (tmp->next)
    tmp = tmp->next;
  return (tmp->fd);
}
