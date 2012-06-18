//
// TakeBloc.cpp for Take in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:47:15 2012 alexandre haulotte
// Last update Fri Jun 15 19:36:17 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::RamassezNourriture()
{
  int   ret;

  std::cout << "RamasseeNouriture" << std::endl;
  ret = send(_soc, "prend nourriture\n", 17, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::RamassezLinemate()
{
  int   ret;

  ret = send(_soc, "prend linemate\n", 15, 0);
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

  ret = send(_soc, "prend deraumere\n", 16, 0);
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

int   Player::RamassezSibure()
{
  int   ret;

  ret = send(_soc, "prend sibure\n", 13, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[SIBURE] = _ressource[SIBURE] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezMendiane()
{
  int   ret;

  ret = send(_soc, "prend mendiane\n", 15, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[SIBURE] = _ressource[SIBURE] + 1;
      return (OK);
    }
  return (KO);
}

int   Player::RamassezPhiras()
{
  int   ret;

  ret = send(_soc, "prend phiras\n", 13, 0);
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

  ret = send(_soc, "prend thystame\n", 15, 0);
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
  std::cout << "RamassezRessourceForLvl" << std::endl;
  int   ret;
  int	i;

  for (i = 1; i < 6; i++)
    {
      if (_lvlTab[_lvl][i] > _ressource[i])
	break;
      if (i == 6)
	return (OK);
    }
  switch (i)
    {
    case LINEMATE:
      ret = RamassezLinemate();
      break;
    case DERAUMERE:
      ret = RamassezDeraumere();
      break;
    case SIBURE:
      ret = RamassezSibure();
      break;
    case MENDIANE:
      ret = RamassezMendiane();
      break;
    case PHIRAS:
      ret = RamassezPhiras();
      break;
    case THYSTAME:
      ret = RamassezThystame();
      break;
    default:
      return (ERR);
    }
  return (ret);
}
