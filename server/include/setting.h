/*
** setting.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:39:04 2012 yann vaillant
** Last update Thu Jun  7 15:39:04 2012 yann vaillant
*/

#ifndef __SETTING_
#define __SETTING_

#include "serv_time.h"

#define USAGE "Usage : %s -p port -x width -y height -n nameteam1 nameteam2 [..] -c MaxClientPerTeam -t delay\n"
#define FLAGDEBUG 1 //1 = valeur par defaut pas besoin de foutre tout les options - 0 = normal

typedef struct s_team {
  char *name;
  int   max;
  int   left;
  int   to_open;
  t_serv_time *stm;
  struct s_team *next;
} t_team;

typedef struct s_setting {
  int   port;
  int   height_map;
  int   width_map;
  //char  **name_teams;
  t_team    *all_team;
  int   max_cl_per_team;
  int   delay;
} t_setting;


t_setting    *get_setting(t_setting *_setting);
void aff_setting();
void init_setting(t_setting *setting);
int count_nb_team(char **av, int i, int ac);
void fill_setting(char **set, int ac, t_setting *setting);
int   check_setting(t_setting *setting);
int   parser_setting(int ac, char **av);


#endif
