//
// main.cpp for main in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun  5 13:19:33 2012 alexandre haulotte
// Last update Wed Jun  6 14:12:33 2012 alexandre haulotte
//

#include	"Core.hh"
#include	"Errur.hh"

int	main(int ac, char **av)
{
  try
    {
      Core	core(ac, av);
      core.go();
    }
  catch (Errur* e)
    {
      std::cout << e->what() << std::endl;
    }
  return (0);
}


