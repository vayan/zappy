//
// Character.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Fri Jun 15 12:06:22 2012 yuguo cao
//

#include	"Character.hh"

Character::Character()
{
}

Character::~Character()
{
}

void		Character::mUp()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 240, 35, 320));
  frame2->SetSubRect(sf::IntRect(35, 240, 70, 320));
  frame3->SetSubRect(sf::IntRect(70, 240, 105, 320));

  _mUp.setDelay(0.2);
  _mUp.push_back(frame1);
  _mUp.push_back(frame2);
  _mUp.push_back(frame3);
  _mUp.push_back(frame2);
}

void		Character::mDown()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 0, 35, 80));
  frame2->SetSubRect(sf::IntRect(35, 0, 70, 80));
  frame3->SetSubRect(sf::IntRect(70, 0, 105, 80));

  _mDown.setDelay(0.2);
  _mDown.push_back(frame1);
  _mDown.push_back(frame2);
  _mDown.push_back(frame3);
  _mDown.push_back(frame2);
}

void		Character::mLeft()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 80, 35, 160));
  frame2->SetSubRect(sf::IntRect(35, 80, 70, 160));
  frame3->SetSubRect(sf::IntRect(70, 80, 105, 160));

  _mLeft.setDelay(0.2);
  _mLeft.push_back(frame1);
  _mLeft.push_back(frame2);
  _mLeft.push_back(frame3);
  _mLeft.push_back(frame2);
}
void		Character::mRight()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 160, 35, 240));
  frame2->SetSubRect(sf::IntRect(35, 160, 70, 240));
  frame3->SetSubRect(sf::IntRect(70, 160, 105, 240));

  _mRight.setDelay(0.2);
  _mRight.push_back(frame1);
  _mRight.push_back(frame2);
  _mRight.push_back(frame3);
  _mRight.push_back(frame2);
}
void		Character::mStand()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(35, 240, 70, 320));
  frame2->SetSubRect(sf::IntRect(35, 0, 70, 80));
  frame3->SetSubRect(sf::IntRect(35, 80, 70, 160));
  frame4->SetSubRect(sf::IntRect(35, 160, 70, 240));

  _mStand.pause();
  _mStand.push_back(frame1);
  _mStand.push_back(frame2);
  _mStand.push_back(frame3);
  _mStand.push_back(frame4);
}

void		Character::mCast()
{
}

void		Character::mBroad()
{
}

void		Character::mDie()
{
}
