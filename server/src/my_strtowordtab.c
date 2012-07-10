/*
** my_strtowordtab.c for ms_ls in /home/lyvet_r//tek2ed/minishell/minishell 1
**
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
**
** Started on  Fri Nov 11 12:50:40 2011 randy lyvet
** Last update Tue Jul 10 11:47:49 2012 robin maitre
*/

#include <string.h>
#include <stdlib.h>

#include "xfunc.h"

void	free_tab(char **tab)
{
  int	i;
 
  i = 0;
  while (tab[i])
    {
      if (tab[i] != NULL)
        xfree(tab[i]);
      i++;
    }
  if (tab != NULL)
    xfree(tab);
}

char	**my_str_to_wordtab(char *s1, char sep)
{
  char	s2[2];
  char	**tab;
  char	*tmp;
  char	*token;
  int	i;

  if (s1 == NULL || strlen(s1) <= 1)
    return (NULL);
  tmp = xmalloc(strlen(s1) + 1);
  strcpy(tmp, s1);
  i = 1;
  s2[0] = sep;
  s2[1] = 0;
  tab = xmalloc(sizeof(char *));
  token = strtok(tmp, s2);
  tab[0] = token;
  while (token != NULL)
    {
      tab = realloc(tab, sizeof(char*) * (i + 1));
      token = strtok(NULL, s2);
      tab[i] = token;
      i++;
    }
  return (tab);
}
