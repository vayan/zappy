/*
** option.h for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Tue Jun 12 11:57:02 2012 randy lyvet
** Last update Fri Jun 15 15:14:29 2012 randy lyvet
*/

#ifndef OPTION_H_
# define OPTION_H_

#include	"network.h"

#define		TAB_SIZE	26

typedef struct  s_option
{
  char          *option;
  int           (*op_func)(char **command, t_client *client);
}               t_option;

#endif /* !OPTION_H_ */
