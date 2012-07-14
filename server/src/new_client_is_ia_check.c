/*
** new_client_is_ia_check.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:55:52 2012 yann vaillant
** Last update Sat Jul 14 13:23:12 2012 robin maitre
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
#include "option.h"
#include "client.h"
#include "map.h"
#include "setting.h"
#include "my_strtowordtab.h"
#include "command_fonc.h"

t_team		*check_team(char *team)
{
  t_setting	*setting;
  t_team	*tmp;

  setting = get_setting(NULL);
  tmp = setting->all_team;
  while (tmp)
    {
      if (strcmp(team, tmp->name) == 0)
        return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		check_place_left_in_team(t_client *cl, char *cmd, t_team *tm)
{
  cmd = cmd;
  if (tm->left == 0 || tm->nbr_pl >= 100)
    {
      broadcast_to_one_client("ko\n", cl);
      cl->death->in_use = -1;
      remove_client(cl);
      return (1);
    }
  return (0);
}
