/*
** network.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun  5 12:26:29 2012 yann vaillant
** Last update Tue Jun 26 12:59:55 2012 yann vaillant
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
#include "setting.h"
#include "map.h"

void    clean_quit()
{
  free_close_client();
  //free_map();
  free_setting();
  printf("\n");
  exit (11);
}

int network()
{
  int     s;
  struct sockaddr_in  sin;
  struct sockaddr_in  client_sin;
  socklen_t   client_sin_len;
  t_client    *all_client;
  t_setting *setting;

  setting = get_setting(NULL);
  xsignal(SIGINT, clean_quit);
  all_client = NULL;
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("socket");
    return (-1);
  }
  init_socket(&sin, setting->port);
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &client_sin, sizeof(client_sin));
  xbind(s, (struct sockaddr*)&sin, sizeof(sin));
  xlisten(s, 42);
  client_sin_len = sizeof(client_sin);
  main_loop(s, client_sin_len, client_sin, all_client);
  xclose(s);
  return (0);
}
