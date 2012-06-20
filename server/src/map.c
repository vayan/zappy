/*
** map.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:10 2012 yann vaillant
** Last update Thu Jun  7 15:38:11 2012 yann vaillant
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

t_map_case    ***get_map(t_map_case ***_map)
{
  static t_map_case ***map = NULL;

  if (_map != NULL)
    map = _map;
  return (map);
}


void  rm_pl(int x, int y, t_client *pl)
{
  t_map_case ***map;

  map = get_map(NULL);

  if (MAP->client != NULL)
  {
    t_pl_case *tmp;

    tmp = MAP->client;

    if (tmp->next == NULL && tmp->client == pl)
      MAP->client = NULL;
    else if (tmp->client == pl)
      MAP->client = tmp->next;
    else
    {
      while (tmp)
      {
        if (tmp->next != NULL && tmp->next->client == pl)
          tmp->next = tmp->next->next;
        tmp = tmp->next;
      }
    }
  }
}

void  add_pl(int x, int y, t_client *pl)
{
  t_map_case ***map;

  map = get_map(NULL);
  if (MAP->client == NULL)
  {
    MAP->client = xmalloc(sizeof(t_pl_case));
    MAP->client->next = NULL;
    MAP->client->client = pl;
  } 
  else 
  {
   t_pl_case  *tmp;
   t_pl_case  *new;

   tmp = MAP->client;
   while (tmp->next)
    tmp = tmp->next; 
  new = xmalloc(sizeof(t_pl_case));
  new->next = NULL;
  new->client = pl;
  tmp->next = new;
}
}
