#include	"Player.hh"

void	Player::initTab()
{
	fctTable[7] = &Player::While10;
	trTable[7][OK] = 25;
	trTable[7][LOOP] = 8;
	fctTable[8] = &Player::Avance;
	trTable[8][OK] = 12;
	fctTable[9] = &Player::Gauche;
	trTable[9][OK] = 8;
	fctTable[1] = &Player::Pond;
	trTable[1][OK] = 8;
	fctTable[11] = &Player::Eclosion;
	trTable[11][OK] = 9;
	fctTable[12] = &Player::VideCase;
	trTable[12][OK] = 7;
	fctTable[13] = &Player::PlaceSurServeur;
	trTable[13][OK] = 11;
	trTable[13][KO] = 14;
	fctTable[14] = &Player::AssezRessourceForLvl;
	trTable[14][OK] = 38;
	trTable[14][KO] = 9;
	fctTable[15] = &Player::Incantation;
	trTable[15][OK] = 9;
	trTable[15][KO] = 9;
	fctTable[25] = &Player::SearchNourriture;
	trTable[25][OK] = 13;
	trTable[25][GODIR] = 26;
	trTable[25][KO] = 13;
	fctTable[26] = &Player::GoToDir;
	trTable[26][OK] = 25;
	fctTable[38] = &Player::VideCase;
	trTable[38][OK] = 39;
	fctTable[39] = &Player::PoserRessourceForLvl;
	trTable[39][OK] = 15;
	trTable[39][KO] = 25;
}