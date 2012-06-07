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

#define USAGE "Usage : %s -p port -x width -y height -n nameteam1 nameteam2 [..] -c MaxClientPerTeam -t delay\n"

typedef struct s_setting {
  int   port;
  int   height_map;
  int   width_map;
  char  **name_teams;
  int   max_cl_per_team;
  int   delay;
} t_setting;


t_setting    *get_setting(t_setting *_setting);

#endif
