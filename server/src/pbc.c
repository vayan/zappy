/*
** pbc.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Tue Jun 12 11:11:09 2012 anatole carlier
** Last update Tue Jul 10 11:38:03 2012 alexandre haulotte
*/

#include <stdio.h>
#include <stdlib.h>

#include "client.h"
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int		pbc(char *msg, t_client *client)
{
  char		*str;
  t_client	*graphic;

  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pbc %d %s\n", client->id, msg);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}
