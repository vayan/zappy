/*
** pfk.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:12:18 2012 anatole carlier
** Last update Wed Jun 20 11:08:48 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int     pfk(char **tab, t_client *client)
{
  char  *str;

  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pfk %i %i\n", client->id);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
