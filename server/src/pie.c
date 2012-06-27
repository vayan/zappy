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

int     pie(t_client *client, int res)
{
  char  *str;
  t_client *graphic;

  graphic = get_graphic(NULL);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pie %d %d %d\n", client->x, client->y, res);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
