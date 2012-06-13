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

#endif