/*
** main.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun  5 12:26:29 2012 yann vaillant
** Last update Sat Jul 14 17:42:03 2012 yann vaillant
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
#include "setting.h"
#include "map.h"
#include "option.h"

int     main(int ac, char **av)
{
  if (parser_setting(ac, av) == -1)
    return (0);
  aff_setting();
  generate_new_map();
  network();
  return (0);
}
