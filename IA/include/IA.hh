//
// IA.hh for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:06:09 2012 alexandre haulotte
// Last update Fri Jun 29 11:23:11 2012 alexandre haulotte
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

//----------------------------------------------//
//----------------- AlgoBloc -------------------//
//----------------------------------------------//

int	While5(); // OK - LOOP
int	While10(); // OK - LOOP
int	IfIsRenf(); // OK - KO
int	IfFoodSup10(); // OK - KO - ERR
int	IfFoodSup5(); // OK - KO - ERR
int	IfFoodSup30(); // OK - KO - ERR

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

// enum  cmd
//   {
//     AVANCE,
//     FORK,
//     LOOP_FUNC = 2500,
//     LOOP_PSS = 2501,
//     LOOP_RN = 2502,
//     LOOP_NSC = 2503,
//     LOOP_AN = 2504,
//     LOOP_I = 2505,
//     LOOP_RFLSC = 2506,
//     LOOP_RRFL = 2057
//   };

#endif
