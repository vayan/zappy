/*
** check_win.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:53:52 2012 yann vaillant
** Last update Tue Jul 10 13:39:39 2012 randy lyvet
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<sys/time.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/ipc.h>
#include		<time.h>
#include		<signal.h>

#include		"network.h"
#include		"xfunc.h"
#include		"map.h"
#include		"setting.h"
#include		"client.h"
#include		"command_fonc.h"

int			check_win()
{
  t_setting		*setting;
  t_team		*all_team;

  setting = get_setting(NULL);
  all_team = setting->all_team;
  while (all_team)
    {
      if (all_team->nb_lvl_max >= 6)
        {
          seg(all_team);
          free_close_client();
          xprintf_cc("\033[1;%sm-->\tGG %s is the winner !!!\n\033[0;0;00m\n",
   DARK_RED, all_team->name);
          exit (11);
        }
      all_team = all_team->next;
    }
  return (0);
}
