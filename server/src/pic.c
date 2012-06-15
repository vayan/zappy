/*
** pic.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Tue Jun 12 11:11:50 2012 anatole carlier
** Last update Fri Jun 15 14:01:45 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_fonc.h"
#include "merge.h"
#include "network.h"
#include "xfunc.h"

int	pic(char **tab, t_client *client)
{
  char	*str;
  char	*players;
  int	y;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pic");
  players = xmalloc(sizeof(char) * 16);
  sprintf(players, " %s", tab[1]);
  str = my_merge(str, players);
  y = 2;
  while (tab[y] != NULL)
    {
      memset(players, 16, 0);
      sprintf(players, " %s", tab[y++]);
      str = my_merge(str, players);
    }
  free(players);
  str = my_merge(str, "\n");
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}

char            *my_merge(char *path, char *name)
{
  char          *new;
  int           i;
  int           a;

  a = -1;
  i = -1;
  new = xmalloc(sizeof(path) + sizeof(name) + 2);
  while (path[++i] != 0)
    new[i] = path[i];
  i = i - 1;
  while (name[++a] != 0)
    new[++i] = name[a];
  new[++i] = 0;
  return (new);
}
