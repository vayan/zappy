/*
** connect_nbr.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:53:17 2012 yann vaillant
** Last update Mon Jul  9 12:39:24 2012 vailla_y
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
#include "map.h"
#include "setting.h"
#include "client.h"

int	do_connect_nbr(t_client *cl)
{
  char	*buff_int;

  buff_int = xmalloc(50 * sizeof(char*));
  sprintf(buff_int, "%d\n", cl->teams->left);
  broadcast_to_one_client(buff_int, cl);
  xfree(buff_int);
  return (0);
}
