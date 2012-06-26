/*
** bct.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 14:54:41 2012 anatole carlier
** Last update Fri Jun 15 16:43:46 2012 anatole carlier
*/

#include <stdio.h>
#include <xfunc.h>
#include <setting.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "map.h"
#include "client.h"

int		bct(char **tab, t_client *client)
{
  char		*str;
  int		x;
  int		y;
  t_client *graphic;

  graphic = get_graphic(NULL);
  str = xmalloc(sizeof(char) * 1024);
  if (tab[1] != NULL && tab[2] != NULL)
  {
    x = atoi(tab[1]);
    y = atoi(tab[2]);
  }
  else
  {
    sbp(NULL, client);
    return (0);
  }
  str = map_contents(str, x, y);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
