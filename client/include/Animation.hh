//
// Animation.hh for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client/include
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 14:32:44 2012 yuguo cao
// Last update Fri Jun 15 11:29:04 2012 yuguo cao
//

#ifndef		__ANIMATION__
# define	__ANIMATION__

#include	<SFML/System.hpp>
#include	<iostream>
#include	"PausableClock.hh"

class Animation
{
private:
  unsigned int	_aFrame;
  float		_delay;
  bool		_isLoop;
  bool		_isPlaying;
  //bool		_isOneFramed;

protected:
  PausableClock _clock;

public:
  Animation();
  virtual ~Animation();

  void			nextFrame();
  virtual void		setFrame(const unsigned int&);
  void			reset();
  unsigned int		getActualFrame() const;
  void			setLoop(const bool&);
  bool			getLoop() const;
  //void			setOneFrame(const bool&);
  //bool			getOneFrame();
  void			play();
  void			stop();
  void			pause();
  bool			getIsPlaying() const;
  void			setDelay(const float&);
  float			getDelay() const;
  virtual void		update();
  virtual unsigned int	getSize() const = 0;
};

#endif
