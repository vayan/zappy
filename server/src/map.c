/*
** map.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:38:10 2012 yann vaillant
** Last update Tue Jul 10 11:32:21 2012 robin maitre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include "map.h"
#include "setting.h"
#include "xfunc.h"
#include "client.h"
#include "network.h"

t_map_case              ***get_map(t_map_case ***_map)
{
  static t_map_case     ***map = NULL;

  if (_map != NULL)
    map = _map;
  return (map);
}

void			rm_pl(int x, int y, t_client *pl)
{
  t_map_case		***map;
  t_pl_case		*tmp;
  t_pl_case   *to_free;

  map = get_map(NULL);
  to_free = NULL;
  if (MAP->client != NULL)
  {
    tmp = MAP->client;
    if (tmp->next == NULL && tmp->client == pl)
    {
      xfree(MAP->client);
      MAP->client = NULL;
    }
    else if (tmp->client == pl)
    {
      to_free = MAP->client;
      MAP->client = tmp->next;
    }
    else
    {
      while (tmp)
      {
        if (tmp->next != NULL && tmp->next->client == pl)
        {
          to_free = tmp->next;
          tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
      }
    }
  }
  xfree(to_free);
}

void			add_pl(int x, int y, t_client *pl)
{
  t_map_case		***map;
  t_pl_case		*tmp;
  t_pl_case		*new;

  map = get_map(NULL);
  if (MAP->client == NULL)
  {
    MAP->client = xmalloc(sizeof(t_pl_case));
    MAP->client->next = NULL;
    MAP->client->client = pl;
  }
  else
  {
    tmp = MAP->client;
    while (tmp->next)
      tmp = tmp->next;
    new = xmalloc(sizeof(t_pl_case));
    new->next = NULL;
    new->client = pl;
    tmp->next = new;
  }
}
