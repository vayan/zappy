/*
** pnw.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:34:51 2012 anatole carlier
** Last update Fri Jun 15 12:04:31 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int	pnw(char **tab, t_client *client)
{
  char	*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pnw %s %s %s %s %s\n", tab[1], tab[2], tab[3], tab[4], tab[5]);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
