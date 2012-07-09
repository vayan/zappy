/*
** ppo.c for zappy\ in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 15:36:19 2012 anatole carlier
** Last update Mon Jul  9 13:06:17 2012 vailla_y
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int		ppo_one(t_client *graphic, t_client *clients)
{
  char		*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "ppo %i %i %i %i\n", clients->id, clients->x, clients->y,
          clients->dir + 1);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}

void		ppo_broad(t_client *clients, t_client *graphic)
{
  char		*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "ppo %i %i %i %i\n", clients->id,
          clients->x, clients->y, clients->dir + 1);
  broadcast_to_one_client(str, graphic);
  xfree(str);
}

int		ppo(char **tab, t_client *client)
{
  t_client	*graphic;
  t_client	*clients;

  clients = get_all_client(NULL, 0);
  graphic = get_graphic(NULL, 0);
  if (graphic == NULL)
    return (0);
  if (tab == NULL)
    return (ppo_one(graphic, client));
  if (tab != NULL && tab[1] != NULL)
    {
      while (clients)
        {
          if (clients->id == atoi(tab[1]))
            {
              ppo_broad(clients, graphic);
              return (0);
            }
          clients = clients->next;
        }
    }
  sbp(NULL, client);
  return (0);
}
