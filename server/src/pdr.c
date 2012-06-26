/*
** pdr.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:12:37 2012 anatole carlier
** Last update Tue Jun 26 10:29:39 2012 robin maitre
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int	pdr(char **tab, t_client *client)
{
  char	*str;

  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  sprintf("pdr %i %i\n", client->id, client->rsrc);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
