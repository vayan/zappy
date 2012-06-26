//
// Graph.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun  6 14:16:26 2012 yuguo cao
// Last update Wed Jun 20 14:45:25 2012 yuguo cao
//

#include	"Graph.hh"

Graph::Graph(const int width, const int height)
  : _app(sf::VideoMode(width, height, 32), "SFML Window"), _input(_app.GetInput())
{
  _imman = new Imman();
  _scr_height = height;
  _scr_width = width;
  _scr_bpp = 32;
}

Graph::~Graph()
{
}

void			Graph::run()
{
  initialize();
  while (_app.IsOpened())
    {
      update();
      draw();
    }
}

void			Graph::initialize()
{
  _app.SetFramerateLimit(60);
  _imman->loadImages();

  addPlayer(4, 4, DOWN, 0, 0);
  addPlayer(3, 3, DOWN, 1, 0);
  addPlayer(2, 2, DOWN, 2, 0);

  _char.createAnim(_imman->getImage("mage_charset1"));
  _char.setPosition(0, 0);

  _view.SetFromRect(sf::FloatRect(0, 0, _scr_width, _scr_height));
  _view.SetCenter(0, 0);

  _map.setHeight(5);
  _map.setWidth(5);
  _map.setImage(_imman->getImage("back"));
}

void			Graph::update()
{
  int			x;
  int			y;
  sf::Event		event;
  float			elapsedTime = _app.GetFrameTime();
  sf::Vector2<int>	ccase;

  while (_app.GetEvent(event))
    {
      if (((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
	  || event.Type == sf::Event::Closed)
	_app.Close();

      if (event.Type == sf::Event::MouseWheelMoved)
	{
	  if (event.MouseWheel.Delta > 0)
	    _view.Zoom(1.1);
	  else if (event.MouseWheel.Delta < 0)
	    _view.Zoom(0.9);
	}
      if (event.Type == sf::Event::MouseButtonPressed)
	{
	  x = relaMouse(event).x;
	  y = relaMouse(event).y;
	  // if (event.MouseButton.Button == 0 && (x >= _char.getPosition().x && x <= _char.getPosition().x + 35 && y >= _char.getPosition().y && y <= _char.getPosition().y + 80))
	  //   {
	  //     std::cout << _char.getPosition().x << " " << _char.getPosition().y << std::endl;
	  //   }
	  //else
	  if (event.MouseButton.Button == 0)
	    movePlayer(1, 1, UP, 0);
	  if (event.MouseButton.Button == 2)
	    {
	      ccase = _map.getMCase(relaMouse(event));
	      std::cout << ccase.x << " " << ccase.y << std::endl;
	    }
	}
    }
  if (_view.GetCenter().x > 0 && _input.GetMouseX() < 200)
    _view.Move(-200 * elapsedTime, 0);
  else if (_view.GetCenter().x < _map.getWidth() * 64 + (_map.getHeight() * 64) && _input.GetMouseX() > 1240)
    _view.Move(200 * elapsedTime, 0);
  if (_view.GetCenter().y > (_map.getWidth() - 1) * -32 && _input.GetMouseY() < 100)
    _view.Move(0, -200 * elapsedTime);
  else if (_view.GetCenter().y < (_map.getHeight() + 1) * 32 && _input.GetMouseY() > 800)
    _view.Move(0, 200 * elapsedTime);
}

sf::Vector2<int>&	Graph::relaMouse(const sf::Event& event)
{
  sf::Vector2<int>	*v2 = new sf::Vector2<int>();

  v2->x = _view.GetCenter().x + (int(_app.GetWidth()) / 2 - event.MouseButton.X) * -1;
  v2->y = _view.GetCenter().y + (int(_app.GetHeight()) / 2 - event.MouseButton.Y) * -1;
  return (*v2);
}

void			Graph::draw()
{
  float		elapsedTime = _app.GetFrameTime();

  _app.Clear(sf::Color(0, 0, 200));
  _map.draw(this->_app);

  if (_app.GetInput().IsKeyDown(sf::Key::Left))
    {
      _char.move(-100 * elapsedTime, 50 * elapsedTime);
      _app.Draw(_char.anim(LEFT));
    }
  else if (_app.GetInput().IsKeyDown(sf::Key::Right))
    {
      _char.move(100 * elapsedTime, -50 * elapsedTime);
      _app.Draw(_char.anim(RIGHT));
    }
  else if (_app.GetInput().IsKeyDown(sf::Key::Up))
    {
      _char.move(-100 * elapsedTime, -50 * elapsedTime);
      _app.Draw(_char.anim(UP));
    }
  else if (_app.GetInput().IsKeyDown(sf::Key::Down))
    {
      _char.move(100 * elapsedTime, 50 * elapsedTime);
      _app.Draw(_char.anim(DOWN));
    }
  else
    _app.Draw(_char.anim(STAND));
  //_view.SetCenter(_char.getPosition());

  for(std::map<int, ASprite*>::iterator it = _sprites.begin() ; it != _sprites.end() ; ++it)
  {
    //it->first; // accede à la clé
    _app.Draw((it->second)->anim(STAND)); // accede à la valeur
  }
  _app.SetView(_view);
  _app.Display();
}

void			Graph::updaCaseInfo(const int x, const int y, const Stone_t& res)
{

}

void			Graph::requCaseInfo(const int x, const int y, const Stone_t& res)
{

}

void			Graph::addPlayer(const int x, const int y, const ACTION orientation, const int n, const int t)
{
  Character		*newchar = new Character();

  newchar->createAnim(_imman->getImage("mage_charset1"));
  newchar->setPosition(x * 64 + (y * 64), y * 32 - (x * 32));
  newchar->setLastAction(orientation);
  _sprites[n] = newchar;
}

void			Graph::movePlayer(const int x, const int y, const ACTION orientation, const int n)
{
  _sprites[n]->move(x * 64 + (y * 64), y * 32 - (x * 32));
}

void			Graph::requPlayerInfo(const int n)
{

}

void			Graph::expuPlayer(const int n)
{

}

void			Graph::broaPlayer(const int n)
{

}

void			Graph::incdPlayer(const int x, const int y)
{

}

void			Graph::incfPlayer(const int x, const int y)
{

}

void			Graph::pondPlayer(const int n)
{

}

void			Graph::dropPlayer(const int n)
{

}

void			Graph::takePlayer(const int n)
{

}

void			Graph::addEgg(const int x, const int y, const int n, const int t)
{

}

void			Graph::eggHatched(const int n)
{

}
