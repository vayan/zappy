#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "serv_time.h"

int start_timer(t_serv_time* stm)
{
  clockid_t clk_id;
  struct timespec tp;

  clock_gettime(clk_id, &tp);
  printf("micro %f \n", tp.tv_nsec);
  stm->clk_id = clk_id;
  stm->start_time = (tp.tv_sec * 1000000000) + tp.tv_nsec;
  stm->start_time_sec = tp.tv_sec;
  return (tp.tv_nsec);
}

int   get_elapse_time(t_serv_time *stm)
{
  clockid_t clk_id;
  struct timespec tp2;
  struct timespec tp;

   clock_gettime(clk_id, &tp2);
  clock_gettime(stm->clk_id, &tp);
  //printf("elaspe %d \n", tp.tv_nsec - stm->start_time);
  printf("\n\n operation : %f - %f\n\n",
      (tp.tv_sec * 1000000000) + tp.tv_nsec, (tp2.tv_sec * 1000000000) + tp2.tv_nsec);
  return (((tp.tv_sec * 1000000000) + tp.tv_nsec) - stm->start_time);
}

int get_elapse_sec(t_serv_time *stm)
{
  struct timespec tp;

  clock_gettime(stm->clk_id, &tp);
  return (tp.tv_sec - stm->start_time_sec);
}

