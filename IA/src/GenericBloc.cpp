//
// BlocIA.cpp for BlocIA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 11:11:47 2012 alexandre haulotte
// Last update Thu Jun 21 17:31:01 2012 alexandre haulotte
//

#include	"Player.hh"
#include	"PlayerCreator.hh"
#include	"stdlib.h"

int   Player::Avance()
{
  int	ret;
  //  char          buff[8096 + 1];

  //  std::cout << _id << " : j'avance" << std::endl;
  ret = xsend(_soc, "avance\n", 7, 0);
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

  //  std::cout << _id << " : je tourne a droite" << std::endl;
  ret = xsend(_soc, "droite\n", 7, 0);
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

  //  std::cout << _id << " : je tourne a gauche" << std::endl;
  ret = xsend(_soc, "gauche\n", 7, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int     Player::Inventaire()
{
  int   ret;

  //std::cout << _id << " : je tourne a gauche" << std::endl;
  ret = xsend(_soc, "inventaire\n", 11, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int     Player::Voir()
{
  int   ret;

  //std::cout << _id << " : je tourne a gauche" << std::endl;
  ret = xsend(_soc, "voir\n", 5, 0);
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

  //std::cout << "je pond" << std::endl;
  ret = xsend(_soc, "fork\n", 5, 0);
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
  //std::cout << "Eclosion" << std::endl;
  pc.create(_addr, _port, _teamName);
  return (OK);
}

int	Player::Incantation()
{
  int	ret;

  ret = xsend(_soc, "incantation\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (_lastRep.find("elevation") != std::string::npos)
    {
      ret = xrecv();
      if (_lastRep.find("niveau") != std::string::npos)
	{
	  _lvl++;
	  std::cout << "je suis lvl: " << _lvl << std::endl;
	  return (OK);
	}
    }
  return (KO);
}

int	Player::GoToDir()
{
  //  std::cout << _id << " >>>>>>>GoToMsgRenfort direct : " << rDir << std::endl;
  switch (rDir)
    {
    case 1:
      Avance();
      break;
    case 2:
      Avance();
      Gauche();
      Avance();
      break;
    case 8:
      Avance();
      Droite();
      Avance();
      break;
    case 7:
      Droite();
      Avance();
      break;
    case 6:
      Droite();
      Avance();
      Droite();
      break;
    case 5:
      Gauche();
      Gauche();
      Avance();
      break;
    case 4:
      Gauche();
      Avance();
      Gauche();
      break;
    case 3:
      Gauche();
      Avance();
      break;
    default:
      return (OK);
    }
  rDir = 0;
  return (OK);
}

int	Player::VideCase()
{
  int           ret;
  std::string   food;

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{") + 2, _lastRep.find(",") - _lastRep.find("{") - 2);
      ret = OK;
      while (food.find("nourriture") != std::string::npos
	     || food.find("linemate") != std::string::npos
	     || food.find("deraumere") != std::string::npos
	     || food.find("sibur") != std::string::npos
	     || food.find("mendiane") != std::string::npos
	     || food.find("phiras") != std::string::npos
	     || food.find("thystame") != std::string::npos)
	{
	  //	  std::cout << "--------->" << food << std::endl;
	  if (food.find("nourriture") != std::string::npos)
	    {
	      food.replace(food.find(" nourriture"), 11, "");
	      RamassezNourriture();
	    }
	  if (food.find("linemate") != std::string::npos)
	    {
	      food.replace(food.find(" linemate"), 9, "");
	      RamassezLinemate();
	    }
	  if (food.find("deraumere") != std::string::npos)
	    {
	      food.replace(food.find(" deraumere"), 10, "");
	      RamassezDeraumere();
	    }
	  if (food.find("sibur") != std::string::npos)
	    {
	      food.replace(food.find(" sibur"), 6, "");
	      RamassezSibur();
	    }
	  if (food.find("mendiane") != std::string::npos)
	    {
	      food.replace(food.find(" mendiane"), 9, "");
	      RamassezMendiane();
	    }
	  if (food.find("phiras") != std::string::npos)
	    {
	      food.replace(food.find(" phiras"), 7, "");
	      RamassezPhiras();
	    }
	  if (food.find("thystame") != std::string::npos)
	    {
	      food.replace(food.find(" thystame"), 9, "");
	      RamassezThystame();
	    }
	}
    }
  return (OK);
}

int     Player::StopRenfort()
{
  isRenf = false;
  return (OK);
}
