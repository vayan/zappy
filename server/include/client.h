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
#include "setting.h"

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
  t_team    *teams;
  int       x;
  int       y;
  int       action[12];
  int       is_graphic;
  int       rm_all_plz;
  t_buffer_msg *buff_msg;
  Direction dir;
  t_serv_time *stm;
  t_serv_time *death;
  Ressource     *rsrc;
  struct  s_client  *next;
}    t_client;


t_client        *get_all_client(t_client *_all_client, int reset);
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
t_client    *get_graphic(t_client *_cl, int reset);
char   *inttochar(int i);
int   get_direction(t_client *emeter, t_client *receiver);
void  rm_top_msg_from_buffer(t_client *cl);
int   parse_cmd_ia(char *cmd, t_client *cl);
int do_input_client(t_client *all_client);
void  do_take_obj(t_client *cl, Ressource obj);
void  do_drop_obj(t_client *cl, Ressource obj);
int   Take_Object(t_client *cl, Ressource obj);
int   Drop_Object(t_client *cl, Ressource obj);
int expelliarmus(t_client *cl);
int Want_See(t_client *cl);
char *clean_see(char *msg);
char  *get_see_one_case(int x, int y);
void  scan_case(t_client *cl, char *msg);
void  strcat_rsrc(Ressource *rsrc, char *msg);
int do_see(t_client *cl);
int incant(t_client *cl, int first);
int fork_cl(t_client *cl);
int   do_connect_nbr(t_client *cl);
int   check_timer_all_team();
int   check_death_all_player();
int check_place_left_in_team(t_client *cl, char *cmd, t_team *tm);
t_team *check_team(char *team);
int   get_type_client(char *cmd, t_client *cl);
void  data_egg_graphic();
void  first_data_graphic(t_client *cl);
void  correction_down(t_client *victim, t_client *kicker, t_setting *setting);
void  correction_up(t_client *victim, t_client *kicker, t_setting *setting);
void  correction_right(t_client *victim, t_client *kicker, t_setting *setting);
void  correction_left(t_client *victim, t_client *kicker, t_setting *setting);
void correction_move_down(t_client *cl, t_setting *setting);
void correction_move_up(t_client *cl, t_setting *setting);
void correction_move_right(t_client *cl, t_setting *setting);
void correction_move_left(t_client *cl, t_setting *setting);
char*  clean_msg(char *msg);

#endif
