//
// PausableClock.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:07:46 2012 yuguo cao
// Last update Thu Jun 14 15:36:21 2012 yuguo cao
//

#include	"PausableClock.hh"

PausableClock::PausableClock(bool p)
{
  _time = 0;
  _isPaused = p;
}

PausableClock::~PausableClock()
{

}

void		PausableClock::Start()
{
  if (!_isPaused)
    {
      _clock.Reset();
      _isPaused = false;
    }
}

void		PausableClock::Pause()
{
  if (!_isPaused)
    {
      _isPaused = true;
      _time += _clock.GetElapsedTime();
    }
}

void		PausableClock::Reset(bool p)
{
  _isPaused = p;
  _time = 0.0;
  _clock.Reset();
}

float		PausableClock::GetElapsedTime() const
{
  if (!_isPaused)
    return (_time + _clock.GetElapsedTime());
  return (_time);
}
