//
// Animation.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client/src
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:32:31 2012 yuguo cao
// Last update Fri Jun 15 11:42:15 2012 yuguo cao
//

#include "Animation.hh"

Animation::Animation(void) : _clock()
{
  _aFrame = 0;
  _delay = 0.0;
  _isLoop = true;
  _isPlaying = true;
  //_isOneFramed = false;
}

Animation::~Animation(void)
{
}

void		Animation::nextFrame()
{
  if(_aFrame == getSize() - 1)
    {
      setFrame(0);
      if(!_isLoop)
	stop();
    }
  else
    _aFrame += 1;
}

void		Animation::setFrame(const unsigned int& f)
{
  if(f < getSize())
    _aFrame = f;
  else
    _aFrame = 0;
}

void		Animation::reset()
{
  stop();
  play();
}

void		Animation::setLoop(const bool& choice)
{
  _isLoop=choice;
}


bool		Animation::getLoop() const
{
  return _isLoop;
}

// void                  setOneFrame(const bool& of)
// {
//   _isOneFramed = of;
// }

// bool                  getOneFrame()
// {
//   return (_isOneFramed);
// }

void		Animation::play()
{
  _isPlaying = true;
  _clock.Start();
}

void		Animation::stop()
{
  _isPlaying = false;
  _aFrame = 0;
  _clock.Reset(true);
}

void		Animation::pause()
{
  _isPlaying = false;
  _clock.Pause();
}

bool		Animation::getIsPlaying() const
{
  return _isPlaying;
}

void		Animation::setDelay(const float& d)
{
  _delay = d;
}

float		Animation::getDelay() const
{
  return _delay;
}

unsigned int	Animation::getActualFrame() const
{
  return _aFrame;
}

void		Animation::update()
{
  unsigned int	frameCount;

  if(_isPlaying)
    {
      if(_delay)
	{
	  frameCount = (unsigned int)(_clock.GetElapsedTime() / _delay);
	  if(!_isLoop && frameCount > getSize())
	    stop();
	  else
	    {
	      frameCount = frameCount % getSize();
	      _aFrame = frameCount;
	    }
	}
      else nextFrame();
    }
}
