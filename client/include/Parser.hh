//
// Parser.hh for parser in /home/haulot_a//zappy-2015-2014s-haulot_a/client
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 13:44:59 2012 alexandre haulotte
// Last update Tue Jun 26 15:06:14 2012 yuguo cao
//

#ifndef	__PARSER_HH__
#define	__PARSER_HH__

#include	<vector>
#include	<string>

class Parser
{
public:
  Parser();
  ~Parser();

  std::vector<std::string>	parse(std::string str);
};

#endif
