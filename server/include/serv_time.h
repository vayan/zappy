#ifndef __SERV_TIME_
#define __SERV_TIME_

#include <time.h>

typedef struct timespec timespec;

typedef struct s_serv_time {
  timespec   start_time;
  long int    in_nsec;
  long int    in_sec;
  int         in_use;
} t_serv_time;

void start_timer(t_serv_time* stm);
timespec diff(timespec start, timespec end);
void   set_elapse_time(t_serv_time *stm);
void set_elapse_sec(t_serv_time *stm);


#endif