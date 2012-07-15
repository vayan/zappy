/*
** network.c for  in /home/vailla_y/Projet/zappy/zappy-2015-2014s-haulot_a/server
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Tue Jun  5 12:26:29 2012 yann vaillant
** Last update Sun Jul 15 21:34:46 2012 robin maitre
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

void			init_socket(struct sockaddr_in *sin, int port)
{
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = INADDR_ANY;
}

int			main_loop(int s, socklen_t client_sin_len,
			  struct sockaddr_in client_sin, t_client *all_cl)
{
  int			cs;

  while (11)
    {
      fd_set		readf;
      struct		timeval tv;

      all_cl = get_all_client(NULL, 0);
      init_timeval(&tv);
      select_list(all_cl, &readf);
      FD_SET(s, &readf);
      select(get_higher_fd() + 30, &readf, NULL, NULL, &tv);
      if (all_cl != NULL && all_cl->next == NULL && all_cl->fd == -1)
        all_cl = NULL;
      if (FD_ISSET(s, &readf))
        {
          cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
          xprintf_cc("\033[1;%sm%s\033[0;0;00m\n", COLOR_BLU, "--New Client");
          if (all_cl == NULL)
            get_all_client(all_cl = add_client(all_cl, cs), 0);
          else
            add_client(all_cl, cs);
        }
      do_each_loop(all_cl, &readf);
    }
}

int			network()
{
  int			s;
  struct sockaddr_in	sin;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;
  t_client		*all_client;
  t_setting		*setting;

  setting = get_setting(NULL);
  xsignal(SIGINT, clean_quit);
  all_client = NULL;
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  init_socket(&sin, setting->port);
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &client_sin, sizeof(client_sin));
  xbind(s, (struct sockaddr*)&sin, sizeof(sin));
  xlisten(s, 42);
  client_sin_len = sizeof(client_sin);
  main_loop(s, client_sin_len, client_sin, all_client);
  xclose(s);
  return (0);
}
