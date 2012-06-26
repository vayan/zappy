/*
** ppo.c for zappy\ in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
** 
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
** 
** Started on  Thu Jun  7 15:36:19 2012 anatole carlier
** Last update Tue Jun 26 12:40:07 2012 robin maitre
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int		ppo(char **tab, t_client *client)
{
  char		*str;
  t_client	*graphic;
  t_client	*clients;

  clients = get_all_client(NULL);
  graphic = get_graphic(NULL);
  if (tab[1] != NULL)
    {
      while (clients)
	{
	  if (clients->id == atoi(tab[1]))
	    {
	      str = xmalloc(sizeof(char) * 1024);
	      sprintf(str, "pnw %i %i %i %i\n", clients->id, clients->x, clients->y, 
		      clients->dir);
	      broadcast_to_one_client(str, graphic);
	      free(str);
	      return (0);
	    }
	  clients = clients->next;
	}  
    }
  sbp(NULL, client);
  return (0);
}
