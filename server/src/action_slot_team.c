/*
** action_slot_team.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:50:36 2012 yann vaillant
** Last update Mon Jul  9 12:33:23 2012 vailla_y
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

int		rm_slot_team(t_team *cl, t_eggs *to_remove)
{
  t_eggs	*tmp;

  tmp = cl->egg;
  if (tmp->next == NULL && tmp == to_remove)
    {
      cl->egg = NULL;
      return (0);
    }
  while (tmp)
    {
      if (tmp->next != NULL && tmp->next == to_remove)
        {
          tmp->next = tmp->next->next;
          return (0);
        }
      tmp = tmp->next;
    }
  return (1);
}

int		add_slot_team(t_team *cl, t_eggs *egg)
{
  cl->left += 1;
  eht(cl->egg->id);
  egg->state = 1;
  return (0);
}
