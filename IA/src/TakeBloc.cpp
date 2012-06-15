//
// TakeBloc.cpp for Take in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:47:15 2012 alexandre haulotte
// Last update Fri Jun 15 12:04:05 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::_RamassezNourriture()
{
  int   ret;

  std::cout << "RammasseeNouriture" << std::endl;
  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend nourriture\n", 17, 0);
  if (ret == -1)
    return (ERR);
  return (LOOP);
}

int   Player::LoopRamassezNourriture()
{
  std::cout << "LoopRammasseeNouriture" << std::endl;
  if (_lastRep.find("ok") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::_RamassezLinemate()
{
  int   ret;

  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend linemate\n", 15, 0);
  RWant = LINEMATE;
  if (ret == -1)
    return (ERR);
  return (LOOP);
}

int   Player::_RamassezDeraumere()
{
  int   ret;

  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend deraumere\n", 16, 0);
  RWant = DERAUMERE;
  if (ret == -1)
    return (ERR);
  return (LOOP);
}

int   Player::_RamassezSibure()
{
  int   ret;

  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend sibure\n", 13, 0);
  RWant = SIBURE;
  if (ret == -1)
    return (ERR);
  return (LOOP);
}

int   Player::_RamassezMendiane()
{
  int   ret;

  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend mendiane\n", 15, 0);
  RWant = MENDIANE;
  if (ret == -1)
    return (ERR);
  return (LOOP);
}

int   Player::_RamassezPhiras()
{
  int   ret;

  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend phiras\n", 13, 0);
  RWant = PHIRAS;
  if (ret == -1)
    return (ERR);
  return (LOOP);
}

int   Player::_RamassezThystame()
{
  int   ret;

  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend thystame\n", 15, 0);
  RWant = THYSTAME;
  if (ret == -1)
    return (ERR);
  return (LOOP);
}
//-----------------Fct Ressource for lvl-----------------------//
int   Player::_RamassezRessourceForLvl()
{
  int   ret;
  int	i;

  for (i = 0; i < 6; i++)
    {
      if (_lvlTab[_lvl][i + 1] > _ressource[i])
	break;
    }
  switch (i)
    {
    case LINEMATE:
      ret = _RamassezLinemate();
      break;
    case DERAUMERE:
      ret = _RamassezDeraumere();
      break;
    case SIBURE:
      ret = _RamassezSibure();
      break;
    case MENDIANE:
      ret = _RamassezMendiane();
      break;
    case PHIRAS:
      ret = _RamassezPhiras();
      break;
    case THYSTAME:
      ret = _RamassezThystame();
      break;
    default:
      return (ERR);
    }
  return (ret);
}

int   Player::LoopRamassezRessource()
{
  if (_lastRep.find("ok") != std::string::npos)
    {
      _ressource[RWant] = _ressource[RWant] + 1;
      return (OK);
    }
  return (KO);
}
