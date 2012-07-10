/*
** main_loop.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:55:07 2012 yann vaillant
** Last update Tue Jul 10 11:29:06 2012 robin maitre
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <time.h>
#include <signal.h>

#include "network.h"
#include "xfunc.h"
#include "setting.h"
#include "map.h"

void	clean_quit()
{
  free_close_client();
  free_setting();
  printf("\n");
  exit(11);
}

int	do_each_loop(t_client *all_client, fd_set *readf)
{
  get_data_from_client(all_client, readf);
  do_input_client(all_client);
  check_timer_all_team();
  if (NEVER_DIE == 0)
    check_death_all_player();
  return (0);
}

void	init_timeval(struct timeval *tv)
{
  tv->tv_sec = 0;
  tv->tv_usec = 1;
}
