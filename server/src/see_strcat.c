/*
** see_strcat.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:55:49 2012 yann vaillant
** Last update Tue Jul 10 11:29:58 2012 alexandre haulotte
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

char	*clean_see(char *msg)
{
  int	i;
  int	j;
  char	*msg_clean;

  msg_clean = xmalloc (100000 * sizeof(*msg_clean));
  memset(msg_clean, 0, 100000);
  i = 0;
  j = 0;
  while (msg[i])
    {
      if (i > 0 && msg[i - 1] == '{' && msg[i] == ' ')
        i++;
      if (msg[i] == ' ' && msg[i + 1] == ',')
        i++;
      if (msg[i] == ' ' && msg[i + 1] == ' ')
        i++;
      msg_clean[j] = msg[i];
      i++;
      j++;
    }
  xfree(msg);
  return (msg_clean);
}

void	strcat_player(t_pl_case *tmp, char *msg)
{
  while (tmp)
    {
      strcat(msg, " joueur ");
      tmp = tmp->next;
    }
}

void	strcat_rsrc(Ressource *rsrc, char *msg)
{
  int	i;
  int	j;
  char	*rc;

  i = 0;
  while (i <= Thystame)
    {
      j = 0;
      while (j < (int)rsrc[i])
        {
          strcat(msg, " ");
          rc = Ressource_to_char(i);
          strcat(msg, rc);
          strcat(msg, " ");
          xfree (rc);
          j++;
        }
      i++;
    }
}
