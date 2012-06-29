//
// TestBloc.cpp for Test in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:48:02 2012 alexandre haulotte
// Last update Fri Jun 29 11:22:33 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::AssezRessourceForLvl()
{
  //std::cout << _id << " : _AssezRessource" << std::endl;
  if (_lvlTab[_lvl][1] > _ressource[LINEMATE]
      || _lvlTab[_lvl][2] > _ressource[DERAUMERE]
      || _lvlTab[_lvl][3] > _ressource[SIBUR]
      || _lvlTab[_lvl][4] > _ressource[MENDIANE]
      || _lvlTab[_lvl][5] > _ressource[PHIRAS]
      || _lvlTab[_lvl][6] > _ressource[THYSTAME])
    return (KO);
  return (OK);
}

int   Player::PlaceSurServeur()
{
  int   ret;
  std::string   food;

  ret = xsend(_soc, "connect_nbr\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.size() > 0)
    {
      if (strToInt(&_lastRep[0]) > 0)
	{
	  return (OK);
	}
    }
  return (KO);
}

int	Player::AssezPlayerForLvl()
{
  int           ret;
  std::string   food;
  int	nbP = 0;

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
      while (food.find("joueur") != std::string::npos)
	{
	  food.replace(food.find("joueur"), 6, "");
	  nbP++;
	}
      // std::cout << "Player demander : " << _lvlTab[_lvl][0] <<std::endl;
      if (nbP >= _lvlTab[_lvl][0])
	{
	  //std::cout << _id << " | Player sur case : " << nbP <<std::endl;
	  return (OK);
	}
    }
  return (KO);
}

int	Player::CaseReady()
{
  int           ret;
  std::string   food;
  int   nbP[] = {0, 0, 0, 0, 0, 0, 0};

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
      while (food.find("joueur") != std::string::npos
	     || food.find("linemate") != std::string::npos
	     || food.find("deraumere") != std::string::npos
	     || food.find("sibur") != std::string::npos
	     || food.find("mendiane") != std::string::npos
	     || food.find("phiras") != std::string::npos
	     || food.find("thystame") != std::string::npos)
	{
	  if (food.find("joueur") != std::string::npos)
	    {
	      food.replace(food.find("joueur"), 6, "");
	      nbP[0]++;
	    }
	  if (food.find("linemate") != std::string::npos)
	    {
	      food.replace(food.find("linemate"), 8, "");
	      nbP[1]++;
	    }
	  if (food.find("deraumere") != std::string::npos)
	    {
	      food.replace(food.find("deraumere"), 9, "");
	      nbP[2]++;
	    }
	  if (food.find("sibur") != std::string::npos)
	    {
	      food.replace(food.find("sibur"), 5, "");
	      nbP[3]++;
	    }
	  if (food.find("mendiane") != std::string::npos)
	    {
	      food.replace(food.find("mendiane"), 8, "");
	      nbP[4]++;
	    }
	  if (food.find("phiras") != std::string::npos)
	    {
	      food.replace(food.find("phiras"), 6, "");
	      nbP[5]++;
	    }
	  if (food.find("thystame") != std::string::npos)
	    {
	      food.replace(food.find(" thystame"), 8, "");
	      nbP[6]++;
	    }
	  if (_lvlTab[_lvl][0] == nbP[0]
	      && _lvlTab[_lvl][1] == nbP[LINEMATE]
	      && _lvlTab[_lvl][2] == nbP[DERAUMERE]
	      && _lvlTab[_lvl][3] == nbP[SIBUR]
	      && _lvlTab[_lvl][4] == nbP[MENDIANE]
	      && _lvlTab[_lvl][5] == nbP[PHIRAS]
	      && _lvlTab[_lvl][6] == nbP[THYSTAME])
	    {
	      return (OK);
	    }
	}
     }
  return (KO);
}

int	Player::JoueurSurCase()
{
  int           ret;
  std::string   food;
  int	nbP = 0;

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
      while (food.find("joueur") != std::string::npos)
	{
	  food.replace(food.find("joueur"), 6, "");
	  nbP++;
	}
      if (nbP > 1)
	{
	  return (OK);
	}
    }
  return (KO);
}

int	Player::GPondu()
{
  if (gPondu == true)
    return (OK);
  return (KO);
}
