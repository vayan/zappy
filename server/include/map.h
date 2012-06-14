/*
** map.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:53 2012 yann vaillant
** Last update Thu Jun  7 15:38:53 2012 yann vaillant
*/

#ifndef _MAP_H
#define _MAP_H

#include "client.h"

#define MAP (map[x][y])

typedef struct  s_client t_client;

typedef enum Ressource {
  Nourriture,
  Linemate,
  Deraumere,
  Sibur,
  Mendiane,
  Phiras,
  Thystame
} Ressource;

typedef struct s_pl_case
{
  t_client *client;  
  struct s_pl_case *next;
} t_pl_case;

typedef struct s_map_case {
  int   x;
  int   y;
  Ressource     *rsrc;
  t_pl_case     *client;
} t_map_case;

t_map_case    ***get_map(t_map_case ***_map);
void  aff_rsrc(Ressource* rsrc);
void  aff_player(t_pl_case* pl);
void  aff_map();
void  rm_pl(int x, int y, t_client *pl);
void  add_pl(int x, int y, t_client *pl);
Ressource *gen_rsrc();
void    generate_new_map();


#endif
