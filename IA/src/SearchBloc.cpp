//
// SearchSurCase.cpp for searchBloc in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:33:05 2012 alexandre haulotte
// Last update Fri Jun 15 09:37:48 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::_NourritureSurCase()
{
  int   ret;

  std::cout << "NouritureSurCase" << std::endl;
  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopNourritureSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  std::cout << "LoopNouritureSurCase " << food << std::endl;
  if (food.find("nourriture") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::_LinemateSurCase()
{
  int   ret;

  std::cout << "RessourceSurCase" << std::endl;
  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopLinemateSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  if (_lvlTab[_lvl][1] > _ressource[LINEMATE]
      && food.find("linemate") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::_DeraumereSurCase()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopDeraumereSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  if (_lvlTab[_lvl][2] > _ressource[DERAUMERE]
      && food.find("deraumere") != std::string::npos)
    return (OK);
  return (KO);
}


int   Player::_SibureSurCase()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopSibureSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  if (_lvlTab[_lvl][3] > _ressource[SIBURE]
      && food.find("sibure") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::_MendianeSurCase()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopMendianeSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  if (_lvlTab[_lvl][4] > _ressource[MENDIANE]
      && food.find("mendiane") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::_PhirasSurCase()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopPhirasSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  if (_lvlTab[_lvl][5] > _ressource[PHIRAS]
      && food.find("phiras") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::_ThystameSurCase()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(LOOP_SEARCH_FOOD);
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopThystameSurCase()
{
  std::string   food;

  food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
  if (_lvlTab[_lvl][6] > _ressource[THYSTAME]
      && food.find("thystame") != std::string::npos)
    return (OK);
  return (KO);
}
