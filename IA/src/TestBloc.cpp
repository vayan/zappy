//
// TestBloc.cpp for Test in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:48:02 2012 alexandre haulotte
// Last update Wed Jun 20 12:43:37 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::AssezNourriture()
{
  int   ret;
  std::string   food;
  //  char          buff[8096 + 1];

  //  std::cout << "_AssezNourriture" << std::endl;
  ret = xsend(_soc, "inventaire\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  food = _lastRep.substr(_lastRep.find("nourriture"), _lastRep.find(",") - _lastRep.find("nourriture"));
  food.replace(food.find("nourriture "), 10, "");
  std::cout << strToInt(&food[0]) << std::endl;
  if (strToInt(&food[0]) > 10)
    return (OK);
  return (KO);
}

int   Player::AssezRessourceForLevel()
{
  //std::cout << "_AssezRessource" << std::endl;
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

  std::cout << "1 : PlaceServeur" << std::endl;
  ret = xsend(_soc, "connect_nbr\n", 12, 0);
  std::cout << "12 : PlaceServeur" << std::endl;
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
    std::cout << "2 : PlaceServeur" << std::endl;
  if (_lastRep.size() > 0)
    {
      std::cout << " 3 : PlaceServeur" << std::endl;
      if (strToInt(&_lastRep[0]) > 0)
	{
	  std::cout << "4 : PlaceServeur" << std::endl;
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
      //std::cout << "Assez Player ???? : " << nbP <<std::endl;
      if (nbP >= _lvlTab[_lvl][0])
	return (OK);
    }
  return (KO);
}
