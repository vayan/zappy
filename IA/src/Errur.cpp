//
// Errur.cpp for Errur in /home/haulot_a//C++/AbstractVM
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Feb  7 11:58:38 2012 alexandre haulotte
// Last update Wed Jun  6 14:08:20 2012 alexandre haulotte
//

#include "Errur.hh"

Errur::Errur(const std::string msg)
  :_message(&msg[0])
{ }

const char * Errur::what() const throw()
{
  return (_message);
}
