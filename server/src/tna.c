/*
** tna.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 15:33:47 2012 anatole carlier
** Last update Mon Jul  9 13:11:43 2012 vailla_y
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xfunc.h"
#include "network.h"
#include "setting.h"

int	       tna(char **tab, t_client *client)
{
  t_setting	*settings;
  char		*str;
  t_team	*tmp;
  t_client	*graphic;

  client = client;
  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  tab = tab;
  settings = get_setting(NULL);
  tmp = settings->all_team;
  while (tmp)
    {
      str = xmalloc(sizeof(char) * 1024);
      sprintf(str, "tna %s\n", tmp->name);
      broadcast_to_one_client(str, graphic);
      xfree(str);
      tmp = tmp->next;
    }
  return (0);
}
