//
// BlocIA.cpp for BlocIA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 11:11:47 2012 alexandre haulotte
// Last update Fri Jun 15 11:59:00 2012 alexandre haulotte
//

#include	"Player.hh"
#include	"PlayerCreator.hh"
#include	"stdlib.h"

int   Player::Avance()
{
  int	ret;

  std::cout << "j'avance" << std::endl;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "avance\n", 7, 0);
  switch (_dir)
    {
    case NORD:
      _y++;
      break;
    case EST:
      _x++;
      break;
    case SUD:
      _y--;
      break;
    case OUEST:
      _x--;
      break;
    }
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::Droite()
{
  int   ret;

  std::cout << "je tourne a droite" << std::endl;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "droite\n", 7, 0);
  if (ret == -1)
    return (ERR);
  return (OK);
}

int     Player::Gauche()
{
  int   ret;

  std::cout << "je tourne a gauche" << std::endl;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "gauche\n", 7, 0);
  if (ret == -1)
    return (ERR);
  return (OK);
}

int   Player::Pond()
{
  int	ret;

  std::cout << "je pond" << std::endl;
  _cmd.push_back(FORK);
  ret = send(_soc, "fork\n", 5, 0);
  if (ret == -1)
    return (ERR);
  return (OK);
}

int   Player::Eclosion()
{
  PlayerCreator	pc;
  std::cout << "Eclosion" << std::endl;
  pc.create(_addr, _port, _teamName);
  return (OK);
}
