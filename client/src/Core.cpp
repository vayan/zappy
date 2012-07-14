//
// Core.cpp for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 13:59:33 2012 alexandre haulotte
// Last update Sat Jul 14 22:17:46 2012 yuguo cao
//

#include	"Core.hh"

Core::Core(int ac, char **av)
  :soc(0), graph(NULL), macName(""), port(4242)
{
  initTab();
  beginParse(ac, av);
}

Core::~Core()
{

}

void				Core::go()
{
  int				ret;
  char				buff[8096 + 1];
  char				cmd[128];
  fd_set			readfds;
  struct timeval		tv;
  int				i , j, save = 0;
  Parser			p;
  std::vector<std::string>	vec;

  init();
  ret = 1;
  tv.tv_sec = 0;
  tv.tv_usec = 20;
  if (!protocole())
    throw(new Errur("Erreur communication serveur."));
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  FD_SET(soc, &readfds);
  while (select(soc + 1, &readfds, NULL, NULL, &tv) != -1)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 2000;
      i = 0;
      if (FD_ISSET(soc, &readfds))
	{
	  ret = recv(soc, buff, 8096, 0);
	  if (ret == -1)
	    throw (new Errur("Receive Fail"));
	  buff[ret] = '\0';
	  while (i < ret)
	    {
	      j = save;
	      while (j < 128 && buff[i] && buff[i] != '\n')
	  	{
	  	  cmd[j] = buff[i];
	  	  i++;
	  	  j++;
	  	}
	      cmd[j] = '\0';
	      if (buff[i] == '\n')
		{
		  vec = p.parse(cmd);
		  if (vec[0] != "-1")
		    {
		      //std::cout << "Commande(" << vec[0] << ") = " << cmd << "<<" << std::endl;
		      (this->*funcs[sti(vec[0])])(vec);
		    }
		}
	      i++;
	      save = 0;
	    }
	  if (buff[ret - 1] != '\n')
	    save = j;
	}
      if (graph)
	graph->run();
      FD_ZERO(&readfds);
      FD_SET(0, &readfds);
      FD_SET(soc, &readfds);
    }
}

void			Core::init()
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			ret = 0;

  pe = getprotobyname("TCP");
  if ((soc = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(&macName[0]);
  if (static_cast<int>(sin.sin_addr.s_addr) == -1)
    throw(new Errur("Connection Fail"));
  sin.sin_port = htons(port);
  ret = connect(soc, (const struct sockaddr*)&sin, sizeof(sin));
  if (ret == -1)
    throw(new Errur("Connection Fail"));
}

void	Core::beginParse(int ac, char **av)
{
  struct hostent *h;
  std::string ip_address;
  in_addr *addss;

  if (ac < 3)
    //throw(new Errur("Usage : ./client -p port [-h nom machine]"));
    port = 4242;
  if (ac <= 3)
    macName = "127.0.0.1";
  //else if (ac != 5)
  //throw(new Errur("Usage : ./client -p port [-h nom machine]"));
  for (int i = 1; i < ac; i++)
    {
      if (i % 2 == 1 && av[i][0] != '-')
	throw(new Errur("Usage : ./client [-p port] [-h nom machine]"));
      else if (i % 2 == 1 && av[i][0] == '-' && av[i][2] == '\0')
	{
	  switch (av[i][1])
	    {
	    case 'p':
	      port = sti(&av[i + 1][0]);
	      break;
	    case 'h':
	      h = gethostbyname(&av[i + 1][0]);
	      addss = (in_addr*)h->h_addr;
	      ip_address = inet_ntoa(*addss);
	      macName = ip_address;
	      break;
	    default:
	      throw(new Errur("Usage : ./client [-p port] [-h nom machine]"));
	      break;
	    }
	  i++;
	}
      else
	throw(new Errur("Usage : ./client -p port [-h nom machine]"));
    }
  if (port == 0 || macName == "")
    throw(new Errur("Usage : ./client [-p port] [-h nom machine]"));
  else
    {
      std::cout << "Port is : " << port << std::endl;
      std::cout << "Host Name is : " << macName << std::endl;
    }
}

int				Core::protocole() const
{
  char				buffer[8096 + 1];
  int				ret;
  std::string			str("BIENVENUE");

  ret = recv(soc, buffer, 8096, 0);
  buffer[ret - 1] = '\0';
  if (str.compare(buffer) == 0)
    {
      send(soc, "GRAPHIC\n", 8, 0);
      return (1);
    }
  return (0);
}

const std::vector<int>		Core::vstvi(const std::vector<std::string> vin)
{
  std::vector<int>		vout;
  int unsigned			i;

  for(i = 0; i < vin.size(); i++)
    {
      vout.push_back(sti(vin[i]));
    }
  return (vout);
}

int	Core::sti(std::string str)
{
  std::istringstream 	buffer(str);
  int 			nbr;

  buffer >> nbr;
  return (nbr);
}

std::string   Core::its(int i)
{
  std::ostringstream oss;

  oss << i;
  return (oss.str());
}

void			Core::initTab()
{
  funcs.push_back(&Core::createMap); //msz
  funcs.push_back(&Core::updaCaseInfo); //bct
  funcs.push_back(&Core::rien); //tna
  funcs.push_back(&Core::addPlayer); //pnw
  funcs.push_back(&Core::movePlayer); //ppo
  funcs.push_back(&Core::lvlPlayer); //plv
  funcs.push_back(&Core::inventPlayer); //pin
  funcs.push_back(&Core::rien); //pex
  funcs.push_back(&Core::broaPlayer); //pbc
  funcs.push_back(&Core::incdPlayer); //pic
  funcs.push_back(&Core::incfPlayer); //pie
  funcs.push_back(&Core::pondPlayer); //pfk
  funcs.push_back(&Core::dropPlayer); //pdr
  funcs.push_back(&Core::takePlayer); //pgt
  funcs.push_back(&Core::diePlayer); //pdi
  funcs.push_back(&Core::addEgg); //enw
  funcs.push_back(&Core::eggHatched); //eht
  funcs.push_back(&Core::rien); //ebo
  funcs.push_back(&Core::eggHatched); //edi
  funcs.push_back(&Core::timeServer); //sgt
  funcs.push_back(&Core::victory); //seg
  funcs.push_back(&Core::rien); //smg
  funcs.push_back(&Core::rien); //suc
  funcs.push_back(&Core::rien); //sbp
}

void			Core::createMap(const std::vector<std::string>& v)
{
  std::vector<int>	vi;

  vi = vstvi(v);
  if (!graph)
    {
      graph = new Graph(this, soc, 1440, 900, vi[1], vi[2]);
      graph->initialize();
    }
}

void			Core::updaCaseInfo(const std::vector<std::string>& v)
{
  Stone_t		stone;
  std::vector<int>	vi;

  vi = vstvi(v);
  stone.food = vi[3];
  stone.linemate = vi[4];
  stone.deraumere = vi[5];
  stone.sibur = vi[6];
  stone.mendiane = vi[7];
  stone.phiras = vi[8];
  stone.thystame = vi[9];
  graph->updaCaseInfo(vi[1], vi[2], stone);
}

void			Core::requCaseInfo(const std::vector<std::string>& v)
{
  (void) v;
}

void			Core::addPlayer(const std::vector<std::string>& v)
{
  ACTION		a;

  switch(sti(v[4]))
    {
    case (1):
      a = UP;
      break;
    case (2):
      a = RIGHT;
      break;
    case (3):
      a = DOWN;
      break;
    case (4):
      a = LEFT;
      break;
    default:
      a = UP;
    }
  graph->addPlayer(sti(v[1]), sti(v[2]), sti(v[3]), a, sti(v[5]), v[6]);
}

void			Core::movePlayer(const std::vector<std::string>& v)
{
  ACTION		a;
  std::vector<int>	vi;

  vi = vstvi(v);
  switch(vi[4])
    {
    case (1):
      a = UP;
      break;
    case (2):
      a = RIGHT;
      break;
    case (3):
      a = DOWN;
      break;
    case (4):
      a = LEFT;
      break;
    default:
      a = UP;
    }
  graph->movePlayer(vi[1], vi[2], vi[3], a);
}

void			Core::lvlPlayer(const std::vector<std::string>& v)
{
  graph->lvlPlayer(sti(v[1]), sti(v[2]));
}

void			Core::inventPlayer(const std::vector<std::string>& v)
{
  Stone_t		stone;
  std::vector<int>	vi;

  vi = vstvi(v);
  stone.food = vi[4];
  stone.linemate = vi[5];
  stone.deraumere = vi[6];
  stone.sibur = vi[7];
  stone.mendiane = vi[8];
  stone.phiras = vi[9];
  stone.thystame = vi[10];

  graph->inventPlayer(vi[1], stone);
}

void			Core::requPlayerInfo(const std::vector<std::string>& v)
{
  (void) v;
}

void			Core::expuPlayer(const std::vector<std::string>& v)
{
  graph->expuPlayer(sti(v[1]));
}

void			Core::broaPlayer(const std::vector<std::string>& v)
{
  graph->broaPlayer(sti(v[1]));
}

void			Core::incdPlayer(const std::vector<std::string>& v)
{
  graph->incdPlayer(sti(v[1]), sti(v[2]));
}

void			Core::incfPlayer(const std::vector<std::string>& v)
{
  graph->incfPlayer(sti(v[1]), sti(v[2]));
}

void			Core::pondPlayer(const std::vector<std::string>& v)
{
  graph->pondPlayer(sti(v[1]));
}

void			Core::dropPlayer(const std::vector<std::string>& v)
{
  graph->dropPlayer(sti(v[1]));
}

void			Core::takePlayer(const std::vector<std::string>& v)
{
  graph->takePlayer(sti(v[1]));
}

void			Core::addEgg(const std::vector<std::string>& v)
{
  graph->addEgg(sti(v[1]), sti(v[2]), sti(v[3]), sti(v[4]));
}

void			Core::eggHatched(const std::vector<std::string>& v)
{
  graph->eggHatched(sti(v[1]));
}

void			Core::diePlayer(const std::vector<std::string>& v)
{
  graph->diePlayer(sti(v[1]));
}

void			Core::timeServer(const std::vector<std::string>& v)
{
  graph->timeServer(sti(v[1]));
}

void			Core::victory(const std::vector<std::string>& v)
{
  graph->victory(v[1]);
}

void			Core::rien(const std::vector<std::string>& v)
{
  (void) v;
}

void			Core::askLevel(const int n)
{
  int			ret;
  char			buff[8096 + 1];
  std::vector<std::string>	vec;
  std::string		s("plv " + its(n) + "\n");

  send(soc, &s[0], s.size(), 0);
  ret = recv(soc, buff, 8096, 0);
  if (ret == -1)
    throw (new Errur("Receive Fail"));
  buff[ret] = '\0';
  vec = p.parse(buff);
  if (vec[0] != "-1")
    {
      std::cout << "Commande(" << vec[0] << ") = " << buff << "<<" << std::endl;
      (this->*funcs[sti(vec[0])])(vec);
    }
}

void			Core::askInvent(const int n)
{
  int			ret;
  char			buff[8096 + 1];
  std::vector<std::string>	vec;
  std::string		s("pin " + its(n) + "\n");

  send(soc, &s[0], s.size(), 0);
  ret = recv(soc, buff, 8096, 0);
  if (ret == -1)
    throw (new Errur("Receive Fail"));
  buff[ret] = '\0';
  vec = p.parse(buff);
  if (vec[0] != "-1")
    {
      std::cout << "Commande(" << vec[0] << ") = " << buff << "<<" << std::endl;
      (this->*funcs[sti(vec[0])])(vec);
    }
}
