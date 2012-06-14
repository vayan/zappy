//
// BlocIA.cpp for BlocIA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 11:11:47 2012 alexandre haulotte
// Last update Thu Jun 14 12:56:52 2012 alexandre haulotte
//

#include	"Player.hh"
#include	"PlayerCreator.hh"

int   Player::Avance()
{
  int	ret;

  _nbCmd++;
  _cmd.push_back(AVANCE);
  ret = send(_soc, "avance\n", 7, 0);
  if (ret == -1)
    return (KO);
  return (OK);
}

int   Player::Pond()
{
  int	ret;

  _nbCmd++;
  _cmd.push_back(FORK);
  ret = send(_soc, "fork\n", 5, 0);
  if (ret == -1)
    return (KO);
  return (OK);
}

int   Player::RamassezNouriture()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(PRENDRE_FOOD);
  ret = send(_soc, "prend nourriture\n", 17, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopRamassezNouriture()
{
  if (_lastRep.find("OK") != std::string::npos)
    return (OK);
  return (KO);
}

int   Player::Eclosion()
{
  PlayerCreator	pc;

  pc.create(_addr, _port, _teamName);
  return (OK);
}

int   Player::_AssezNouriture()
{
  if (_ressource[FOOD] >= 2)
    return (OK);
  else
    return (KO);
}

int   Player::_NouritureSurCase()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(VOIR);
  ret = send(_soc, "voir\n", 12, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopNouritureSurCase()
{
  std::string	food;

  food = _lastRep.substr(_lastRep.find("nouriture"));
  food.replace(0, 10, "");
  if (strToInt(&food[0]) > 0)
    return (OK);
  return (KO);
}


int   Player::_PlaceSurServeur()
{
  int   ret;

  _nbCmd++;
  _cmd.push_back(CONNECT);
  ret = send(_soc, "connect_nbr\n", 12, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopPlaceSurServeur()
{
  if (strToInt(&_lastRep[0]) > 0)
      return (OK);
  return (KO);
}
