#ifndef __NETWORK__
#define __NETWORK__

#include <signal.h>
#include "client.h"

#define MAX_INPUT 50000

int network();
int   remove_client(t_client *to_remove);
t_client  *add_client(t_client *all_client, int fd);
void    get_data_from_client(t_client *all_client, fd_set *readfs);
int   get_higher_fd(t_client *all_client);
void    select_list(t_client *all_client, fd_set *readf);

#endif