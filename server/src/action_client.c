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

  new = xmalloc(sizeof(t_client));
  tmp = all_client;
  new->fd = fd;
  new->next = NULL;
  if (tmp == NULL)
    return (new);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (NULL);
}