/*
** serv_time.h for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/include
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun 14 15:39:26 2012 yann vaillant
** Last update Mon Jul  9 16:13:05 2012 vailla_y
*/

#ifndef __SERV_TIME_
#define __SERV_TIME_

#include <time.h>

typedef struct timespec timespec;

typedef struct	s_serv_time {
  timespec	start_time;
  long int	in_nsec;
  long int	in_sec;
  int		in_use;
}		t_serv_time;

void		start_timer(t_serv_time* stm);
timespec	diff(timespec start, timespec end);
void		set_elapse_time(t_serv_time *stm);
void		set_elapse_sec(t_serv_time *stm);

#endif
