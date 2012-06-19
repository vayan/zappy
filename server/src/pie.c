/*
** pie.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:11:28 2012 anatole carlier
** Last update Tue Jun 19 10:00:30 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int     pie(char **tab, t_client *client)
{
  char  *str;

  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pie %i %i %i %s\n", client->id, client->x, client->y, tab[1]);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
