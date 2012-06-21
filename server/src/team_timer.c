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
#include "map.h"
#include "setting.h"
#include "client.h"

int   add_slot_team(t_team *cl)
{
  cl->left += 1;
  cl->to_open -= 1;
}

int   check_timer(t_team *cl)
{
  t_setting *setting;

  if (cl->stm->in_use == -1)
  { 
    printf("start timer ouverture slot %s\n", cl->name);
    cl->stm->in_use = 1;
    start_timer(cl->stm);
    return (1);
  }
  setting = get_setting(NULL);
  set_elapse_time(cl->stm);
  set_elapse_sec(cl->stm);
  if (( (cl->stm->in_nsec) >= (600000000000/setting->delay)))
  {
    cl->stm->in_use = -1;
    printf("nouveau slot team %s\n", cl->name);
    add_slot_team(cl);
    return (0);
  }
  return (1);  
}

int   check_timer_all_team()
{
  t_setting *setting;
  t_team    *tmp;

  setting = get_setting(NULL);
  tmp = setting->all_team;
  while (tmp)
  {
    if (tmp->to_open > 0)
      check_timer(tmp);    
    tmp = tmp->next;
  }
  return (0);
}