/*
** pbc.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:11:09 2012 anatole carlier
** Last update Tue Jun 19 09:57:49 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int	pbc(char **tab, t_client *client)
{
  char	*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf("pbc %i %s\n", client->id, tab[2]);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
