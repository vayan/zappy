/*
** settings.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Thu Jun  7 15:38:27 2012 yann vaillant
** Last update Tue Jul 10 11:28:50 2012 alexandre haulotte
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

int	fill_struct_set(char **set, t_setting *setting, int i, int ac)
{
  if (strcmp("-p", set[i]) == 0 && i + 1 <= ac)
    setting->port = atoi(set[++i]);
  if (strcmp("-v", set[i]) == 0)
    setting->verbose = 1;
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

int	fill_setting(char **set, int ac, t_setting *setting)
{
  int	i;
  int	save;

  i = 1;
  init_setting(setting);
  while (i < ac)
    {
      i = fill_struct_set(set, setting, i, ac);
      if (strcmp("-n", set[i]) == 0 && i + 1 <= ac)
        save = i;
      i++;
    }
  if (strcmp("-n", set[save]) == 0 && save++ + 1 <= ac)
    {
      while (save < ac && set[save][0] != '-')
        {
          if (strlen(set[save]) <= 1)
            {
              printf("Error : team name must be 2 cara or more\n");
              return (-1);
            }
          add_team(setting, set[save++], setting->max_cl_per_team);
        }
    }
  return (0);
}

int	check_setting(t_setting *setting)
{
  if (setting->port == -1 || setting->width_map == -1 ||
      setting->height_map == - 1 || setting->max_cl_per_team == -1 ||
      setting->delay == -1)
    printf(USAGE, "test");
  else if (setting->port < 2000)
    printf("Error : port < 2000\n");
  else if (setting->width_map < 5 || setting->width_map > 100)
    printf("Error : 100 > x > 1 \n");
  else if (setting->height_map < 5 || setting->height_map > 100)
    printf("Error : 100 > y > 1 \n");
  else if (setting->max_cl_per_team <= 0)
    printf("Error : max client <= 0 \n");
  else if (setting->delay <= 0 || setting->delay >= 10000)
    printf("Error : 10000 > y > 1 \n");
  else
    return (0);
  return (-1);
}

int		parser_setting(int ac, char **av)
{
  t_setting	*setting;

  setting = xmalloc(sizeof(t_setting));
  if (ac < 13)
    {
      printf(USAGE, av[0]);
      return (-1);
    }
  setting->verbose = 0;
  if (fill_setting(av, ac, setting) == -1)
    return (-1);
  get_setting(setting);
  return (check_setting(setting));
}
