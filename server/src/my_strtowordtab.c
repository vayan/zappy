/*
** my_strtowordtab.c for ms_ls in /home/lyvet_r//tek2ed/minishell/minishell 1
** 
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
** 
** Started on  Fri Nov 11 12:50:40 2011 randy lyvet
** Last update Thu Jun 14 12:26:56 2012 randy lyvet
*/

#include	"xfunc.h"

int	my_count_word(char *str, char sep)
{
  int	i;
  int	nbw;

  i = 0;
  nbw = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	nbw++;
      i++;
    }
  return (nbw + 1);
}

char	**my_alloc_tab(char *str, char sep)
{
  char	**tab;
  int	i;
  int	k;
  int	szw;

  tab = xmalloc(sizeof(*tab) * (my_count_word(str, sep) + 2));
  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      szw = 0;
      while ((str[i] != sep) && (str[i] != '\0'))
	{
	  szw++;
	  i++;
	}
      if (szw)
	tab[k++] = xmalloc(sizeof(**tab) * (szw + 2));
      i++;
    }
  tab[k] = '\0';
  return (tab);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  tab = my_alloc_tab(str, sep);
  i = 0;
  j = 0;
  while (str[i])
    {
      k = 0;
      while (str[i] != sep && str[i])
	tab[j][k++] = str[i++];
      if (k)
	{
	  tab[j][k] = '\0';
	  j++;
	}
      if (str[i])
	i++;
    }
  tab[j] = '\0';
  return (tab);
}
