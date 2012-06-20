/*
** client.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:47 2012 yann vaillant
** Last update Wed Jun 20 11:45:42 2012 anatole carlier
*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include "serv_time.h"
//#include "map.h"

typedef enum Ressource {
  Nourriture,
  Linemate,
  Deraumere,
  Sibur,
  Mendiane,
  Phiras,
  Thystame
} Ressource;

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

typedef struct s_buffer_msg
{
  char *msg;
  struct s_buffer_msg *next;
} t_buffer_msg;

typedef struct      s_client {
  int       fd;
  int       id;
  int       level;
  char      *team;
  int       x;
  int       y;
  int       action[12];
  int       is_graphic;
  t_buffer_msg *buff_msg;
  Direction dir;
  t_serv_time *stm;
  Ressource     *rsrc;
  struct  s_client  *next;
}    t_client;


t_client        *get_all_client(t_client *_all_client);
int		remove_client(t_client *to_remove);
void		remove_client_on_map(t_client *cl);
void		add_client_on_map(t_client *new);
t_client        *add_client(t_client *all_client, int fd);
void		MoveClient(t_client *cl);
void		TurnClient(t_client *cl, int turn);
int		turnLeft(t_client *cl);
int		turnRight(t_client *cl);
int		MoveFront(t_client *cl);
void		send_invent(t_client *cl);
int		Inventory(t_client *cl);
void		show_all_msg(t_client *cl);
int		add_msg_to_buffer(t_client *cl, char *msg);
int		broad_ia(t_client *cl, t_client *all_client, char *msg);
int		do_say(t_client *me, t_client *all_client, char *msg);
char		*parse_msg(char *msg);

#endif
