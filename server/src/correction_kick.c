/*
** correction_kick.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:54:05 2012 yann vaillant
** Last update Sat Jul 14 11:19:01 2012 yann vaillant
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

void			correction_down(t_client *victim, t_client *kicker,
					t_setting *setting)
{
  if (kicker->dir == Down)
    {
      victim->y += 1;
      if (victim->y >= setting->height_map)
        victim->y = 0;
    }
}

void			correction_up(t_client *victim, t_client *kicker,
				      t_setting *setting)
{
  if (kicker->dir == Up)
    {
      victim->y -= 1;
      if (victim->y < 0)
        victim->y = setting->height_map - 1;
    }
}

void			correction_right(t_client *victim, t_client *kicker,
					 t_setting *setting)
{
  if (kicker->dir ==  Right)
    {
      victim->x += 1;
      if (victim->x >= setting->width_map)
        victim->x = 0;
    }
}

void			correction_left(t_client *victim, t_client *kicker,
					t_setting *setting)
{
  if (kicker->dir ==  Left)
    {
      victim->x -= 1;
      if (victim->x < 0)
        victim->x = setting->width_map - 1;
    }
}
