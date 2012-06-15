//
// TakeBloc.cpp for Take in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 09:47:15 2012 alexandre haulotte
// Last update Fri Jun 15 09:47:44 2012 alexandre haulotte
//

#include	"Player.hh"

int   Player::RamassezNourriture()
{
  int   ret;

  std::cout << "RamassezNourriture" << std::endl;
  _nbCmd++;
  _cmd.push_back(LOOP_PRENDRE_FOOD);
  ret = send(_soc, "prend nourriture\n", 17, 0);
  if (ret == -1)
    return (KO);
  return (LOOP);
}

int   Player::LoopRamassezNourriture()
{
  std::cout << "LoopRamassezNourriture : " << _lastRep << std::endl;
  if (_lastRep.find("ok") != std::string::npos)
    return (OK);
  return (KO);
}
