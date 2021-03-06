//
// PausableClock.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:07:59 2012 yuguo cao
// Last update Thu Jun 14 15:21:28 2012 yuguo cao
//

#ifndef		__PAUSABLECLOCK__
# define	__PAUSABLECLOCK__

#include	<SFML/System.hpp>

class PausableClock
{
private:
  sf::Clock	_clock;
  float		_time;
  bool		_isPaused;

public:
  PausableClock(bool p = false);
  ~PausableClock();

  void		Start();
  void		Pause();
  void		Reset(bool p = false);
  float		GetElapsedTime() const;
};

#endif
