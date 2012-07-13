/*
** xfunc.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:39:23 2012 yann vaillant
** Last update Tue Jul 10 11:16:58 2012 alexandre haulotte
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "network.h"
#include "xfunc.h"

int	xclose(int d)
{
  if (close(d) == -1)
    return (-1);
  return (0);
}

void	*xmalloc(unsigned int size)
{
  void	*p;

  if ((p = malloc(size)) == 0)
      exit(EXIT_FAILURE);
  return (p);
}

sighandler_t	xsignal(int signum, sighandler_t handler)
{
  sighandler_t	ret;

  ret = signal(signum, handler);
  if (ret == SIG_ERR)
    perror("signal");
  return (ret);
}

int	xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  int	ret;

  if ((ret = bind(sockfd, addr, addrlen)) == -1)
    return (-1);
  return (ret);
}

void	xfree(void *ptr)
{
  if (ptr != NULL)
    {
      free(ptr);
      ptr = NULL;
    }
}

