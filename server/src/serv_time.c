/*
** serv_time.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun 14 15:40:40 2012 yann vaillant
** Last update Tue Jul 10 11:29:27 2012 alexandre haulotte
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "serv_time.h"

void		start_timer(t_serv_time* stm)
{
  timespec	tp;

  clock_gettime(CLOCK_REALTIME, &tp);
  stm->start_time = tp;
}

timespec	diff(timespec start, timespec end)
{
  timespec	temp;

  if ((end.tv_nsec - start.tv_nsec) < 0)
    {
      temp.tv_sec = end.tv_sec - start.tv_sec - 1;
      temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    }
  else
    {
      temp.tv_sec = end.tv_sec - start.tv_sec;
      temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
  return (temp);
}

void		set_elapse_time(t_serv_time *stm)
{
  timespec	tp;
  timespec	tp_diff;
  long int	tim;

  clock_gettime(CLOCK_REALTIME, &tp);
  tp_diff = diff(stm->start_time, tp);
  tim = (tp_diff.tv_sec * 1000000000) + tp_diff.tv_nsec;
  stm->in_nsec  = tim;
}

void		set_elapse_sec(t_serv_time *stm)
{
  timespec	tp;
  timespec	tp_diff;
  long int	tim;

  clock_gettime(CLOCK_REALTIME, &tp);
  tp_diff = diff(stm->start_time, tp);
  tim  = tp_diff.tv_sec;
  stm->in_sec = tim;
}

