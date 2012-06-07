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

//LIST CHAINNE DES RESSOURCE POUR CHAQUE CASE DE LA MAP
typedef struct s_ressource {
  Ressource type;
  int quantity;
  struct s_ressource *next;
} t_ressource;

typedef struct s_map_case {
  int   x;
  int   y;
  t_ressource   *rsrc;
  t_client      *client;
} t_map_case;

#endif