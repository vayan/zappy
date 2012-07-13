#include	"Player.hh"

void	Player::initTab()
{
	fctTable[1] = &Player::Avance;
	trTable[1][OK] = 12;
	fctTable[7] = &Player::GoToDir;
	trTable[7][OK] = 11;
	fctTable[10] = &Player::RamassezNourriture;
	trTable[10][OK] = 12;
	trTable[10][KO] = 12;
	fctTable[11] = &Player::SearchNourriture;
	trTable[11][OK] = 10;
	trTable[11][GODIR] = 7;
	trTable[11][KO] = 13;
	fctTable[12] = &Player::IfFoodSup10;
	trTable[12][OK] = 1;
	trTable[12][KO] = 11;
	fctTable[13] = &Player::Avance;
	trTable[13][OK] = 11;
}