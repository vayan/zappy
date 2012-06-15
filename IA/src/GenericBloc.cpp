//
// BlocIA.cpp for BlocIA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 11:11:47 2012 alexandre haulotte
// Last update Fri Jun 15 09:48:53 2012 alexandre haulotte
//

#include	"Player.hh"
#include	"PlayerCreator.hh"

int   Player::Avance()
{
  int	ret;

    std::cout << "j'avance" << std::endl;
  _nbCmd++;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "avance\n", 7, 0);
  if (ret == -1)
    return (KO);
  return (OK);
}

int	Player::Droite()
{
  int   ret;

  std::cout << "je tourne a droite" << std::endl;
  _nbCmd++;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "droite\n", 7, 0);
  if (ret == -1)
    return (KO);
  return (OK);
}

int     Player::Gauche()
{
  int   ret;

  std::cout << "je tourne a gauche" << std::endl;
  _nbCmd++;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "gauche\n", 7, 0);
  if (ret == -1)
    return (KO);
  return (OK);
}

int   Player::Pond()
{
  int	ret;

  std::cout << "je pond" << std::endl;
  _nbCmd++;
  _cmd.push_back(FORK);
  ret = send(_soc, "fork\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (OK);
}

int   Player::Eclosion()
{
  PlayerCreator	pc;
  std::cout << "Eclosion" << std::endl;
  pc.create(_addr, _port, _teamName);
  return (OK);
}
