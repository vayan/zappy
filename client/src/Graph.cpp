//
// Graph.cpp for  in /home/cao_y//sysunix/zappy-2015-2014s-haulot_a/client
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed Jun  6 14:16:26 2012 yuguo cao
// Last update Fri Jun 15 13:00:15 2012 yuguo cao
//

#include	"Graph.hh"

Graph::Graph(const int height, const int width)
  : _app(sf::VideoMode(height, width, 32), "SFML Window"), _input(_app.GetInput())
{
  _imman = new Imman();
  _scr_height = height;
  _scr_width = width;
  _scr_bpp = 32;
}

Graph::~Graph()
{
}

void		Graph::run()
{
  initialize();
  while (_app.IsOpened())
    {
      update();
      //      float Framerate = 1.f / _app.GetFrameTime();
      //      std::cout << Framerate << std::endl;
      draw();
    }
}

void		Graph::initialize()
{
  _app.SetFramerateLimit(60);
  _imman->loadImages();

  _char.createAnim(_imman->getImage("mage_charset1"));
  _char.setPos(1440/2, 900/2);

  _map.setHeight(20);
  _map.setWidth(20);
  _map.setImage(_imman->getImage("back"));
}

void		Graph::update()
{
  sf::Event	event;

  if (_app.GetEvent(event))
    {
      if (((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
	  || event.Type == sf::Event::Closed)
	_app.Close();
    }



  // if (_app.GetInput().IsKeyDown(sf::Key::Left))  _char.move(-75 * ElapsedTime, 50 * ElapsedTime);
  // if (_app.GetInput().IsKeyDown(sf::Key::Right)) _char.move(75 * ElapsedTime, -50 * ElapsedTime);
  // if (_app.GetInput().IsKeyDown(sf::Key::Up))    _char.move(-75 * ElapsedTime, -50 * ElapsedTime);
  // if (_app.GetInput().IsKeyDown(sf::Key::Down))  _char.move(75 * ElapsedTime, 50 * ElapsedTime);
  // std::cout << -100 * ElapsedTime << std::endl;

  //std::cout << _input.GetMouseX() << " " << _input.GetMouseY() << std::endl;
}

void		Graph::draw()
{
  float		ElapsedTime = _app.GetFrameTime();

  _app.Clear(sf::Color(0, 0, 200));
  std::cout << _char.getLastAction() << std::endl;
  _app.Draw(_char.anim(STAND, _char.getLastAction()));
  if (_app.GetInput().IsKeyDown(sf::Key::Left))
    {
      _char.move(-75 * ElapsedTime, 50 * ElapsedTime);
      _app.Draw(_char.anim(LEFT));
    }
  if (_app.GetInput().IsKeyDown(sf::Key::Right))
    {
      _char.move(75 * ElapsedTime, -50 * ElapsedTime);
      _app.Draw(_char.anim(RIGHT));
    }
  if (_app.GetInput().IsKeyDown(sf::Key::Up))
    {
      _char.move(-75 * ElapsedTime, -50 * ElapsedTime);
      _app.Draw(_char.anim(UP));
    }
  if (_app.GetInput().IsKeyDown(sf::Key::Down))
    {
      _char.move(75 * ElapsedTime, 50 * ElapsedTime);
      _app.Draw(_char.anim(DOWN));
    }
  _map.draw(this);
  _app.Display();
}
