/*
** map.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:38:53 2012 yann vaillant
** Last update Sat Jul 14 11:54:57 2012 yann vaillant
*/

#ifndef _MAP_H
#define _MAP_H

#include "client.h"

#define MAP (map[x][y])

typedef struct		s_pl_case
{
  t_client		*client;
  struct s_pl_case	*next;
}			t_pl_case;

typedef struct	s_map_case {
  int		x;
  int		y;
  Ressource	*rsrc;
  t_pl_case	*client;
}		t_map_case;

t_map_case	***get_map(t_map_case ***_map);
void		aff_rsrc(Ressource* rsrc);
void		aff_player(t_pl_case* pl);
void		aff_map();
void		rm_pl(int x, int y, t_client *pl);
void		add_pl(int x, int y, t_client *pl);
Ressource	*gen_rsrc();
void		generate_new_map();
void		aff_pl_test();
void		free_close_client();
int		free_map();
int		free_setting();
int		free_buff_msg(t_buffer_msg *buff_msg);
int		free_client_map(t_pl_case *client);
char		*ressource_to_char(Ressource rsrc);
int		parse_rsr(char *rsrc);
void		strcat_player(t_pl_case *tmp, char *msg);
void		set_y_see(t_client *cl, int *y, int lvl, int i);
void		set_x_see(t_client *cl, int *x, int lvl, int i);
int		count_pl_on_case(int lvl_me, t_pl_case *all_cl_case);
void		fill_tab_req(int *req, int level);
void		gen_new_rsrc();
void  incant_broad(t_client *cl, t_map_case ***map, int *req, int dead);

#endif
