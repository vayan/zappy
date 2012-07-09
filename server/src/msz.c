/*
** msz.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 14:36:31 2012 anatole carlier
** Last update Mon Jul  9 12:55:59 2012 vailla_y
*/

#include <stdio.h>
#include <stdlib.h>

#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int		msz(char **tab, t_client *client)
{
  char		 *str;
  t_setting	*settings;
  t_client	*graphic;

  client = client;
  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  tab = tab;
  str = xmalloc(sizeof(char) * 64);
  settings = get_setting(NULL);
  sprintf(str, "msz %i %i\n", settings->width_map, settings->height_map);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}
