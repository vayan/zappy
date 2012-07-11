#include	"Player.hh"

void	Player::initTab()
{
	fctTable[1] = &Player::Pond;
	trTable[1][OK] = 15;
	fctTable[8] = &Player::SearchNourriture;
	trTable[8][OK] = 16;
	trTable[8][GODIR] = 11;
	trTable[8][KO] = 12;
	fctTable[11] = &Player::GoToDir;
	trTable[11][OK] = 15;
	fctTable[12] = &Player::Avance;
	trTable[12][OK] = 15;
	fctTable[13] = &Player::CallRenfort;
	trTable[13][OK] = 14;
	fctTable[14] = &Player::IfFoodSup10;
	trTable[14][OK] = 13;
	trTable[14][KO] = 8;
	fctTable[15] = &Player::PlaceSurServeur;
	trTable[15][OK] = 17;
	trTable[15][KO] = 13;
	fctTable[16] = &Player::RamassezAllNourriture;
	trTable[16][OK] = 8;
	trTable[16][KO] = 15;
	fctTable[17] = &Player::Eclosion2;
	trTable[17][OK] = 13;
	fctTable[18] = &Player::RamassezAllNourriture;
	trTable[18][OK] = 2;
	trTable[18][KO] = 2;
	fctTable[2] = &Player::RecvRenfort;
	trTable[2][OK] = 59;
	trTable[2][GODIR] = 21;
	trTable[2][KO] = 2;
	fctTable[21] = &Player::GoToDir;
	trTable[21][OK] = 18;
	fctTable[59] = &Player::Expulse;
	trTable[59][OK] = 18;
}