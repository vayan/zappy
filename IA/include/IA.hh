//
// IA.hh for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:06:09 2012 alexandre haulotte
// Last update Tue Jun 19 13:57:08 2012 alexandre haulotte
//

#ifndef	__IA_HH__
#define	__IA_HH__


//----------------------------------------------//
//--------------- GenericBloc ------------------//
//----------------------------------------------//
int	Avance(); // OK - ERR
int	Droite(); // OK - ERR
int	Gauche(); // OK - ERR
int	Pond(); // OK - ERR
int	Eclosion(); // OK
int	Incantation(); // OK - KO - ERR
int	GoToMsgRenfort(); // OK - KO - ERR
int	VideCase(); // OK - ERR

//----------------------------------------------//
//--------------- SearchBloc -------------------//
//----------------------------------------------//
int	NourritureSurCase(); // OK - KO - ERR
int	LinemateSurCase(); // OK - KO - ERR
int	DeraumereSurCase(); // OK - KO - ERR
int	SiburSurCase(); // OK - KO - ERR
int	MendianeSurCase(); // OK - KO - ERR
int	PhirasSurCase(); // OK - KO - ERR
int	ThystameSurCase(); // OK - KO - ERR
int	RessourceForLvlSurCase(); // OK - KO - ALREADY - ERR

//----------------------------------------------//
//----------------- TakeBloc -------------------//
//----------------------------------------------//

int	RamassezNourriture(); // OK - KO - ERR
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

int	AssezNourriture(); // OK - KO - ERR
int	AssezRessourceForLevel(); // OK - KO
int	PlaceSurServeur(); // OK - KO - ERR
int	AssezPlayerForLvl(); // OK - KO - ERR

//----------------------------------------------//
//----------------- MsgBloc -------------------//
//----------------------------------------------//

int	CallRenfort(); // OK - ERR
int	RecvRenfort(); // OK - KO - ERR

//-----------------EndIAFunc--------------------//

int	rDir;

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
    ERR
  };

enum  cmd
  {
    AVANCE,
    FORK,
    LOOP_FUNC = 2500,
    LOOP_PSS = 2501,
    LOOP_RN = 2502,
    LOOP_NSC = 2503,
    LOOP_AN = 2504,
    LOOP_I = 2505,
    LOOP_RFLSC = 2506,
    LOOP_RRFL = 2057
  };

#endif
