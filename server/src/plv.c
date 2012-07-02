/*
** plv.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 15:37:08 2012 anatole carlier
** Last update Mon Jul  2 12:03:15 2012 yann vaillant
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int plv_one(t_client *client, t_client *graphic)
{
  char  *str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "pnw %i %i\n", client->id, client->level);
  broadcast_to_one_client(str, graphic);
  free(str);
  return (0);
}

int     plv(char **tab, t_client *client)
{
  char  *str;
  t_client *graphic;
  t_client      *clients;

  clients = get_all_client(NULL);
  graphic = get_graphic(NULL);
  if (graphic == NULL)
    return (0);
  if (tab == NULL)
    return (plv_one(client, graphic));
  if (tab[1] != NULL)
    {
      while (clients)
        {
          if (clients->id == atoi(tab[1]))
            {
              str = xmalloc(sizeof(char) * 1024);
              sprintf(str, "pnw %i %i\n", client->id, client->level);
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
