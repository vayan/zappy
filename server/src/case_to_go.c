/*
** case_to_go.c for  in /home/lyvet_r//tek2/syst-unix/zappy/zappy-2015-2014s-haulot_a/server
**
** Made by randy lyvet
** Login   <lyvet_r@epitech.net>
**
** Started on  Fri Jun 22 10:32:29 2012 randy lyvet
** Last update Mon Jul  9 12:36:11 2012 vailla_y
*/

int	go_up(int x, int y)
{
  if (x == 1 && y == 0)
    return (7);
  else if (x == 1 && y == 1)
    return (6);
  else if (x == 0 && y == 1)
    return (5);
  else if (x == -1 && y == 1)
    return (4);
  else if (x == -1 && y == 0)
    return (3);
  else if (x == -1 && y == -1)
    return (2);
  else if (x == 0 && y == -1)
    return (1);
  else if (x == 1 && y == -1)
    return (8);
  else
    return (0);
}

int	go_right(int x, int y)
{
  if (x == 1 && y == 0)
    return (1);
  else if (x == 1 && y == 1)
    return (8);
  else if (x == 0 && y == 1)
    return (7);
  else if (x == -1 && y == 1)
    return (6);
  else if (x == -1 && y == 0)
    return (5);
  else if (x == -1 && y == -1)
    return (4);
  else if (x == 0 && y == -1)
    return (3);
  else if (x == 1 && y == -1)
    return (2);
  else
    return (0);
}

int	go_bot(int x, int y)
{
  if (x == 1 && y == 0)
    return (3);
  else if (x == 1 && y == 1)
    return (2);
  else if (x == 0 && y == 1)
    return (1);
  else if (x == -1 && y == 1)
    return (8);
  else if (x == -1 && y == 0)
    return (7);
  else if (x == -1 && y == -1)
    return (6);
  else if (x == 0 && y == -1)
    return (5);
  else if (x == 1 && y == -1)
    return (4);
  else
    return (0);
}

int	go_left(int x, int y)
{
  if (x == 1 && y == 0)
    return (5);
  else if (x == 1 && y == 1)
    return (4);
  else if (x == 0 && y == 1)
    return (3);
  else if (x == -1 && y == 1)
    return (2);
  else if (x == -1 && y == 0)
    return (1);
  else if (x == -1 && y == -1)
    return (8);
  else if (x == 0 && y == -1)
    return (7);
  else if (x == 1 && y == -1)
    return (6);
  else
    return (0);
}
