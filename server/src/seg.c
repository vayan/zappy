/*
** seg.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:17:01 2012 anatole carlier
** Last update Tue Jun 26 10:44:55 2012 robin maitre
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int	seg(char **tab, t_client *client)
{
  char	*str;
   t_client *graphic;

  graphic = get_graphic(NULL);
  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "seg %s\n", client->teams);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
