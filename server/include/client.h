/*
** client.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:47 2012 yann vaillant
** Last update Thu Jun  7 15:38:48 2012 yann vaillant
*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include "serv_time.h"

typedef enum Direction {
  Up,
  Right,
  Down,
  Left
} Direction;

typedef enum ActionClient {
  GoFront,
  TurnRight,
  TurnLeft,
  See,
  Inventaire,
  Take,
  Drop,
  Kick,
  Say,
  Incant,
  Fork,
  Slot,
  Dead
} ActionClient;

typedef struct      s_client {
  int       fd;
  int       id;
  int       level;
  char      *team;
  int       x;
  int       y;
  int       action[12];
  Direction dir;
  t_serv_time *stm;
  struct  s_client  *next;
}    t_client;


t_client    *get_all_client(t_client *_all_client);


#endif
