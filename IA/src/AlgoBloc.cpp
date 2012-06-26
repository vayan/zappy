//
// AlgoBloc.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 21 09:47:33 2012 alexandre haulotte
// Last update Tue Jun 26 10:24:13 2012 alexandre haulotte
//

#include	"Player.hh"

int	Player::While5()
{
  static int	loop = 0;
  loop++;
  if (loop < 5)
    return (LOOP);
  loop = 0;
  return (OK);
}

int	Player::While10()
{
  static int	loop = 0;
  loop++;
  if (loop < 10)
    return (LOOP);
  loop = 0;
  return (OK);
}

int     Player::IfIsRenf()
{
  if (isRenf)
    return (OK);
  return (KO);
}

int     Player::IfFoodSup10()
{
  int   ret;
  std::string   food;
  //  char          buff[8096 + 1];

  //  std::cout << "_AssezNourriture" << std::endl;
  ret = xsend(_soc, "inventaire\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("nourriture") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("nourriture"), _lastRep.find(",") - _lastRep.find("nourriture"));
      food.replace(food.find("nourriture "), 10, "");
      if (strToInt(&food[0]) > 10)
	return (OK);
    }
  return (KO);
}

int     Player::IfFoodSup5()
{
  int   ret;
  std::string   food;
  //  char          buff[8096 + 1];

  //  std::cout << "_AssezNourriture" << std::endl;
  ret = xsend(_soc, "inventaire\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("nourriture") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("nourriture"), _lastRep.find(",") - _lastRep.find("nourriture"));
      food.replace(food.find("nourriture "), 10, "");
      if (strToInt(&food[0]) > 5)
	return (OK);
    }
  return (KO);
}

int     Player::IfFoodSup30()
{
  int   ret;
  std::string   food;
  //  char          buff[8096 + 1];

  //  std::cout << "_AssezNourriture" << std::endl;
  ret = xsend(_soc, "inventaire\n", 12, 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  if (_lastRep.find("nourriture") != std::string::npos)
    {
      food = _lastRep.substr(_lastRep.find("nourriture"), _lastRep.find(",") - _lastRep.find("nourriture"));
      food.replace(food.find("nourriture "), 10, "");
      if (strToInt(&food[0]) > 30)
	return (OK);
    }
  return (KO);
}
