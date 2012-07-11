//
// SearchSurCase.cpp for searchBloc in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:33:05 2012 alexandre haulotte
// Last update Wed Jul 11 14:56:50 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::SearchNourriture()
{
  int   			ret;
  std::vector<std::string>	food;

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchNourriture1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchNourriture2" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "nourriture"));
    }
  return (KO);
}

int   Player::SearchLinemate()
{
  int   ret;
  std::vector<std::string>	food;

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchLine1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchLine2" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "linemate"));
    }
  return (KO);
}

int   Player::SearchDeraumere()
{
  int   ret;
  std::vector<std::string>	food;

   ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchDerau1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchDerau1" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "deraumere"));
    }
  return (KO);
}


int   Player::SearchSibur()
{
  int   ret;
  std::vector<std::string>	food;

   ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchSib1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchSib2" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "sibur"));
    }
  return (KO);
}

int   Player::SearchMendiane()
{
  int   ret;
  std::vector<std::string>	food;

   ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchMend1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchMend2" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "mendiane"));
    }
  return (KO);
}

int   Player::SearchPhiras()
{
  int   ret;
  std::vector<std::string>	food;

   ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchPhi1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchPhi2" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "phiras"));
    }
  return (KO);
}

int   Player::SearchThystame()
{
  int   ret;
  std::vector<std::string>	food;

   ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      // std::cout << "SearchThy1" << std::endl;
      _lastRep.replace(_lastRep.find("{"), 1, "");
      // std::cout << "SearchThy2" << std::endl;
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      return (searchDir(food, "thystame"));
    }
  return (KO);
}

int   Player::SearchRessourceForLvl()
{
  int   ret;
  std::vector<std::string>	food;

  ret = xsend(_soc, "voir\n", 5, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("{") != std::string::npos)
    {
      _lastRep.replace(_lastRep.find("{"), 1, "");
      _lastRep.replace(_lastRep.find("}"), 1, "");
      food = split_to_vec(_lastRep, ",");
      if (_lvlTab[_lvl][1] <= _ressource[LINEMATE]
	  && _lvlTab[_lvl][2] <= _ressource[DERAUMERE]
	  && _lvlTab[_lvl][3] <= _ressource[SIBUR]
	  && _lvlTab[_lvl][4] <= _ressource[MENDIANE]
	  && _lvlTab[_lvl][5] <= _ressource[PHIRAS]
	  && _lvlTab[_lvl][6] <= _ressource[THYSTAME])
	return (ALREADY);
      if ((_lvlTab[_lvl][1] > _ressource[LINEMATE]
	   && searchDir(food, "linemate") == OK)
	  || (_lvlTab[_lvl][2] > _ressource[DERAUMERE]
	      && searchDir(food, "deraumere") == OK)
	  || (_lvlTab[_lvl][3] > _ressource[SIBUR]
	      && searchDir(food, "sibur") == OK)
	  || (_lvlTab[_lvl][4] > _ressource[MENDIANE]
	      && searchDir(food, "mendiane") == OK)
	  || (_lvlTab[_lvl][5] > _ressource[PHIRAS]
	      && searchDir(food, "phiras") == OK)
	  || (_lvlTab[_lvl][6] > _ressource[THYSTAME]
	      && searchDir(food, "thystame") == OK))
	return (OK);
      else if (_lvlTab[_lvl][1] > _ressource[LINEMATE]
	       && searchDir(food, "linemate") == GODIR)
	  return (searchDir(food, "linemate"));
      else if (_lvlTab[_lvl][1] > _ressource[DERAUMERE]
	       && searchDir(food, "deraumere") == GODIR)
	return (searchDir(food, "deraumere"));
      else if (_lvlTab[_lvl][1] > _ressource[SIBUR]
	       && searchDir(food, "sibur") == GODIR)
	return (searchDir(food, "sibur"));
      else if (_lvlTab[_lvl][1] > _ressource[MENDIANE]
	       && searchDir(food, "mendiane") == GODIR)
	return (searchDir(food, "mendiane"));
      else if (_lvlTab[_lvl][1] > _ressource[PHIRAS]
	       && searchDir(food, "phiras") == GODIR)
	return (searchDir(food, "phiras"));
      else if (_lvlTab[_lvl][1] > _ressource[THYSTAME]
	       && searchDir(food, "thystame") == GODIR)
	return (searchDir(food, "thystame"));
    }
  return (KO);
}
