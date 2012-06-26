//
// Parser.cpp for parser in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 13:57:49 2012 alexandre haulotte
// Last update Fri Jun 22 14:02:42 2012 yuguo cao
//

#include	<stdlib.h>
#include	<iostream>
#include	"Parser.hh"

Parser::Parser()
{
}

Parser::~Parser()
{
}

std::vector<int>	Parser::parse(std::string str)
{
  int 			i, j = 0;
  std::vector<int> 	vec;
  char			buff[20];

  if (str.find("msz") == 0)
    vec.push_back(0);
  else if (str.find("bct") == 0)
    vec.push_back(1);
  else if (str.find("tna") == 0)
    vec.push_back(2);
  else if (str.find("pnw") == 0)
    vec.push_back(3);
  else if (str.find("ppo") == 0)
    vec.push_back(4);
  else if (str.find("plv") == 0)
    vec.push_back(5);
  else if (str.find("pin") == 0)
    vec.push_back(6);
  else if (str.find("pex") == 0)
    vec.push_back(7);
  else if (str.find("pbc") == 0)
    vec.push_back(8);
  else if (str.find("pic") == 0)
    vec.push_back(9);
  else if (str.find("pie") == 0)
    vec.push_back(10);
  else if (str.find("pfk") == 0)
    vec.push_back(11);
  else if (str.find("pdr") == 0)
    vec.push_back(12);
  else if (str.find("pgt") == 0)
    vec.push_back(13);
  else if (str.find("pdi") == 0)
    vec.push_back(14);
  else if (str.find("enw") == 0)
    vec.push_back(15);
  else if (str.find("eht") == 0)
    vec.push_back(16);
  else if (str.find("ebo") == 0)
    vec.push_back(17);
  else if (str.find("edi") == 0)
    vec.push_back(18);
  else if (str.find("sgt") == 0)
    vec.push_back(19);
  else if (str.find("seg") == 0)
    vec.push_back(20);
  else if (str.find("smg") == 0)
    vec.push_back(21);
  else if (str.find("suc") == 0)
    vec.push_back(22);
  else if (str.find("sbp") == 0)
    vec.push_back(23);
  else
    {
      vec.push_back(-1);
      return (vec);
    }
  str.erase(0, 4);
  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i] && str[i] != ' ' && j < 20)
	{
	  buff[j] = str[i];
	  j++;
	  i++;
	}
      buff[j] = '\0';
      vec.push_back(atoi(buff));
      if (str[i])
	i++;
    }
  return (vec);
}
