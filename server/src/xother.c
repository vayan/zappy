/*
** xother.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:39:31 2012 yann vaillant
** Last update Thu Jun  7 15:39:32 2012 yann vaillant
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int	xlisten(int sockfd, int backlog)
{
  int	ret;

  if ((ret = listen(sockfd, backlog)) == -1)
    {
      perror("listen");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

ssize_t		xsend(int sockfd, const void *buf, size_t len, int flags)
{
  ssize_t	ret;

  if ((ret = send(sockfd, buf, len, flags)) == -1)
    {
      perror("send");
      exit(EXIT_FAILURE);
    }
  return (ret);
}