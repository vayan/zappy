/*
** pdi.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:13:21 2012 anatole carlier
** Last update Thu Jun 21 15:24:58 2012 robin maitre
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int	pdi(char **tab, t_client *client)
{
  char	*str;
   t_client *graphic;

  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pdi %i\n", client->id);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
