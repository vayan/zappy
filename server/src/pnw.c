/*
** pnw.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:34:51 2012 anatole carlier
** Last update Mon Jun 18 18:29:15 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int	pnw(char **tab, t_client *client)
{
  char	*str;
  t_client *graphic;

  tab = tab;
  graphic = get_graphic(NULL);
  if (graphic == NULL || client->is_graphic == 1 || client == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pnw %i %i %i %i %i %s\n", client->id, client->x, client->y, 
	  client->dir + 1, client->level, client->teams->name);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
