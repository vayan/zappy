/*
** network.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:57 2012 yann vaillant
** Last update Mon Jul  9 16:12:26 2012 vailla_y
*/

#ifndef __NETWORK__
#define __NETWORK__

#include <sys/socket.h>
#include <sys/select.h>
#include <signal.h>
#include <netinet/in.h>

#include "client.h"

#define MAX_INPUT 990000
#define COLOR_BLU "1;34"
#define WHITE_BLUE "36"
#define RED "1;32"
#define DARK_RED "32"

int		network();
int		remove_client(t_client *to_remove);
t_client	*add_client(t_client *all_client, int fd);
void		get_data_from_client(t_client *all_client, fd_set *readfs);
int		get_higher_fd();
void		select_list(t_client *all_client, fd_set *readf);
void		clean_quit();
int		broadcast_to_one_client(char *msg, t_client *me);
void		init_timeval(struct timeval *tv);
int		do_each_loop(t_client *all_client, fd_set *readf);

#endif
