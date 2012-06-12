//
// PlayerCreator.cpp for plCreator in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 14:16:37 2012 alexandre haulotte
// Last update Tue Jun 12 14:50:42 2012 alexandre haulotte
//

#include	<iostream>
#include	<unistd.h>
#include	"Errur.hh"
#include	"PlayerCreator.hh"

int	PlayerCreator::create(std::vector<int> vec)
{
  int	pid;
  pid = fork();
  if (pid == -1)
    throw (new Errur("Fork error"));
  if (pid == 0)
    {

    }
  std::vector<int>::iterator it;
  for (it = vec.begin(); it != vec.end(); it++)
    {
      std::cout << (*it) << " ";
    }
  std::cout << std::endl;
  return (pid);
}

PlayerCreator::PlayerCreator() {}

PlayerCreator::~PlayerCreator() {}
