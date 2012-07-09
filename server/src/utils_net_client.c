/*
** utils_net_client.c for  in /home/vailla_y/Projet/Tek2/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by vailla_y
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  9 12:27:29 2012 vailla_y
** Last update Mon Jul  9 13:13:17 2012 vailla_y
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

  end = xmalloc (strlen(msg) * sizeof(char));
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
