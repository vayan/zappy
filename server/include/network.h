#ifndef __NETWORK__
#define __NETWORK__

#include <signal.h>

#define MAX_INPUT 50000

typedef void (*sighandler_t)(int);

typedef struct      s_client {
  int       fd;
  struct  s_client  *next;
}    t_client;


int network(int ac, char **av);
t_client    *get_all_client(t_client *_all_client);
int   remove_client(t_client *to_remove);
t_client  *add_client(t_client *all_client, int fd);
void    get_data_from_client(t_client *all_client, fd_set *readfs);
int   get_higher_fd(t_client *all_client);
void    select_list(t_client *all_client, fd_set *readf);

#endif