/*
** bct.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 14:54:41 2012 anatole carlier
** Last update Mon Jul  9 12:34:38 2012 vailla_y
*/

#include <stdio.h>
#include <xfunc.h>
#include <setting.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "map.h"
#include "client.h"

int		bct_int(int x, int y)
{
  char		*str;
  t_client	*graphic;

  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  str = map_contents(str, x, y);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}

int		bct_one(t_client *graphic, t_client *client)
{
  char		*str;

  str = xmalloc(sizeof(char) * 1024);
  str = map_contents(str, client->x, client->y);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}

int		bct(char **tab, t_client *client)
{
  char		*str;
  int		x;
  int		y;
  t_client	*graphic;

  x = -1;
  y = -1;
  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  if (tab == NULL)
    return (bct_one(graphic, client));
  str = xmalloc(sizeof(char) * 1024);
  if (tab[1] != NULL && tab[2] != NULL)
    {
      x = atoi(tab[1]);
      y = atoi(tab[2]);
    }
  if (x < 0 || y < 0)
    return (sbp(NULL, client));
  str = map_contents(str, x, y);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}
