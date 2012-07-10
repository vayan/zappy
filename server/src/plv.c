/*
** plv.c for zappy in /home/carlie_a//zappy-2015-2014s-haulot_a/server/src
**
** Made by anatole carlier
** Login   <carlie_a@epitech.net>
**
** Started on  Thu Jun  7 15:37:08 2012 anatole carlier
** Last update Tue Jul 10 11:34:18 2012 alexandre haulotte
*/

#include <stdio.h>
#include <stdlib.h>

#include "command_fonc.h"
#include "network.h"
#include "xfunc.h"

int	plv_one(t_client *client, t_client *graphic)
{
  char	*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "plv %i %i\n", client->id, client->level);
  broadcast_to_one_client(str, graphic);
  xfree(str);
  return (0);
}

void	plv_broad(t_client *client, t_client *graphic)
{
  char	*str;

  str = xmalloc(sizeof(char) * 1024);
  sprintf(str, "plv %i %i\n", client->id, client->level);
  broadcast_to_one_client(str, graphic);
  xfree(str);
}

int		plv(char **tab, t_client *client)
{
  t_client	*graphic;
  t_client	*clients;

  clients = get_all_client(NULL, 0);
  graphic = get_graphic(NULL, 0);
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
              plv_broad(clients, graphic);
              return (0);
            }
          clients = clients->next;
        }
    }
  sbp(NULL, client);
  return (0);
}
