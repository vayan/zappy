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
#include "setting.h"
#include "xfunc.h"

t_setting    *get_setting(t_setting *_setting)
{
  static t_setting *setting = NULL;

  if (_setting != NULL)
    setting = _setting;
  return (setting);
}

// char **to_tab(char *msg)
// {
//   char  *tok;
//   char  **tab;
//   int   i;

//   i = 0;
//   tab = xmalloc(1 * sizeof(*tab));
//   tok = strtok(msg, " ");
//   while (tok != NULL)
//   {
//     tab[i] = strdup(msg);
//     i++;
//     tab = realloc(tab, (1 + i) * sizeof(*tab));
//     tab[i] = NULL;
//     tok = strtok(NULL, " ");
//   }
//   return (tab);
// }

void aff_setting()
{
  t_setting *setting;

  setting = get_setting(NULL);
  printf("port:%d, X:%d, Y:%d, MAXCL:%d, DELAY:%d\n", setting->port, setting->width_map, 
    setting->height_map, setting->max_cl_per_team, setting->delay);
}

void fill_setting(char **set, int ac, t_setting *setting)
{
  int i;

  i = 1;
  setting->port = -1;
  setting->width_map = -1;
  setting->height_map = -1;
  setting->max_cl_per_team = -1;
  setting->delay = -1;
  setting->name_teams = NULL;
  while (i < ac)
  {
    if (strcmp("-p", set[i]) == 0 && i + 1 <= ac)
      setting->port = atoi(set[++i]);
    if (strcmp("-x", set[i]) == 0 && i + 1 <= ac)
      setting->width_map = atoi(set[++i]);
    if (strcmp("-y", set[i]) == 0 && i + 1 <= ac)
      setting->height_map = atoi(set[++i]);
    if (strcmp("-c", set[i]) == 0 && i + 1 <= ac)
      setting->max_cl_per_team = atoi(set[++i]);
    if (strcmp("-t", set[i]) == 0 && i + 1 <= ac)
      setting->delay = atoi(set[++i]);
    i++;
  }
}

int   check_setting(t_setting *setting)
{
  if (setting->port == -1 || setting->width_map == -1 || setting->height_map == - 1 || 
    setting->max_cl_per_team == -1 || setting->delay == -1)
    printf(USAGE);
  else if (setting->port < 2000)
    printf("Error : port < 2000\n");
  else if (setting->width_map <= 0)
    printf("Error : x <= 0 \n");
  else if (setting->height_map <= 0)
    printf("Error : y <= 0 \n");
  else if (setting->max_cl_per_team <= 0)
    printf("Error : max client <= 0 \n");
  else if (setting->delay <= 0)
    printf("Error : delay <= 0 \n");
  else
    return (0);
  return (-1);
}

int   parser_setting(int ac, char **av)
{
  t_setting *setting;

  setting = xmalloc(sizeof(t_setting));
  if (ac < 13)
  {
    printf(USAGE, av[0]);
    return (-1);
  }
  fill_setting(av, ac, setting);
  get_setting(setting);
  return (check_setting(setting));
}