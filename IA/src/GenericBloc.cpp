//
// BlocIA.cpp for BlocIA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 11:11:47 2012 alexandre haulotte
// Last update Fri Jun 15 17:55:01 2012 alexandre haulotte
//

#include	"Player.hh"
#include	"PlayerCreator.hh"
#include	"stdlib.h"

int   Player::Avance()
{
  int	ret;
  char          buff[8096 + 1];

  std::cout << "j'avance" << std::endl;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "avance\n", 7, 0);
// switch (_dir)
  //   {
  //   case NORD:
  //     _y++;
  //     break;
  //   case EST:
  //     _x++;
  //     break;
  //   case SUD:
  //     _y--;
  //     break;
  //   case OUEST:
  //     _x--;
  //     break;
  //   }
  if (ret == -1)
    return (ERR);
  ret = recv(_soc, buff, 8096, 0);
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::Droite()
{
  int   ret;
  char          buff[8096 + 1];

  std::cout << "je tourne a droite" << std::endl;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "droite\n", 7, 0);
  if (ret == -1)
    return (ERR);
  ret = recv(_soc, buff, 8096, 0);
  if (ret == -1)
    return (ERR);
  return (OK);
}

int     Player::Gauche()
{
  int   ret;
  char          buff[8096 + 1];

  std::cout << "je tourne a gauche" << std::endl;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "gauche\n", 7, 0);
  if (ret == -1)
    return (ERR);
  ret = recv(_soc, buff, 8096, 0);
  if (ret == -1)
    return (ERR);
  return (OK);
}

int   Player::Pond()
{
  int	ret;
  char          buff[8096 + 1];

  std::cout << "je pond" << std::endl;
  _cmd.push_back(FORK);
  ret = send(_soc, "fork\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = recv(_soc, buff, 8096, 0);
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

int	Player::Incantation()
{
  int	ret;
  char 	buff[8096 + 1];

  std::cout << "je m'éléve" << std::endl;
  _cmd.push_back(LOOP_I);
  ret = send(_soc, "incantation\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = recv(_soc, buff, 8096, 0);
  std::cout << "Incanter" << std::endl;
  _lastRep = &buff[0];
  if (_lastRep.find("elevation") != std::string::npos)
    {
      ret = recv(_soc, buff, 8096, 0);
      std::cout << "Lvl UP" << std::endl;
      _lastRep = &buff[0];
      if (_lastRep.find("niveau") != std::string::npos)
	{
	  for (int i = 0; i < 6; i++)
	    _ressource[i] = _ressource[i] - _lvlTab[_lvl][i + 1];
	  _lvl++;
	  return (OK);
	}
    }
  return (KO);
}
