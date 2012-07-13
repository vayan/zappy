/*
** setting.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:39:04 2012 yann vaillant
** Last update Mon Jul  9 18:34:28 2012 vailla_y
*/

#ifndef __SETTING_
#define __SETTING_

#include "serv_time.h"

#define NEVER_DIE 0
#define USAGE "Usage : %s -p port -x width -y height -n nameteam1 nameteam2 [..] -c MaxClientPerTeam -t delay\n"

typedef struct	s_eggs {
  int		id;
  int		from;
  int		x;
  int		y;
  t_serv_time	*stm;
  int		state;
  struct s_eggs	*next;
}		t_eggs;

typedef struct	s_team {
  char		*name;
  int		max;
  int		nbr_pl;
  int		left;
  int		nb_lvl_max;
  t_eggs	*egg;
  t_serv_time	*stm;
  struct s_team	*next;
}		t_team;

typedef struct	s_setting {
  int		port;
  int   verbose;
  int		height_map;
  int		width_map;
  t_team	*all_team;
  int		max_cl_per_team;
  int		delay;
}		t_setting;

t_setting	*get_setting(t_setting *_setting);
void		aff_setting();
void		init_setting(t_setting *setting);
int		count_nb_team(char **av, int i, int ac);
int		fill_setting(char **set, int ac, t_setting *setting);
int		check_setting(t_setting *setting);
int		parser_setting(int ac, char **av);
int		rm_slot_team(t_team *cl, t_eggs *to_remove);
int		add_slot_team(t_team *cl, t_eggs *egg);
void		add_team(t_setting *setting, char *name, int max);
void		init_setting(t_setting *setting);

#endif
