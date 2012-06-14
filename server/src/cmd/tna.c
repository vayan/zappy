/*
** tna.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:33:47 2012 anatole carlier
** Last update Thu Jun 14 17:00:06 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xfunc.h"
#include "network.h"

int	tna(char **tab, t_client *client)
{
  char	*str;
  int	y;

  y = 0;
  while (tab[1+y*2])
    {
      y++;
      str = xmalloc(sizeof(char) * 1024);
      sprintf(str, "tna %s\n", tab[1+y]);
      broadcast_to_one_client(str, client);
      memset(str, 0, 1024);
    }
  free(str);
  return (0);
}
