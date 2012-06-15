/*
** command_parser.c for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Tue Jun 12 11:37:00 2012 randy lyvet
** Last update Tue Jun 12 15:46:52 2012 randy lyvet
*/

#include	<string.h>
#include	<stdlib.h>

#include	"option.h"
#include	"my_strtowordtab.h"

int			command_parser(t_option *tab, char *command)
{
  int           j;
  char		**command_type;

  command_type = my_str_to_wordtab(command, ' ');
  j = -1;
  while (tab[++j].option != 0)
    if (strcmp(tab[j].option, command_type[0]) == 0)
    {
     return (tab[j].op_func(command_type));

   }
   j = -1;
   while (command_type[++j] != 0)
    free(command_type[j]);
  free(command_type);
}
