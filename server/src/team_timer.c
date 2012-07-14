/*
** team_timer.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun 26 12:56:04 2012 yann vaillant
** Last update Sat Jul 14 18:35:14 2012 robin maitre
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

#include "network.h"
#include "xfunc.h"
#include "map.h"
#include "setting.h"
#include "client.h"
#include "command_fonc.h"

int		check_time_all_egg(t_eggs *egg, t_team *cl)
{
  t_setting	*setting;

  if (egg->state == 1)
    return (1);
  if (egg->stm->in_use == -1)
    {
      egg->stm->in_use = 1;
      start_timer(egg->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(egg->stm);
  set_elapse_sec(egg->stm);
  if (((egg->stm->in_nsec) >= (600000000000 / setting->delay)))
    {
      egg->stm->in_use = -1;
      add_slot_team(cl, egg);
      return (0);
    }
  return (1);
}

int		check_time_pourriture_all_egg(t_eggs *egg, t_team *cl)
{
  t_setting	*setting;

  if (egg->state == 0)
    return (1);
  if (egg->stm->in_use == -1)
    {
      egg->stm->in_use = 1;
      start_timer(egg->stm);
      return (1);
    }
  setting = get_setting(NULL);
  set_elapse_time(egg->stm);
  set_elapse_sec(egg->stm);
  if (((egg->stm->in_nsec) >= ((10 * 126000000000) / setting->delay)))
    {
      egg->stm->in_use = -1;
      rm_slot_team(cl, egg);
      edi(egg->id);
      return (0);
    }
  return (1);
}

int		check_timer(t_team *cl)
{
  t_eggs	*tmp;

  tmp = cl->egg;
  while (tmp)
    {
      check_time_all_egg(tmp, cl);
      check_time_pourriture_all_egg(tmp, cl);
      tmp = tmp->next;
    }
  return (0);
}

int		check_timer_all_team()
{
  t_setting	*setting;
  t_team	*tmp;

  setting = get_setting(NULL);
  tmp = setting->all_team;
  while (tmp)
    {
      if (tmp->egg != NULL)
        check_timer(tmp);
      tmp = tmp->next;
    }
  return (0);
}
