//
// main.cpp for main in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun  5 13:19:33 2012 alexandre haulotte
// Last update Fri Jun 29 11:23:33 2012 alexandre haulotte
//

#include	<signal.h>
#include	"Player.hh"
#include	"Errur.hh"

void	signal_pipe(int sig)
{
  std::cout << "For the life of my little sister in the castle far far away!!!" << std::endl;
  exit(0);
}

int	main(int ac, char **av)
{
  Player	*pl = new Player();
  try
    {
      signal(SIGPIPE, &signal_pipe);
      pl->parse(ac, av);
      pl->play();
    }
  catch (Errur* e)
    {
      std::cout << e->what() << std::endl;
    }
  return (0);
}


