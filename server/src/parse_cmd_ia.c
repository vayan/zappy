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
#include "option.h"
#include "client.h"
#include "map.h"
#include "setting.h"
#include "my_strtowordtab.h"

void  first_data_graphic(t_client *cl)
{
  msz(NULL, cl);

}

t_team *check_team(char *team)
{
  t_setting *setting;
  t_team *tmp;

  setting = get_setting(NULL);
  tmp = setting->all_team;
  while(tmp)
  {
    if (strcmp(team, tmp->name) == 0)
      return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}

int   get_type_client(char *cmd, t_client *cl)
{
  char *buff_int;
  t_setting *setting;
  t_team *tm;

  setting = get_setting(NULL);
  buff_int = xmalloc(50 * sizeof(char*));
  if (strcmp (cmd, "GRAPHIC") == 0)
  {
    cl->is_graphic = 1;
    get_graphic(cl);
    return (0);
  }
  else if (cl->teams == NULL && (tm = check_team(cmd)) != NULL)
  {
    if (tm->left == 0)
    {
      broadcast_to_one_client("ko\n", cl);
      cl->death->in_use = -1;
      return (1);
    }     
    add_client_on_map(cl);
    cl->teams = check_team(cmd);
    tm->left--;
    cl->death->in_use = -1;
    sprintf(buff_int, "%d\n", cl->id);
    broadcast_to_one_client(buff_int, cl);
    sprintf(buff_int, "%d %d\n", setting->width_map, setting->height_map);
    broadcast_to_one_client(buff_int, cl);
    if (get_graphic(NULL) != NULL)
      pnw(NULL, get_graphic(NULL));
    return (0);
  }
  return (1);
}

int   parse_cmd_ia(char *cmd, t_client *cl)
{
  char **tab;

  tab = my_str_to_wordtab(cmd, ' ');
  get_type_client(tab[0], cl);
  if (cl->teams != NULL)
  {
    if (strcmp(tab[0], "avance") == 0)
      return (MoveFront(cl));
    else if (strcmp(tab[0], "droite") == 0)
      return (turnRight(cl));
    else if (strcmp(tab[0], "gauche") == 0)
      return (turnLeft(cl));
    else if (strcmp(tab[0], "inventaire") == 0)
      return (Inventory(cl));
    else if (strcmp(tab[0], "prend") == 0)
      return(Take_Object(cl, parse_rsr(tab[1])));
    else if (strcmp(tab[0], "pose") == 0)
      return(Drop_Object(cl, parse_rsr(tab[1])));
    else if (strcmp(tab[0], "expulse") == 0)
      return(expelliarmus(cl));
    else if (strcmp(tab[0], "broadcast") == 0)
      return (broad_ia(cl, get_all_client(NULL), parse_msg(cmd)));
    else if (strcmp(tab[0], "incantation") == 0)
    {
    }
    else if (strcmp(tab[0], "fork") == 0)
      return (fork_cl(cl));
    else if (strcmp(tab[0], "connect_nbr") == 0)
      return (do_connect_nbr(cl));
    else if (strcmp(tab[0], "voir") == 0) 
      return (Want_See(cl));
  }
  return (0);
}
