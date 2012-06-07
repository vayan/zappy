#ifndef _MAP_H
#define _MAP_H

#include "client.h"

#define MAP (map[x][y])

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

#endif