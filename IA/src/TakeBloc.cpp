//
// TakeBloc.cpp for Take in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:47:15 2012 alexandre haulotte
// Last update Thu Jul 12 15:11:25 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::RamassezNourriture()
{
  int   ret;

  //// std::cout << "PrendNouriture" << std::endl;
  ret = xsend(_soc, "prend nourriture\n", 17, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::RamassezAllNourriture()
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
      while (food.find("nourriture") != std::string::npos)
	{
	  //std::cout << "RamassezAllNourriture" << std::endl;
	  food.replace(food.find("nourriture"), 10, "");
	  ret = RamassezNourriture();
	  if (ret == KO)
	    return (KO);
	}
      return (OK);
    }
  return (KO);
}

int   Player::RamassezLinemate()
{
  int   ret;

  ret = xsend(_soc, "prend linemate\n", 15, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[LINEMATE] = _ressource[LINEMATE] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezDeraumere()
{
  int   ret;

  ret = xsend(_soc, "prend deraumere\n", 16, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[DERAUMERE] = _ressource[DERAUMERE] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezSibur()
{
  int   ret;

  ret = xsend(_soc, "prend sibur\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[SIBUR] = _ressource[SIBUR] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezMendiane()
{
  int   ret;

  ret = xsend(_soc, "prend mendiane\n", 15, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[MENDIANE] = _ressource[MENDIANE] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezPhiras()
{
  int   ret;

  ret = xsend(_soc, "prend phiras\n", 13, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[PHIRAS] = _ressource[PHIRAS] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezThystame()
{
  int   ret;

  ret = xsend(_soc, "prend thystame\n", 15, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[THYSTAME] = _ressource[THYSTAME] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezRessourceForLvl()
{
  //// std::cout << "RamassezRessourceForLvl" << std::endl;
  int   ret = KO;
  int   ret2;
  int	i;
  std::string      food;

  ret2 = xsend(_soc, "voir\n", 5, 0);
  if (ret2 == -1)
    return (ERR);
  ret2 = xrecv();
  if (ret2 == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{") + 1, _lastRep.find(",") - _lastRep.find("{") + 1);
      for (i = 1; i < 6; i++)
        {
          if (_lvlTab[_lvl][i] > _ressource[i])
	    {
	      switch (i)
		{
		case LINEMATE:
		  if (food.find("linemate") != std::string::npos)
		    ret = RamassezLinemate();
		  break;
		case DERAUMERE:
		  if (food.find("deraumere") != std::string::npos)
		    ret = RamassezDeraumere();
		  break;
		case SIBUR:
		  if (food.find("sibur") != std::string::npos)
		  ret = RamassezSibur();
		  break;
		case MENDIANE:
		  if (food.find("mendiane") != std::string::npos)
		  ret = RamassezMendiane();
		  break;
		case PHIRAS:
		  if (food.find("phiras") != std::string::npos)
		  ret = RamassezPhiras();
		  break;
		case THYSTAME:
		  if (food.find("thystame") != std::string::npos)
		  ret = RamassezThystame();
		  break;
		default:
		  return (ERR);
		}
	    }
	}
    }
  return (ret);
}
