//
// TestBloc.cpp for Test in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:48:02 2012 alexandre haulotte
// Last update Fri Jun 15 09:48:55 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::_AssezNourriture()
{
  int   ret;

  std::cout << "_AssezNourriture" << std::endl;
  _nbCmd++;
  _cmd.push_back(LOOP_ASSEZ_FOOD);
  ret = send(_soc, "inventaire\n", 12, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopAssezNourriture()
{
  std::string   food;

  std::cout << "LoopAssezNourriture" << std::endl;
  std::cout << _lastRep << std::endl;
  food = _lastRep.substr(_lastRep.find("nourriture"), _lastRep.find(",") - _lastRep.find\
			 ("nourriture"));
  food.replace(food.find("nourriture "), 10, "");
  std::cout << strToInt(&food[0]) << std::endl;
  if (strToInt(&food[0]) > 10)
    {
      std::cout << "assez de bouf" << std::endl;
      return (OK);
    }
  return (KO);
}

int   Player::_AssezRessourceForLevel()
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

int   Player::_PlaceSurServeur()
{
  int   ret;

  std::cout << "PlaceServeur" << std::endl;
  _nbCmd++;
  _cmd.push_back(LOOP_CONNECT);
  ret = send(_soc, "connect_nbr\n", 12, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopPlaceSurServeur()
{
  std::cout << "LoopPlaceServeur : " << &_lastRep[0] << std::endl;
  if (strToInt(&_lastRep[0]) > 0)
    return (OK);
  return (KO);
}
