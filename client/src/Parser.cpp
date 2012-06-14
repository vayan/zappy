//
// Parser.cpp for parser in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 13:57:49 2012 alexandre haulotte
// Last update Tue Jun 12 14:43:38 2012 alexandre haulotte
//

#include	<stdlib.h>
#include	<iostream>
#include	"Parser.hh"

std::vector<int>	Parser::parseThat(std::string str)
{
  int 			i, j = 0;
  std::vector<int> 	vec;
  char			buff[20];

  //idée map[cmd]...
  if (str.find("pnw") != std::string::npos)
    {
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
  return (vec);
}

Parser::Parser() {}

Parser::~Parser() {}