//
// BlocIA.cpp for BlocIA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 11:11:47 2012 alexandre haulotte
// Last update Tue Jun 19 12:00:57 2012 alexandre haulotte
//

#include	"Player.hh"
#include	"PlayerCreator.hh"
#include	"stdlib.h"

int   Player::Avance()
{
  int	ret;
  //  char          buff[8096 + 1];

  std::cout << "j'avance" << std::endl;
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
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::Droite()
{
  int   ret;

  std::cout << "je tourne a droite" << std::endl;
  ret = send(_soc, "droite\n", 7, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int     Player::Gauche()
{
  int   ret;

  std::cout << "je tourne a gauche" << std::endl;
  ret = send(_soc, "gauche\n", 7, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int   Player::Pond()
{
  int	ret;

  std::cout << "je pond" << std::endl;
  ret = send(_soc, "fork\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
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

  ret = send(_soc, "incantation\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (_lastRep.find("elevation") != std::string::npos)
    {
      ret = xrecv();
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

int	Player::GoToMsgRenfort()
{
  if (rDir == 1 || rDir == 2 || rDir == 8)
    Avance();
  else if (rDir == 7 || rDir == 6)
    {
      Droite();
      Avance();
    }
  else if (rDir == 3 || rDir == 4)
    {
      Gauche();
      Avance();
    }
  else if (rDir == 5)
    {
      Gauche();
      Gauche();
      Avance();
    }
  else
    return (OK);
  return (KO);
}

int	VideCase()
{
  int           ret;
  std::string   food;

  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
      ret = OK;
      while (ret == OK)
	{
	  ret = RamassezNourriture();
	  if (RamassezLinemate() == OK)
	    ret = OK;
	  if (RamassezDeraumere() == OK)
	    ret = OK;
	  if (RamassezSibure() == OK)
	    ret = OK;
	  if (RamassezMendiane() == OK)
	    ret = OK;
	  if (RamassezPhiras() == OK)
	    ret = OK;
	  if (RamassezThystame() == OK)
	    ret = OK;
	}
    }
  return (OK);
}
