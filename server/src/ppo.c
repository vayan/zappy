/*
** ppo.c for zappy\ in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:36:19 2012 anatole carlier
** Last update Tue Jun 19 09:25:13 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int     ppo(char **tab, t_client *client)
{
  char  *str;
  t_client *graphic;

  graphic = get_graphic(NULL);
  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pnw %i %i %i %i\n", client->id, client->x, client->y, 
	  client->dir);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
