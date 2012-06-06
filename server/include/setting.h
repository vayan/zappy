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