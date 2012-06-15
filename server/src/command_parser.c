/*
** command_parser.c for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Tue Jun 12 11:37:00 2012 randy lyvet
** Last update Fri Jun 15 15:32:26 2012 randy lyvet
*/

#include	<string.h>
#include	<stdlib.h>

#include	"option.h"
#include	"my_strtowordtab.h"
#include	"network.h";

int			command_parser(t_option *tab, char *command, t_client *client)
{
  int           j;
  char		**command_type;
  int		ret;
  int 		g;

  command_type = my_str_to_wordtab(command, ' ');
  j = -1;
  while (++j < TAB_SIZE)
    if (strcmp(tab[j].option, command_type[0]) == 0)
      {
	ret = tab[j].op_func(command_type, client);
	g = -1;
	while (command_type[++j] != 0)
	  free(command_type[j]);
	free(command_type);
	return (ret);
      }
  return (tab[24].op_func(command_type, client));
}