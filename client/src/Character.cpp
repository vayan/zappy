//
// Character.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:21:28 2012 yuguo cao
// Last update Wed Jul 11 11:19:53 2012 yuguo cao
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
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(0, 0, 64, 64));
  frame2->SetSubRect(sf::IntRect(64, 0, 64 * 2, 64));
  frame3->SetSubRect(sf::IntRect(64 * 2, 0, 64 * 3, 64));
  frame4->SetSubRect(sf::IntRect(64 * 3, 0, 64 * 4, 64));

  _mUp.setDelay(0.2);
  _mUp.push_back(frame1);
  _mUp.push_back(frame3);
  _mUp.push_back(frame2);
  _mUp.push_back(frame4);
}

void		Character::mDown()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 8, 0, 64 * 9, 64));
  frame2->SetSubRect(sf::IntRect(64 * 9, 0, 64 * 10, 64));
  frame3->SetSubRect(sf::IntRect(64 * 10, 0, 64 * 11, 64));
  frame4->SetSubRect(sf::IntRect(64 * 11, 0, 64 * 12, 64));

  _mDown.setDelay(0.2);
  _mDown.push_back(frame1);
  _mDown.push_back(frame2);
  _mDown.push_back(frame3);
  _mDown.push_back(frame4);
}

void		Character::mLeft()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 12, 0, 64 * 13, 64));
  frame2->SetSubRect(sf::IntRect(64 * 13, 0, 64 * 14, 64));
  frame3->SetSubRect(sf::IntRect(64 * 14, 0, 64 * 15, 64));
  frame4->SetSubRect(sf::IntRect(64 * 15, 0, 64 * 16, 64));

  _mLeft.setDelay(0.2);
  _mLeft.push_back(frame1);
  _mLeft.push_back(frame2);
  _mLeft.push_back(frame3);
  _mLeft.push_back(frame4);
}

void		Character::mRight()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 4, 0, 64 * 5, 64));
  frame2->SetSubRect(sf::IntRect(64 * 5, 0, 64 * 6, 64));
  frame3->SetSubRect(sf::IntRect(64 * 6, 0, 64 * 7, 64));
  frame4->SetSubRect(sf::IntRect(64 * 7, 0, 64 * 8, 64));

  _mRight.setDelay(0.2);
  _mRight.push_back(frame1);
  _mRight.push_back(frame2);
  _mRight.push_back(frame3);
  _mRight.push_back(frame4);
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

  frame1->SetSubRect(sf::IntRect(0, 0, 64, 64));
  frame2->SetSubRect(sf::IntRect(64 * 4, 0, 64 * 5, 64));
  frame3->SetSubRect(sf::IntRect(64 * 8, 0, 64 * 9, 64));
  frame4->SetSubRect(sf::IntRect(64 * 12, 0, 64 * 13, 64));

  _mStand.pause();
  _mStand.push_back(frame1);
  _mStand.push_back(frame3);
  _mStand.push_back(frame4);
  _mStand.push_back(frame2);
}

void		Character::mPond()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  // sf::Sprite	*frame2 = new sf::Sprite;
  // sf::Sprite	*frame3 = new sf::Sprite;
  // sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  // frame2->SetImage(_image);
  // frame3->SetImage(_image);
  // frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 24, 0, 64 * 25, 64));
  // frame2->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame3->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame4->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));

  _mPond.pause();
  _mPond.push_back(frame1);
  _mPond.push_back(frame1);
  _mPond.push_back(frame1);
  _mPond.push_back(frame1);
}

void		Character::mTake()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 16, 0, 64 * 17, 64));
  frame2->SetSubRect(sf::IntRect(64 * 17, 0, 64 * 18, 64));
  frame3->SetSubRect(sf::IntRect(64 * 18, 0, 64 * 19, 64));
  frame4->SetSubRect(sf::IntRect(64 * 19, 0, 64 * 20, 64));

  _mTake.pause();
  _mTake.push_back(frame3);
  _mTake.push_back(frame2);
  _mTake.push_back(frame1);
  _mTake.push_back(frame4);
}

void		Character::mBroad()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  // sf::Sprite	*frame2 = new sf::Sprite;
  // sf::Sprite	*frame3 = new sf::Sprite;
  // sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  // frame2->SetImage(_image);
  // frame3->SetImage(_image);
  // frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 25, 0, 64 * 26, 64));
  // frame2->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame3->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));
  // frame4->SetSubRect(sf::IntRect(24 * 49, 0, 24 * 50, 60));

  _mBroad.pause();
  _mBroad.push_back(frame1);
  _mBroad.push_back(frame1);
  _mBroad.push_back(frame1);
  _mBroad.push_back(frame1);
}

void		Character::mExpu()
{
  sf::Sprite	*frame1 = new sf::Sprite;
  sf::Sprite	*frame2 = new sf::Sprite;
  sf::Sprite	*frame3 = new sf::Sprite;
  sf::Sprite	*frame4 = new sf::Sprite;

  frame1->SetImage(_image);
  frame2->SetImage(_image);
  frame3->SetImage(_image);
  frame4->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 20, 0, 64 * 21, 64));
  frame2->SetSubRect(sf::IntRect(64 * 21, 0, 64 * 22, 64));
  frame3->SetSubRect(sf::IntRect(64 * 22, 0, 64 * 23, 64));
  frame4->SetSubRect(sf::IntRect(64 * 23, 0, 64 * 24, 64));

  _mExpu.pause();
  _mExpu.push_back(frame3);
  _mExpu.push_back(frame2);
  _mExpu.push_back(frame1);
  _mExpu.push_back(frame4);
}

void		Character::mDie()
{
  sf::Sprite	*frame1 = new sf::Sprite;

  frame1->SetImage(_image);

  frame1->SetSubRect(sf::IntRect(64 * 26, 0, 64 * 27, 64));

  _mDie.pause();
  _mDie.push_back(frame1);
  _mDie.push_back(frame1);
  _mDie.push_back(frame1);
  _mDie.push_back(frame1);
}
