/*
** main.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun  5 12:26:29 2012 yann vaillant
** Last update Mon Jun 11 17:47:52 2012 alexandre haulotte
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

int     main(int ac, char **av)
{
  //if (parser_setting(ac, av) == -1)
    //return (-1);
  parser_setting(ac, av);
  aff_setting();

  generate_new_map();
  aff_map();

  network();
  return(0);
}
