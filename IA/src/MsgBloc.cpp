//
// MsgBloc.cpp for MsgBloc in /home/haulot_a//zappy-2015-2014s-haulot_a/IA/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri Jun 15 18:50:57 2012 alexandre haulotte
// Last update Thu Jul 12 17:15:35 2012 alexandre haulotte
//

#include	"Player.hh"

int	Player::CallRenfort()
{
  int   ret;

  //  // std::cout << "Renfort!!!!!!!!!" << std::endl;
  std::string str = "broadcast xxrenfortxx" + intToStr(_lvl) + "\n";
  ret = xsend(_soc, &str[0], str.size(), 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::CallJGLR()
{
  int   ret;

  //  // std::cout << "Renfort!!!!!!!!!" << std::endl;
  std::string str = "broadcast xxjglrxx\n";
  ret = xsend(_soc, &str[0], str.size(), 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::RecvRenfort()
{
  Voir();
  std::vector<std::string>::reverse_iterator	it;
  int	rfLvl;
  if (!_msg.empty())
    {
      for (it = _msg.rbegin(); it != _msg.rend(); it++)
	{
	  if ((*it).find("xxrenfortokxx") != std::string::npos && isRenf)
	    {
	      rDir = (*it)[8] - '0';
	      rfLvl = strToInt(&((*it).substr((*it).find("xxrenfortokxx") + 13, (*it).find("xxrenfortxx") + 14))[0]);
	      if (rfLvl == _lvl)
		{
		  _msg.clear();
		  if (rDir == 0)
		    return (OK);
		  return (GODIR);
		}
	    }
	  else if ((*it).find("xxrenfortokxx") != std::string::npos)
	    {
	      rfLvl = strToInt(&((*it).substr((*it).find("xxrenfortokxx") + 13, (*it).find("xxrenfortxx") + 14))[0]);
	      if (rfLvl == _lvl)
		{
		  _msg.clear();
		  return (KO);
		}
	    }
	  if ((*it).find("xxrenfortxx") != std::string::npos)
	    {
	      rDir = (*it)[8] - '0';
	      rfLvl = strToInt(&((*it).substr((*it).find("xxrenfortxx") + 11, (*it).find("xxrenfortxx") + 12))[0]);
	      if (rfLvl == _lvl)
		{
		  _msg.clear();
		  if (rDir == 0)
		    return (OK);
		  return (GODIR);
		}
	    }
	}
    }
  _msg.clear();
  return (KO);
}

int	Player::RecvJGLR()
{
  Voir();
  std::vector<std::string>::reverse_iterator	it;

  if (!_msg.empty())
    {
      for (it = _msg.rbegin(); it != _msg.rend(); it++)
	{
	  if ((*it).find("xxjglrxx") != std::string::npos)
	    {
	      rDir = (*it)[8] - '0';
	      _msg.clear();
	      return (OK);
	    }
	}
    }
  _msg.clear();
 return (KO);
}

int	Player::CallArrive()
{
  int   ret;

  // std::cout << _id << " : Jarrive!!!!!!!!!" << std::endl;
  std::string str = "broadcast xxJarrivexx" + intToStr(_lvl) + "\n";
  ret = xsend(_soc, &str[0], str.size(), 0);
  isRenf = true;
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::CallRenfortOK()
{
  int   ret;

  //  // std::cout << "Renfort!!!!!!!!!" << std::endl;
  std::string str = "broadcast xxrenfortokxx" + intToStr(_lvl) + "\n";
  ret = xsend(_soc, &str[0], str.size(), 0);
  if (ret == -1)
    return (ERR);
  ret = xrecv();
  if (ret == -1)
    return (ERR);
  return (OK);
}

int	Player::RecvArrive()
{
  Voir();
  std::vector<std::string>::reverse_iterator	it;
  std::string str = "xxJarrivexx" + intToStr(_lvl);

  if (!_msg.empty())
    {
      for (it = _msg.rbegin(); it != _msg.rend(); it++)
	{
	  if ((*it).find(str) != std::string::npos)
	    {
	      _nbRenf++;
	    }
	}
      _msg.clear();
      // std::cout << _id << " : " << _nbRenf << std::endl;
      if (_nbRenf >= _lvlTab[_lvl][0])
	{
	  _nbRenf = 1;
	  return (OK);
	}
    }
  _msg.clear();
  return (KO);
}

int	Player::GetSpam()
{
  Voir();
  std::vector<std::string>::reverse_iterator	it;
  std::string str = "xx";

  if (!_msg.empty())
    {
      for (it = _msg.rbegin(); it != _msg.rend(); it++)
	{
	  if ((*it).find(str) == std::string::npos)
	    {
	      _spam = (*it);
	      _msg.clear();
	      return (OK);
	      break;
	    }
	}
      _msg.clear();
    }
  return (KO);
}

int	Player::Spam()
{
  int   ret;

  //  // std::cout << "Renfort!!!!!!!!!" << std::endl;
  if (_spam != "")
    {
      std::string str = "broadcast " + _spam + "\n";
      ret = xsend(_soc, &str[0], str.size(), 0);
      if (ret == -1)
	return (ERR);
      ret = xrecv();
      if (ret == -1)
	return (ERR);
      return (OK);
    }
  return (KO);
}
