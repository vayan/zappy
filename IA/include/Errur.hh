//
// Errur.hpp for Errur in /home/haulot_a//C++/AbstractVM
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue Feb  7 11:47:43 2012 alexandre haulotte
// Last update Tue Feb  7 15:08:09 2012 alexandre haulotte
//

#ifndef	__ERRUR_HH__
#define	__ERRUR_HH__

#include        <string>
#include        <stdexcept>

class   Errur : public std::exception
{
public:
  ~Errur() throw() {}
  Errur(std::string msg);
  const char * what() const throw();

private:
  const char *        _message;
};

#endif
