/*
** utils_setting.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun 26 12:56:14 2012 yann vaillant
** Last update Tue Jun 26 12:56:14 2012 yann vaillant
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

t_setting    *get_setting(t_setting *_setting)
{
  static t_setting *setting = NULL;

  if (_setting != NULL)
    setting = _setting;
  return (setting);
}

void  aff_team(t_team *team)
{
  int i;
  t_team *tmp;

  tmp = team;
  printf("\033[1;%sm Teams : \033[0;0;00m\n", WHITE_BLUE);
  if (tmp != NULL)
  {
    while (tmp)
    {
      printf("\033[1;%sm\t%s\033[0;0;00m\n", WHITE_BLUE, tmp->name);
      tmp = tmp->next;
    }
  }
}

void aff_setting()
{
  t_setting *setting;

  setting = get_setting(NULL);
  printf("\033[1;%sm*****************************\033[0;0;00m\n", WHITE_BLUE);
  printf("\033[1;%sm Listening on port %d... \n Configuration : \n\tMax(%d) \n\tWorldX(%d)\
    \n\tWorldY(%d) \n\tDelay(%d)\033[0;0;00m\n", 
    WHITE_BLUE, setting->port, setting->max_cl_per_team, setting->width_map,
    setting->height_map, setting->delay); 
  aff_team(setting->all_team);
  printf("\033[1;%sm*****************************\n\033[0;0;00m\n", WHITE_BLUE);
}

int count_nb_team(char **av, int i, int ac)
{
  int nb;

  nb = 0;
  while (i < ac && av[i][0] != '-')
  {
    nb++;
    i++;
  }
  return (nb);
}
