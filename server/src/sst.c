/*
** sst.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:16:11 2012 anatole carlier
** Last update Thu Jun 21 13:50:09 2012 robin maitre
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "command_fonc.h"
#include "network.h"
#include "setting.h"

int	sst(char **tab, t_client *client)
{
  char          *str;
  t_setting     *settings;

  tab = tab;
  str = xmalloc(sizeof(char) * 1024);
  settings = get_setting(NULL);
  sprintf(str, "sst %d\n", settings->delay);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
