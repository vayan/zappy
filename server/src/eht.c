/*
** eht.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:14:46 2012 anatole carlier
** Last update Thu Jun 21 14:59:02 2012 robin maitre
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int	eht(int id, t_client *client)
{
  char *str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "eht %d\n", id);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
