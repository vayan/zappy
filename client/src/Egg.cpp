//
// Egg.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Sat Jul 14 23:24:06 2012 yuguo cao
//

#include	"Egg.hh"

Egg::Egg()
{
  genMargins();
}

Egg::~Egg()
{
}

void		Egg::genMargins()
{
  _x_margin = rand() % 17;
  _y_margin = rand() % 17;
  if (rand() % 2)
    _x_margin *= -1;
  if (rand() % 2)
    _y_margin *= -1;
  _x_margin += 32;
  _y_margin -= 16;
}

void		Egg::mUp()
{
}

void		Egg::mDown()
{
}

void		Egg::mLeft()
{
}

void		Egg::mRight()
{
}

void		Egg::mStand()
{
  
  sf::Sprite	*frame1 = new sf::Sprite;

  frame1->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 0, 80, 80));

  _mStand.setDelay(1);
  _mStand.push_back(frame1);
  _mStand.push_back(frame1);
  _mStand.push_back(frame1);
  _mStand.push_back(frame1);
}

void		Egg::mPond()
{
}

void		Egg::mTake()
{
}

void		Egg::mBroad()
{
}

void		Egg::mExpu()
{
}

void		Egg::mDie()
{
}
