/*
** new_client_is_graphic.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:55:20 2012 yann vaillant
** Last update Mon Jul  2 11:55:23 2012 yann vaillant
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

void  data_egg_graphic()
{
  t_setting *setting;
  t_team    *tmp;
  t_eggs    *egg;

  setting = get_setting(NULL);
  tmp = setting->all_team;

  while (tmp)
    {
      egg = tmp->egg;
      while (egg)
        {
          enw(egg);
          egg = egg->next;
        }
      tmp = tmp->next;
    }
}

void  first_data_graphic(t_client *cl)
{
  t_client *all_cl;

  all_cl = get_all_client(NULL);
  msz(NULL, cl);
  sgt(NULL, cl);
  mct(NULL, cl);
  tna(NULL, cl);

  if (all_cl != NULL)
    {
      while (all_cl)
        {
          if (all_cl->teams != NULL)
            pnw(NULL, all_cl);
          all_cl = all_cl->next;
        }
    }
  data_egg_graphic();
}
