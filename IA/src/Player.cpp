//
// Player.cpp for player in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun 13 11:21:10 2012 alexandre haulotte
// Last update Thu Jul 12 17:16:35 2012 alexandre haulotte
//

#include	"Player.hh"


void  Player::connexion()
{
  struct protoent       *pe;
  struct sockaddr_in    sin;
  int                   ret = 0;

  pe = getprotobyname("TCP");
  if ((_soc = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(&_addr[0]);
  if (static_cast<int>(sin.sin_addr.s_addr) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_port = htons(_port);
  ret = connect(_soc, (const struct sockaddr*)&sin, sizeof(sin));
  if (ret == -1)
    throw(new Errur("Connection Fail"));
}

void  Player::play()
{
  fd_set		readfds;
  struct timeval	tv;
  int                   ret;
  char                  buff[16192 + 1];
  int			fctRet = 0;

  connexion();
  initTab();
  tv.tv_sec = 0;
  tv.tv_usec = 2000;
  recInfo();
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  FD_SET(_soc, &readfds);
  while (select(_soc + 1, &readfds, NULL, NULL, &tv) != -1)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 2000;
      if (fctRet == ERR)
	throw (new Errur("Msg not send"));
      if (FD_ISSET(_soc, &readfds))
	{
	  ret = recv(_soc, buff, 16192, 0);
	  buff[ret] = 0;
	  //std::cout << buff << std::endl;
	  _lastRep = buff;
	  if (std::string(buff).find("mort") != std::string::npos)
	    throw (new Errur("Pour Trantor...arg...mon coeur... MON COEUR"));
	  else if (std::string(buff).find("deplacement") != std::string::npos)
	    {
	      rDir = buff[12] - '0';
	      //GoToDir();
	    }
	  else if (_lastRep.find("message") != std::string::npos)
	    _msg.push_back(_lastRep);
	}
      //std::cout << _id << " | Etat : " << _cState << std::endl;
      fctRet = (this->*fctTable[_cState])();
      //std::cout << _id << " | Retour Fct : " << fctRet << std::endl;
      while ((ret = recv(_soc, buff, 16192, MSG_DONTWAIT)) > 0)
	{
	  buff[ret] = 0;
	  if (std::string(buff).find("mort") != std::string::npos)
	    throw (new Errur("Pour Trantor...arg...mon coeur... MON COEUR"));
	  else if (std::string(buff).find("deplacement") != std::string::npos)
	    {
	      rDir = buff[12] - '0';
	      //GoToDir();
	    }
	  else if (_lastRep.find("message") != std::string::npos)
	    _msg.push_back(_lastRep);
	}
      _cState = trTable[_cState][fctRet];
      if (_lvl == 6)
	std::cout << _id << " ! Etat : " << _cState << std::endl;
      FD_ZERO(&readfds);
      FD_SET(0, &readfds);
      FD_SET(_soc, &readfds);
    }
}

void	Player::recInfo()
{
  std::string	str;
  int		ret;
  char		buff[16192 + 1];

  ret = recv(_soc, buff, 16192, 0);
  send(_soc, &_teamName[0], _teamName.length(), 0);
  send(_soc, "\n", 1, 0);
  ret = recv(_soc, buff, 16192, 0);
  buff[ret] = 0;
  //  _id = strToInt(buff);
  std::cout << "Mon Id est : " << _id << std::endl;
  ret = recv(_soc, buff, 16192, 0);
  buff[ret] = 0;
  str = &buff[0];
  std::cout << "Taille Map : " << buff << std::endl;
}

Player::Player(int compo)
  :_x(0), _y(0), _width(0), _height(0), _dir(1), _lvl(0), _id(0),
   _port(0), _addr(""), _compo(0), _lastRep(""), _cState(compo), _spam("")
{
  _teamName = "";
  _ressource[FOOD] = 10;
  _ressource[LINEMATE] = 0;
  _ressource[DERAUMERE] = 0;
  _ressource[SIBUR] = 0;
  _ressource[MENDIANE] = 0;
  _ressource[PHIRAS] = 0;
  _ressource[THYSTAME] = 0;
  _lvlTab = {{1, 1, 0, 0, 0, 0, 0},
	     {2, 1, 1, 1, 0, 0, 0},
	     {2, 2, 0, 1, 0, 2, 0},
	     {4, 1, 1, 2, 0, 1, 0},
	     {4, 1, 2, 1, 3, 0, 0},
	     {6, 1, 2, 3, 0, 1, 0},
	     {6, 2, 2, 2, 2, 2, 1}};
  _nbRenf = 1;
}

Player::Player(int port, std::string ip, std::string team, int compo, int id)
  :_x(0), _y(0), _width(0), _height(0), _dir(1), _lvl(0), _id(id),
   _port(port), _addr(ip),  _compo(0), _lastRep(""), _cState(compo), _spam("")
{
  _teamName = team;
  _ressource[FOOD] = 10;
  _ressource[LINEMATE] = 0;
  _ressource[DERAUMERE] = 0;
  _ressource[SIBUR] = 0;
  _ressource[MENDIANE] = 0;
  _ressource[PHIRAS] = 0;
  _ressource[THYSTAME] = 0;
  _lvlTab = {{1, 1, 0, 0, 0, 0, 0},
	     {2, 1, 1, 1, 0, 0, 0},
	     {2, 2, 0, 1, 0, 2, 0},
	     {4, 1, 1, 2, 0, 1, 0},
	     {4, 1, 2, 1, 3, 0, 0},
	     {6, 1, 2, 3, 0, 1, 0},
	     {6, 2, 2, 2, 2, 2, 1}};
  _nbRenf = 1;
}

void    Player::parse(int ac, char **av)
{
  struct hostent *h;
  std::string ip_address;
  in_addr *addss;

  if (ac < 5)
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  if (ac == 5)
    _addr = "127.0.0.1";
  else if (ac != 7)
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  for (int i = 1; i < ac; i++)
    {
      if (i % 2 == 1 && av[i][0] != '-')
	throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
      else if (i % 2 == 1 && av[i][0] == '-' && av[i][2] == '\0')
	{
	  switch (av[i][1])
	    {
	    case 'n':
	      _teamName = &av[i + 1][0];
	      break;
	    case 'p':
	      _port = strToInt(&av[i + 1][0]);
	      break;
	    case 'h':
	      h = gethostbyname(&av[i + 1][0]);
	      addss = (in_addr*)h->h_addr;
	      ip_address = inet_ntoa(*addss);
	      _addr = ip_address;
	      break;
	    default:
	      throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
	      break;
	    }
	  i++;
	}
      else
        throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
    }
  if (_teamName == "" || _port == 0 || _addr == "")
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  else
    {
      std::cout << "Team Name is : " << _teamName << std::endl;
      std::cout << "Port is : " << _port << std::endl;
      std::cout << "Host Name is : " << _addr << std::endl;
    }
}

//-------------------------------------//
//--------------- GETTER --------------//
//-------------------------------------//
int	Player::getX() const
{ return (_x); }

int	Player::getY() const
{ return (_y); }

int	Player::getWidth() const
{ return (_width); }

int	Player::getHeight() const
{ return (_height); }

int	Player::getDir() const
{ return (_dir); }

int	Player::getLvl() const
{ return (_lvl); }

int	Player::getRessource(int r) const
{ return (_ressource[r]); }

std::map< int, std::map< int, std::vector<int> > >	Player::getMap() const
{ return (_map); }

int	Player::getId() const
{ return (_id); }

//-------------------------------------//
//--------------- SETTER --------------//
//-------------------------------------//
void  Player::setX(int x)
{ _x = x; }

void  Player::setY(int y)
{ _y = y; }

void  Player::setDir(int dir)
{ _dir = dir; }

void  Player::setLvl(int lvl)
{ _lvl = lvl; }

void  Player::setRessource(int r, int nb)
{ _ressource[r] += nb; }

void	Player::initCase(int x, int y)
{
  for (int i = 0; i < 9; i++)
    (_map[x][y])[i] = 0;
}
void  Player::setMap(int x, int y, int p, int nb)
{
  if (_map[x][y].empty())
    initCase(x, y);
  (_map[x][y])[p] += nb;
}


int     Player::strToInt(char* str)
{
  std::istringstream    buffer(str);
  int                   nbr;

  buffer >> nbr;
  return (nbr);
}

std::string   Player::intToStr(int i)
{
  std::ostringstream oss;

  oss << i;
  return (oss.str());
}

int	Player::xrecv()
{
  fd_set				readfds;
  int					ret = 0;
  struct timeval			tv;
  char					buff[16192 + 1];
  std::vector<std::string>		rep;
  std::vector<std::string>::iterator	it;
  std::string				save = "";

  tv.tv_sec = 5;
  tv.tv_usec = 0;
  FD_ZERO(&readfds);
  FD_SET(_soc, &readfds);
  while (select(_soc + 1, &readfds, NULL, NULL, &tv) != -1)
    {
      tv.tv_sec = 5;
      tv.tv_usec = 0;
      if (FD_ISSET(_soc, &readfds))
	{
	  ret = recv(_soc, buff, 16192, 0);
	  if (ret == -1)
	    return (ERR);
	  buff[ret] = 0;
	  _lastRep = buff;
	  rep = split_to_vec(_lastRep, "\n");
	  if (rep.size() > 1)
	    {
	      save = "";
	      for (it = rep.begin(); it != rep.end(); it++)
		{
		  _lastRep = (*it);
		  if (_lastRep.find("message") != std::string::npos)
		    _msg.push_back(_lastRep);
		  else if (std::string(buff).find("deplacement") != std::string::npos)
		    {
		      rDir = buff[12] - '0';
		      //GoToDir();
		    }
		  else
		    save = _lastRep;
		}
	      if (save != "")
		{
		  _lastRep = save;
		  break;
		}
	    }
	  if (_lastRep.find("message") == std::string::npos && std::string(buff).find("deplacement") == std::string::npos)
	    break;
	  else
	    _msg.push_back(_lastRep);
	}
      else
	{
	  //	  std::cout << _id << " | je recois rien" << std::endl;
	  break;
	}
      //      std::cout << _id << " | je recois un message : " << _lastRep << std::endl;
      FD_ZERO(&readfds);
      FD_SET(_soc, &readfds);
    }
  return (ret);
}

int	Player::xsend(int soc, const void* msg, int size, int flag)
{
  int	ret;
  //  ret = xrecv();
  ret = send(soc, msg, size, flag);
  return (ret);
}

void 	Player::Tokenize(const std::string& str, std::vector<std::string>& tokens,
			 const std::string& delimiters)
{
  std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

  //  std::cout << pos << " : "<< lastPos << " : " << str << std::endl;
  while (std::string::npos != pos || std::string::npos != lastPos)
    {
      tokens.push_back(str.substr(lastPos, pos - lastPos));
      lastPos = str.find_first_not_of(delimiters, pos);
      pos = str.find_first_of(delimiters, lastPos);
    }
}

std::vector<std::string> Player::split_to_vec(std::string to_split,
					      std::string delim)
{
  std::vector<std::string> tokens;

  while (to_split.find(",,") != std::string::npos)
    to_split.replace(to_split.find(",,"), 2, ", nada,");
  while (to_split.find(",\n") != std::string::npos)
    to_split.replace(to_split.find(",\n"), 2, ", nada");
  Tokenize(to_split, tokens, delim);
  return (tokens);
}

int     Player::searchDir(std::vector<std::string> food, std::string tok)
{
  uint	i = 0;

  while ( i < food.size() && (food[i]).find(tok) == std::string::npos)
    i++;
  //  std::cout << "Search vector size : " << food.size() <<  " case = "  << i << std::endl;
  switch (i)
    {
    case 0:
      return (OK);
    case 1:
      rDir = 2;
      return (GODIR);
    case 2:
      rDir = 1;
      return (GODIR);
    case 3:
      rDir = 8;
      return (GODIR);
    default:
      rDir = 0;
      return (KO);
    }
}

Player::~Player() {}
