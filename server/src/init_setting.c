/*
** init_setting.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:54:56 2012 yann vaillant
** Last update Mon Jul  2 11:54:59 2012 yann vaillant
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
  new->egg = NULL;
  new->stm = xmalloc(sizeof(t_serv_time));
  new->stm->in_use = -1;
  new->nb_lvl_max = 0;
  new->nbr_pl = 0;
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
      setting->port = -1;
      setting->width_map = -1;
      setting->height_map = -1;
      setting->max_cl_per_team = -1;
      setting->delay = -1;
      setting->all_team = NULL;
}
