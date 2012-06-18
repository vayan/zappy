//
// TestBloc.cpp for Test in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:48:02 2012 alexandre haulotte
// Last update Fri Jun 15 19:32:15 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::AssezNourriture()
{
  int   ret;
  std::string   food;
  //  char          buff[8096 + 1];

  std::cout << "_AssezNourriture" << std::endl;
  ret = send(_soc, "inventaire\n", 12, 0);
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
  std::cout << "_AssezRessource" << std::endl;
  if (_lvlTab[_lvl][1] > _ressource[LINEMATE]
      || _lvlTab[_lvl][2] > _ressource[DERAUMERE]
      || _lvlTab[_lvl][3] > _ressource[SIBURE]
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

  std::cout << "PlaceServeur" << std::endl;
  ret = send(_soc, "connect_nbr\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (strToInt(&_lastRep[0]) > 0)
    return (OK);
  return (KO);
}
