//
// Core.cpp for Core in /home/haulot_a//zappy-2015-2014s-haulot_a/client/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun  6 13:59:33 2012 alexandre haulotte
// Last update Tue Jun 12 10:27:20 2012 alexandre haulotte
//

#include 	<sstream>
#include	"Core.hh"

void			Core::go()
{
  int			ret;
  char			buff[8096 + 1];
  fd_set		readfds;
  struct timeval	tv;
  Parseur		p;

  init();
  ret = 1;
  tv.tv_sec = 0;
  tv.tv_usec = 200;
  send(soc, "GRAPHIC\n", 8, 0);
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  FD_SET(soc, &readfds);
  while (ret != 0 && (select(soc + 1, &readfds, NULL, NULL, &tv) != -1))
    {
      if (FD_ISSET(soc, &readfds))
	{
	  ret = recv(soc, buff, 8096, 0);
	  if (ret == -1)
	    throw (new Errur("Receive Fail"));
	  buff[ret] = '\0';
	  std::cout << buff << std::endl;
	  p.parse(buff);
	}
      buff[0] = '\0';
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
  if (ac < 5)
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  if (ac == 5)
    macName = "127.0.0.1";
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
	      teamName = &av[i + 1][0];
	      break;
	    case 'p':
	      port = strToInt(&av[i + 1][0]);
	      break;
	    case 'h':
	      macName = &av[i + 1][0];
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
  if (teamName == "" || port == 0 || macName == "")
    throw(new Errur("Usage : ./client -n nom_equipe -p port [-h nom machine]"));
  else
    {
      std::cout << "Team Name is : " << teamName << std::endl;
      std::cout << "Port is : " << port << std::endl;
      std::cout << "Host Name is : " << macName << std::endl;
    }
}

int	Core::strToInt(char* str)
{
  std::istringstream 	buffer(str);
  int 			nbr;

  buffer >> nbr;
  return (nbr);
}

std::string   Core::intToStr(int i)
{
  std::ostringstream oss;

  oss << i;
  return (oss.str());
}

Core::Core(int ac, char **av)
  :soc(0), teamName(""), macName(""), port(0)
{
  beginParse(ac, av);
}

Core::~Core()
{}
