/*
** option.h for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
**
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
**
** Started on  Tue Jun 12 11:57:02 2012 randy lyvet
** Last update Sat Jul 14 11:51:53 2012 yann vaillant
*/

#ifndef OPTION_H_
# define OPTION_H_

#include	"network.h"

#define		TAB_SIZE	9

typedef struct	s_option
{
  char		*option;
  int		(*op_func)(char **command, t_client *client);
}		t_option;

void	init_tab(t_option *tab);

#endif /* !OPTION_H_ */
