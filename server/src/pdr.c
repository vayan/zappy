/*
** pdr.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Tue Jun 12 11:12:37 2012 anatole carlier
** Last update Tue Jul 10 11:37:41 2012 alexandre haulotte
*/

#include <stdio.h>
#include <stdlib.h>

#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int		pdr(Ressource rsrc, t_client *client)
{
  char		*str;
  t_client	*graphic;

  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pdr %d %d\n", client->id, rsrc);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}
