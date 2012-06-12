/*
** option.h for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Tue Jun 12 11:57:02 2012 randy lyvet
** Last update Tue Jun 12 14:37:35 2012 randy lyvet
*/

#ifndef OPTION_H_
# define OPTION_H_

typedef struct  s_option
{
  char          *option;
  int           (*op_func)(char **command);
}               t_option;

#endif /* !OPTION_H_ */
