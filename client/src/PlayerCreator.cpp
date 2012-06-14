//
// PlayerCreator.cpp for plCreator in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 14:16:37 2012 alexandre haulotte
// Last update Wed Jun 13 12:44:58 2012 alexandre haulotte
//

#include	<iostream>
#include	<unistd.h>
#include 	<stdlib.h>
#include	"Errur.hh"
#include	"PlayerCreator.hh"
#include	"Player.hh"

int	PlayerCreator::create(std::vector<int> vec, std::string& ip, int port)
{
  int		pid;
  Player	pl(vec[2], vec[3], vec[4], vec[5], vec[1], ip, port);

  pid = fork();
  if (pid == -1)
    throw (new Errur("Fork error"));
  if (pid == 0)
    {
      pl.play();
      exit(0);
    }
  return (pid);
}

PlayerCreator::PlayerCreator() {}

PlayerCreator::~PlayerCreator() {}