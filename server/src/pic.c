/*
** pic.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Tue Jun 12 11:11:50 2012 anatole carlier
** Last update Mon Jul  2 12:04:42 2012 yann vaillant
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_fonc.h"
#include "merge.h"
#include "network.h"
#include "xfunc.h"
#include "map.h"

int     pic(t_client *client, t_map_case *cas)
{
  char  *str;
  char  *tmp;
  t_client *graphic;
  t_pl_case *tmp_c;

  tmp_c = cas->client;
  graphic = get_graphic(NULL);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pic %d %d %d ", client->x, client->y, client->level + 1);
  while (tmp_c)
    {
      tmp = xmalloc(50 * sizeof(char));
      sprintf(tmp, "%d ", tmp_c->client->id);
      tmp_c = tmp_c->next;
      strcat(str, tmp);
      free(tmp);
    }
  strcat(str, "\n");
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
