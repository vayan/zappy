/*
** pin.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:37:50 2012 anatole carlier
** Last update Fri Jun 15 12:08:30 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int	pin(char **tab, t_client *client)
{
  char	*str;

  str = xmalloc(sizeof(char) * 100);
  sprintf("pin %s %s %s %s %s %s %s %s %s %s", tab[1], tab[2], tab[3], tab[4], 
	  tab[5], tab[6], tab[7], tab[8], tab[9], tab[10]);
  broadcast_to_one_client(str, client);
  free(str);
  return (0);
}
