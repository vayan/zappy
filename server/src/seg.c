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

int	seg(t_team *tm)
{
  char	*str;
   t_client *graphic;

  graphic = get_graphic(NULL);
  if (graphic == NULL)
    return (0);
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "seg %s\n", tm->name);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}
