/*
** main_loop.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Mon Jul  2 11:55:07 2012 yann vaillant
** Last update Mon Jul  2 12:08:17 2012 yann vaillant
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

void  init_socket(struct sockaddr_in    *sin, int port)
{
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = INADDR_ANY;
}

int do_each_loop(t_client *all_client, fd_set *readf)
{
  get_data_from_client(all_client, readf);
  do_input_client(all_client);
  check_timer_all_team();
  if (NEVER_DIE == 0)
    check_death_all_player();
  return (0);
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
      if (all_client != NULL && all_client->next == NULL
          && all_client->fd == -1)
        all_client = NULL;
      if (FD_ISSET(s, &readf))
        {
          cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
          printf("\033[1;%sm%s\033[0;0;00m\n", COLOR_BLU, "--New Connexion");
          if (all_client == NULL)
            get_all_client(all_client = add_client(all_client, cs));
          else
            add_client(all_client, cs);
        }
      do_each_loop(all_client, &readf);
    }
}


