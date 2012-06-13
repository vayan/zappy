#ifndef __SERV_TIME_
#define __SERV_TIME_

typedef struct s_serv_time {
  double   start_time;
  double   start_time_sec;
  int   end;
  clockid_t clk_id;
} t_serv_time;

#endif