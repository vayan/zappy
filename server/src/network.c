/*
** network.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Jun  5 12:26:29 2012 yann vaillant
** Last update Tue Jun  5 12:26:30 2012 yann vaillant
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

void  init_socket(struct sockaddr_in    *sin, int port)
{
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = INADDR_ANY;
}

int main_loop(int s, socklen_t client_sin_len,
  struct sockaddr_in client_sin, t_client *all_client)
{
  int cs;

  while (11)
  {
    fd_set    readf;
    struct  timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 1;
    select_list(all_client, &readf);
    FD_SET(s, &readf);
    if (select(get_higher_fd(all_client) + 1, &readf, NULL, NULL, &tv) == -1)
      printf("Errror : select fail\n");
    if (FD_ISSET(s, &readf))
    {
      cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
      printf("\033[1;%sm%s\033[0;0;00m\n", COLOR_BLU, "--New Connexion");
        if (all_client != NULL && all_client->rm_all_plz == 1)
          printf("\n\n\nI WANT TO FUCKING DIE\n\n\n");
        if (all_client == NULL)
          get_all_client(all_client = add_client(all_client, cs));
        else
          add_client(all_client, cs);
      }
      get_data_from_client(all_client, &readf);
      do_input_client(all_client);
      check_timer_all_team();
      check_death_all_player();
    }
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