/*
** pex.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:10:02 2012 anatole carlier
** Last update Fri Jun 15 12:19:56 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int	pex(char **tab, t_client *client)
{
  char	*str;

  str = xmalloc(sizeof(char) * 16);
  sprintf("pex %s\n", tab[1]);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
