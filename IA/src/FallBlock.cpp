//
// TakeBloc.cpp for Take in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:47:15 2012 alexandre haulotte
// Last update Tue Jun 19 11:42:26 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::PoserNourriture()
{
  int   ret;

  std::cout << "PoseNouriture" << std::endl;
  ret = send(_soc, "pose nourriture\n", 17, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("ok") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::PoserLinemate()
{
  int   ret;

  ret = send(_soc, "pose linemate\n", 15, 0);
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

int   Player::PoserDeraumere()
{
  int   ret;

  ret = send(_soc, "pose deraumere\n", 16, 0);
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

int   Player::PoserSibure()
{
  int   ret;

  ret = send(_soc, "pose sibure\n", 13, 0);
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

int   Player::PoserMendiane()
{
  int   ret;

  ret = send(_soc, "pose mendiane\n", 15, 0);
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

int   Player::PoserPhiras()
{
  int   ret;

  ret = send(_soc, "pose phiras\n", 13, 0);
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

int   Player::PoserThystame()
{
  int   ret;

  ret = send(_soc, "pose thystame\n", 15, 0);
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

int   Player::PoserRessourceForLvl()
{
  std::cout << "PoserRessourceForLvl" << std::endl;
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
      ret = PoserLinemate();
      break;
    case DERAUMERE:
      ret = PoserDeraumere();
      break;
    case SIBURE:
      ret = PoserSibure();
      break;
    case MENDIANE:
      ret = PoserMendiane();
      break;
    case PHIRAS:
      ret = PoserPhiras();
      break;
    case THYSTAME:
      ret = PoserThystame();
      break;
    default:
      return (ERR);
    }
  return (ret);
}
