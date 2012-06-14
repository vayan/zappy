/*
** mct.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:27:10 2012 anatole carlier
** Last update Thu Jun 14 17:04:16 2012 anatole carlier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xfunc.h"
#include "network.h"
#include "setting.h" 
#include "command_fonc.h"

int	mct(char **tab, t_client *client)
{
  char	*str;
  int	y;

  while (tab[y*10] != NULL)
    { 
      str = xmalloc(sizeof(char) * 1024);
      sprintf("bct %s %s %s %s %s %s %s %s %s\n", tab[1+y*10], tab[2+y*10], 
	      tab[3+y*10], tab[4+y*10], tab[5+y*10], tab[6+y*10], tab[6+y*10],
	      tab[8+y*10],  tab[9+y*10]);
      broadcast_to_one_client(str, client);
      memset(str, 0, 1024);
      y++;
    }
  free(str);
  return (0);
}
