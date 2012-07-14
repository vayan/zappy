//
// PlayerCreator.cpp for plCreator in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Jun 12 14:16:37 2012 alexandre haulotte
// Last update Sat Jul 14 10:48:07 2012 alexandre haulotte
//

#include	<iostream>
#include	<unistd.h>
#include 	<stdlib.h>
#include	"Errur.hh"
#include	"PlayerCreator.hh"
#include	"Player.hh"

int	PlayerCreator::create(std::string& ip, int port, std::string& teamName)
{
  int		pid;
  Player	* pl;

  pid = fork();
  if (pid == -1)
    throw (new Errur("Fork error"));
  if (pid == 0)
    {
      pl = new Player(port, ip, teamName);
      pl->play();
      exit(0);
    }
  return ( pid);
}

PlayerCreator::PlayerCreator() {}

PlayerCreator::~PlayerCreator() {}
