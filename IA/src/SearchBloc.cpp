//
// SearchSurCase.cpp for searchBloc in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:33:05 2012 alexandre haulotte
// Last update Fri Jun 15 19:34:29 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::NourritureSurCase()
{
  int   	ret;
  std::string   food;

  std::cout << "NouritureSurCase" << std::endl;
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
      std::cout << "LoopNouritureSurCase " << food << std::endl;
      if (food.find("nourriture") != std::string::npos)
	return (OK);
    }
  return (KO);
}

int   Player::LinemateSurCase()
{
  int   ret;
  std::string   food;

  std::cout << "RessourceSurCase" << std::endl;
  ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{"), _lastRep.find(",") - _lastRep.find("{"));
      if (food.find("linemate") != std::string::npos)
	return (OK);
    }
  return (KO);
}

int   Player::DeraumereSurCase()
{
  int   ret;
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
      if (food.find("deraumere") != std::string::npos)
	return (OK);
    }
  return (KO);
}


int   Player::SibureSurCase()
{
  int   ret;
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
      if (food.find("sibure") != std::string::npos)
	return (OK);
    }
  return (KO);
}

int   Player::MendianeSurCase()
{
  int   ret;
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
      if (food.find("mendiane") != std::string::npos)
	return (OK);
    }
  return (KO);
}

int   Player::PhirasSurCase()
{
  int   ret;
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
      if (food.find("phiras") != std::string::npos)
	return (OK);
    }
  return (KO);
}

int   Player::ThystameSurCase()
{
  int   ret;
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
      if (food.find("thystame") != std::string::npos)
	return (OK);
    }
  return (KO);
}

int   Player::RessourceForLvlSurCase()
{
  int   ret;
  std::string   food;

  std::cout << "RessourceForLvlSurCase : Level = " << _lvl << std::endl;
   ret = send(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("{") + 1, _lastRep.find(",") - _lastRep.find("{"));
      if ((_lvlTab[_lvl][1] > _ressource[LINEMATE]
	   && food.find("linemate") != std::string::npos)
	  || (_lvlTab[_lvl][2] > _ressource[DERAUMERE]
	      && food.find("deraumere") != std::string::npos)
	  || (_lvlTab[_lvl][3] > _ressource[SIBURE]
	      && food.find("sibure") != std::string::npos)
	  || (_lvlTab[_lvl][4] > _ressource[MENDIANE]
	      && food.find("mendiane") != std::string::npos)
	  || (_lvlTab[_lvl][5] > _ressource[PHIRAS]
	      && food.find("phiras") != std::string::npos)
	  || (_lvlTab[_lvl][6] > _ressource[THYSTAME]
	      && food.find("thystame") != std::string::npos))
	return (OK);
      if (_lvlTab[_lvl][1] <= _ressource[LINEMATE]
	  && _lvlTab[_lvl][2] <= _ressource[DERAUMERE]
	  && _lvlTab[_lvl][3] <= _ressource[SIBURE]
	  && _lvlTab[_lvl][4] <= _ressource[MENDIANE]
	  && _lvlTab[_lvl][5] <= _ressource[PHIRAS]
	  && _lvlTab[_lvl][6] <= _ressource[THYSTAME])
	return (ALREADY);
    }
  return (KO);
}
