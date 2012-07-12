//
// Player.hh for Player in /home/haulot_a//zappy-2015-2014s-haulot_a/client
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed Jun 13 10:36:21 2012 alexandre haulotte
// Last update Thu Jul 12 16:55:30 2012 alexandre haulotte
//

#ifndef	__PLAYER_HH__
#define	__PLAYER_HH__

#include	<vector>
#include	<map>
#include	<iostream>
#include	<string>
#include        <sys/time.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <unistd.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <netdb.h>
#include        <sstream>
#include        <stdlib.h>
#include 	<algorithm>
#include 	<iterator>
#include	"Errur.hh"

class Player
{
protected:
  int							_x;
  int							_y;
  int							_width;
  int							_height;
  int							_dir;
  int							_lvl;
  int							_ressource[7];
  std::map< int, std::map< int, std::vector<int> > >	_map;
  int							_id;
  std::string						_teamName;
  int 							_lvlTab[7][7];

protected:
  int				_soc;
  int				_port;
  std::string			_addr;
  std::vector<std::string>	_msg;
  int				_compo;
  std::string			_lastRep;
  int				_cState;
  std::string			_spam;

public:
  Player(int port, std::string ip, std::string team, int compo = 0, int id = 0);
  Player(int compo = 0);
  ~Player();
  void				connexion();
  void				play();
  void				recInfo();
  void				parse(int ac, char **av);
  int				strToInt(char* str);
  int				xrecv();
  int				xsend(int soc, const void* msg, int size, int flag);
  std::string			intToStr(int i);
  void    			initTab();
  std::vector<std::string>	split_to_vec(std::string , std::string);
  void 				Tokenize(const std::string& str,
					 std::vector<std::string>& tokens,
					 const std::string& delimiters);
  int     			searchDir(std::vector<std::string>, std::string);

public:
  //-------------------------------------//
  //--------------- GETTER --------------//
  //-------------------------------------//
  int							getX() const;
  int							getY() const;
  int							getWidth() const;
  int							getHeight() const;
  int							getDir() const;
  int							getLvl() const;
  int							getRessource(int r) const;
  std::map< int, std::map< int, std::vector<int> > >	getMap() const;
  int							getId() const;

  //-------------------------------------//
  //--------------- SETTER --------------//
  //-------------------------------------//
  void	setX(int x);
  void	setY(int y);
  void	setDir(int dir);
  void	setLvl(int lvl);
  void	setRessource(int r, int nb);
  void	initCase(int x, int y);
  void	setMap(int x, int y, int p, int nb);

  //----------------------------------------------//
  //--------------- GenericBloc ------------------//
  //----------------------------------------------//
  int	Avance(); // OK - ERR
  int	Droite(); // OK - ERR
  int	Expulse(); // OK - ERR
  int	Gauche(); // OK - ERR
  int	Pond(); // OK - ERR
  int	Eclosion(); // OK
  int	Eclosion2(); // OK
  int	Eclosion3(); // OK
  int	Eclosion4(); // OK
  int	Eclosion5(); // OK
  int	Incantation(); // OK - KO - ERR
  //  int	IncantationPassive(); // OK - KO - ERR
  int	GoToDir(); // OK - ERR
  int	VideCase(); // OK - ERR
  int	Inventaire(); // OK - ERR
  int	Voir(); // OK - ERR
  int	MyLvl(); // UN - DEUX - TROIS - QUATRE - CINQ - SIX - SEPT
  int	RaZRenfort(); // OK
  int	RaZGPondu(); // OK

  //----------------------------------------------//
  //--------------- SearchBloc -------------------//
  //----------------------------------------------//
  int	SearchNourriture(); // OK - GODIR - KO - ERR
  int	SearchLinemate(); // OK - GODIR - KO - ERR
  int	SearchDeraumere(); // OK - GODIR - KO - ERR
  int	SearchSibur(); // OK - GODIR - KO - ERR
  int	SearchMendiane(); // OK - GODIR - KO - ERR
  int	SearchPhiras(); // OK - GODIR - KO - ERR
  int	SearchThystame(); // OK - KO - ERR
  int	SearchRessourceForLvl(); // OK - GODIR - KO - ALREADY - ERR

  //----------------------------------------------//
  //----------------- TakeBloc -------------------//
  //----------------------------------------------//

  int	RamassezNourriture(); // OK - KO - ERR
  int	RamassezAllNourriture(); // OK - KO - ERR
  int	RamassezLinemate(); // OK - KO - ERR
  int	RamassezDeraumere(); // OK - KO - ERR
  int	RamassezSibur(); // OK - KO - ERR
  int	RamassezMendiane(); // OK - KO - ERR
  int	RamassezPhiras(); // OK - KO - ERR
  int	RamassezThystame(); // OK - KO - ERR
  int	RamassezRessourceForLvl(); // OK - KO - ERR

  //----------------------------------------------//
  //----------------- PoseBloc -------------------//
  //----------------------------------------------//

  int     PoserNourriture(); // OK - KO - ERR
  int     PoserLinemate(); // OK - KO - ERR
  int     PoserDeraumere(); // OK - KO - ERR
  int     PoserSibur(); // OK - KO - ERR
  int     PoserMendiane(); // OK - KO - ERR
  int     PoserPhiras(); // OK - KO - ERR
  int     PoserThystame(); // OK - KO - ERR
  int     PoserRessourceForLvl(); // OK - KO - ERR

  //----------------------------------------------//
  //----------------- TestBloc -------------------//
  //----------------------------------------------//

  int	AssezRessourceForLvl(); // OK - KO
  int	PlaceSurServeur(); // OK - KO - ERR
  int	AssezPlayerForLvl(); // OK - KO - ERR
  int	CaseReady(); // OK - KO - ERR
  int	JoueurSurCase(); // OK - KO - ERR
  int	GPondu(); // OK - KO

  //----------------------------------------------//
  //----------------- MsgBloc -------------------//
  //----------------------------------------------//

  int	CallRenfort(); // OK - ERR
  int	RecvRenfort(); // OK - GODIR - KO - ERR
  int	CallJGLR(); // OK - ERR (JeGereLesResource)
  int	RecvJGLR(); // OK - KO - ERR
  int	CallArrive(); // OK - ERR
  int	CallRenfortOK(); // OK - ERR
  int	RecvArrive(); // OK - KO - ERR
  int	Spam(); // OK - KO - ERR
  int   GetSpam(); // OK - KO - ERR

  //----------------------------------------------//
  //----------------- AlgoBloc -------------------//
  //----------------------------------------------//

  int	While5(); // OK - LOOP
  int	While10(); // OK - LOOP
  int	IfIsRenf(); // OK - KO
  int	IfFoodSup5(); // OK - KO - ERR
  int	IfFoodSup10(); // OK - KO - ERR
  int	IfFoodSup30(); // OK - KO - ERR
  int	IfFoodSup50(); // OK - KO - ERR

  //-----------------EndIAFunc--------------------//

  int	rDir;
  bool	isRenf;
  int	_nbRenf;
  bool	gPondu;
  typedef int (Player::*fct)();
  std::map<int, std::map<int, int> > trTable;
  std::map<int, fct > fctTable;

public:
  enum Direction
    {
      NORD = 1,
      EST = 2,
      SUD = 3,
      OUEST = 4
    };

  enum Ressources
    {
      FOOD,
      LINEMATE,
      DERAUMERE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };

  enum  Retour
    {
      KO,
      OK,
      LOOP,
      ALREADY,
      GODIR,
      UN,
      DEUX,
      TROIS,
      QUATRE,
      CINQ,
      SIX,
      SEPT,
      ERR
    };

};

#endif
