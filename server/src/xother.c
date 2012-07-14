/*
** xother.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:39:31 2012 yann vaillant
** Last update Sat Jul 14 16:56:57 2012 robin maitre
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "setting.h"

int		xlisten(int sockfd, int backlog)
{
  int		ret;

  if ((ret = listen(sockfd, backlog)) == -1)
    perror("listen");
  return (ret);
}

ssize_t		xsend(int sockfd, const void *buf, size_t len, int flags)
{
  ssize_t	 ret;

  ret = send(sockfd, buf, len, flags);
  return (ret);
}

void		xprintf_cc(const char *format, char *on, char *foo)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf(format, on, foo);
}

void		xprintf_i(const char *format, int on)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf(format, on);
}

