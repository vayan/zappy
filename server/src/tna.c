/*
** tna.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:33:47 2012 anatole carlier
** Last update Fri Jun 15 18:03:27 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xfunc.h"
#include "network.h"
#include "setting.h"

int		tna(char **tab, t_client *client)
{
  t_setting	*settings;
  char		*str;
  int		i;

  i = 0;
  tab = tab;
  settings = get_setting(NULL);
  while (settings->name_teams[i] != NULL)
    {
      str = xmalloc(sizeof(char) * 1024);
      sprintf(str, "tna %s\n", settings->name_teams[i++]);
      broadcast_to_one_client(str, client);
      free(str);
    }
  printf("fin\n");
  return (0);
}
