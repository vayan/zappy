/*
** xprintf.c for  in /home/vailla_y/Projet/Tek2/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Sat Jul 14 11:40:55 2012 yann vaillant
** Last update Sat Jul 14 11:41:35 2012 yann vaillant
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "setting.h"

void		xprintf(char *format)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf("%s", format);
}

void		xprintf_ci(const char *format, char *foo, int ts)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf(format, foo, ts);
}

void		xprintf_iii(const char *format, int on, int tw, int thre)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf(format, on, tw, thre);
}

void		xprintf_cic(const char *format, char *on, int tw, char *thre)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf(format, on, tw, thre);
}

void		xprintf_c(const char *format, char *on)
{
  t_setting	*setting;

  setting = get_setting(NULL);
  if (setting != NULL && setting->verbose == 1)
    printf(format, on);
}

