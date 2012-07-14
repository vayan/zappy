/*
** pie.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Tue Jun 12 11:11:28 2012 anatole carlier
** Last update Sat Jul 14 11:34:57 2012 yann vaillant
*/

#include <stdio.h>
#include <stdlib.h>

#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int		pie(t_client *client, int res)
{
  char		*str;
  t_client	*graphic;

  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pie %d %d %d\n", client->x, client->y, res);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}
