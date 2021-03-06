//
// ASprite.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Thu Jun 14 11:09:55 2012 yuguo cao
// Last update Sat Jul 14 22:32:38 2012 yuguo cao
//

#include	"ASprite.hh"

ASprite::ASprite()
{
  _orientation = UP;
  _lastAction = UP;
  _x_margin = 32;
  _y_margin = -16;
}

ACTION		ASprite::getLastAction() const
{
  return (_lastAction);
}

void		ASprite::createAnim(const sf::Image& i)
{
  _image = i;
  mUp();
  mDown();
  mLeft();
  mRight();
  mStand();
  mTake();
  mBroad();
  mExpu();
  mPond();
  mDie();
}

LayerAnimation	ASprite::anim(ACTION a)
{
  if (a == NO)
    a = _lastAction;
  switch (a)
    {
    case (UP):
      _orientation = UP;
      _lastAction = UP;
      return (_mUp);
      break;
    case (DOWN):
      _orientation = DOWN;
      _lastAction = DOWN;
      return (_mDown);
      break;
    case (LEFT):
      _orientation = LEFT;
      _lastAction = LEFT;
      return (_mLeft);
      break;
    case (RIGHT):
      _orientation = RIGHT;
      _lastAction = RIGHT;
      return (_mRight);
      break;
    case (STAND):
      _lastAction = STAND;
      switch (_orientation)
	{
	case (UP):
	  _mStand.setFrame(0);
	  break;
	case (DOWN):
	  _mStand.setFrame(1);
	  break;
	case (LEFT):
	  _mStand.setFrame(2);
	  break;
	case (RIGHT):
	  _mStand.setFrame(3);
	  break;
	default:
	  _mStand.setFrame(0);
	}
      return (_mStand);
      break;
    case (POND):
      _lastAction = POND;
      switch (_orientation)
	{
	case (UP):
	  _mPond.setFrame(0);
	  break;
	case (DOWN):
	  _mPond.setFrame(1);
	  break;
	case (LEFT):
	  _mPond.setFrame(2);
	  break;
	case (RIGHT):
	  _mPond.setFrame(3);
	  break;
	default:
	  _mPond.setFrame(0);
	}
      return (_mPond);
      break;
    case (TAKE):
      _lastAction = TAKE;
      switch (_orientation)
	{
	case (UP):
	  _mTake.setFrame(0);
	  break;
	case (DOWN):
	  _mTake.setFrame(1);
	  break;
	case (LEFT):
	  _mTake.setFrame(2);
	  break;
	case (RIGHT):
	  _mTake.setFrame(3);
	  break;
	default:
	  _mTake.setFrame(0);
	}
      return (_mTake);
      break;
    case (BROAD):
      _lastAction = BROAD;
      switch (_orientation)
	{
	case (UP):
	  _mBroad.setFrame(0);
	  break;
	case (DOWN):
	  _mBroad.setFrame(1);
	  break;
	case (LEFT):
	  _mBroad.setFrame(2);
	  break;
	case (RIGHT):
	  _mBroad.setFrame(3);
	  break;
	default:
	  _mBroad.setFrame(0);
	}
      return (_mBroad);
      break;
    case (EXPU):
      _lastAction = EXPU;
      switch (_orientation)
	{
	case (UP):
	  _mExpu.setFrame(0);
	  break;
	case (DOWN):
	  _mExpu.setFrame(1);
	  break;
	case (LEFT):
	  _mExpu.setFrame(2);
	  break;
	case (RIGHT):
	  _mExpu.setFrame(3);
	  break;
	default:
	  _mExpu.setFrame(0);
	}
      return (_mExpu);
      break;
    case (DIE):
      _lastAction = DIE;
      switch (_orientation)
	{
	case (UP):
	  _mDie.setFrame(0);
	  break;
	case (DOWN):
	  _mDie.setFrame(1);
	  break;
	case (LEFT):
	  _mDie.setFrame(2);
	  break;
	case (RIGHT):
	  _mDie.setFrame(3);
	  break;
	default:
	  _mDie.setFrame(0);
	}
      return (_mDie);
      break;
    default:
      _mStand.setFrame(0);
      return (_mStand);
    }
}

void		ASprite::move(const float x, const float y)
{
  _mUp.Move(x, y);
  _mDown.Move(x, y);
  _mLeft.Move(x, y);
  _mRight.Move(x, y);
  _mStand.Move(x, y);
  _mPond.Move(x, y);
  _mTake.Move(x, y);
  _mBroad.Move(x, y);
  _mExpu.Move(x, y);
  _mDie.Move(x, y);
}

void		ASprite::setLastAction(const ACTION a)
{
  _lastAction = a;
}

void		ASprite::setOrientation(const ACTION a)
{
  _orientation = a;
}

ACTION		ASprite::getOrientation() const
{
  return (_orientation);
}

void		ASprite::setPosition(const int x, const int y)
{
  _mUp.SetPosition(x, y);
  _mDown.SetPosition(x, y);
  _mLeft.SetPosition(x, y);
  _mRight.SetPosition(x, y);
  _mStand.SetPosition(x, y);
  _mPond.SetPosition(x, y);
  _mTake.SetPosition(x, y);
  _mBroad.SetPosition(x, y);
  _mExpu.SetPosition(x, y);
  _mDie.SetPosition(x, y);
}

void		ASprite::setScale(const float s)
{
  _mUp.SetScale(s, s);
  _mDown.SetScale(s, s);
  _mLeft.SetScale(s, s);
  _mRight.SetScale(s, s);
  _mStand.SetScale(s, s);
  _mPond.SetScale(s, s);
  _mTake.SetScale(s, s);
  _mBroad.SetScale(s, s);
  _mExpu.SetScale(s, s);
  _mDie.SetScale(s, s);
}

void		ASprite::setColor(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
  std::cout << "<<<<<<<<< " << int(_mStand.GetColor().a) << std::endl;
  _mUp.SetColor(sf::Color(r, g, b, a));
  _mDown.SetColor(sf::Color(r, g, b, a));
  _mLeft.SetColor(sf::Color(r, g, b, a));
  _mRight.SetColor(sf::Color(r, g, b, a));
  _mStand.SetColor(sf::Color(r, g, b, a));
  _mPond.SetColor(sf::Color(r, g, b, a));
  _mTake.SetColor(sf::Color(r, g, b, a));
  _mBroad.SetColor(sf::Color(r, g, b, a));
  _mExpu.SetColor(sf::Color(r, g, b, a));
  _mDie.SetColor(sf::Color(r, g, b, a));
  std::cout << ">>>>>>>>> " << int(_mStand.GetColor().a) << std::endl;
}


const sf::Vector2f&	ASprite::getPosition() const
{
  return (_mStand.GetPosition());
}
