  /*
** settings.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Jun  7 15:38:27 2012 yann vaillant
** Last update Thu Jun  7 15:38:28 2012 yann vaillant
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
#include "setting.h"
#include "xfunc.h"
#include "network.h"

void  add_team(t_setting *setting, char *name, int max)
{
  t_team *tmp;
  t_team *new;

  tmp = setting->all_team;
  new = xmalloc (sizeof(t_team));
  new->name = strdup(name);
  new->max = max;
  new->left = max;
  new->to_open = 0;
  new->stm = xmalloc(sizeof(t_serv_time));
  new->stm->in_use = -1;
  new->next = NULL;
  if (tmp == NULL)
    setting->all_team = new;
  else 
  {
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
  }
}

void init_setting(t_setting *setting)
{
  if (FLAGDEBUG == 0)
  {
    setting->port = -1;
    setting->width_map = -1;
    setting->height_map = -1;
    setting->max_cl_per_team = -1;
    setting->delay = -1;
    setting->all_team = NULL;
  }
  if (FLAGDEBUG == 1)
  {
    setting->port =  4242;
    setting->width_map = 5;
    setting->height_map = 7;
    setting->max_cl_per_team = 3;
    setting->delay = 100;
    add_team(setting, "foo", 3);
    add_team(setting, "bar", 3);
  }
}

int  fill_struct_set(char **set, t_setting *setting, int i, int ac)
{
  if (strcmp("-p", set[i]) == 0 && i + 1 <= ac)
    setting->port = atoi(set[++i]);
  if (strcmp("-x", set[i]) == 0 && i + 1 <= ac)
    setting->width_map = atoi(set[++i]);
  if (strcmp("-y", set[i]) == 0 && i + 1 <= ac)
    setting->height_map = atoi(set[++i]);
  if (strcmp("-c", set[i]) == 0 && i + 1 <= ac)
    setting->max_cl_per_team = atoi(set[++i]);
  if (strcmp("-t", set[i]) == 0 && i + 1 <= ac)
    setting->delay = atoi(set[++i]);
  return (i);
}

void fill_setting(char **set, int ac, t_setting *setting)
{
  int i;
  int b;

  i = 1;
  init_setting(setting);
  if (FLAGDEBUG == 0)
  {
    while (i < ac)
    {
      b = 0;   
      i = fill_struct_set(set, setting, i, ac);
      if (strcmp("-n", set[i]) == 0 && i + 1 <= ac)
      {
        i++;
        while (i < ac && set[i][0] != '-')
        {
          add_team(setting, set[i], 0);
          i++;
        }
        b = 1;
      }
      if (b == 0)
        i++;
    }
  }
}

int   check_setting(t_setting *setting)
{
  if (setting->port == -1 || setting->width_map == -1 || setting->height_map == - 1 || 
    setting->max_cl_per_team == -1 || setting->delay == -1)
    printf(USAGE, "test");
  else if (setting->port < 2000)
    printf("Error : port < 2000\n");
  else if (setting->width_map <= 0)
    printf("Error : x <= 0 \n");
  else if (setting->height_map <= 0)
    printf("Error : y <= 0 \n");
  else if (setting->max_cl_per_team <= 0)
    printf("Error : max client <= 0 \n");
  else if (setting->delay <= 0)
    printf("Error : delay <= 0 \n");
  else
    return (0);
  return (-1);
}

int   parser_setting(int ac, char **av)
{
  t_setting *setting;

  setting = xmalloc(sizeof(t_setting));

  if (FLAGDEBUG == 1)
    printf("==DEBUG ACTIVEE!!==\n");
  if (ac < 13 && FLAGDEBUG == 0)
  {
    printf(USAGE, av[0]);
    return (-1);
  }
  fill_setting(av, ac, setting);
  get_setting(setting);
  return (check_setting(setting));
}
