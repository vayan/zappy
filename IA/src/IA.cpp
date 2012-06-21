//
// IA.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:51:45 2012 alexandre haulotte
// Last update Thu Jun 21 12:17:55 2012 alexandre haulotte
//

#include	"Player.hh"

void	Player::initTab()
{
  // ------------------ Lapin Mania ----------------//
  trTable[1][OK] = 2;
  trTable[2][OK] = 6;
  trTable[3][OK] = 7;
  trTable[3][KO] = 4;
  trTable[4][OK] = 1;
  trTable[4][GODIR] = 9;
  trTable[4][KO] = 5;
  trTable[5][OK] = 4;
  trTable[6][OK] = 7;
  trTable[6][KO] = 5;
  trTable[7][OK] = 8;
  trTable[7][KO] = 9;
  trTable[8][OK] = 9;
  trTable[9][OK] = 4;
  trTable[9][KO] = 4;

  fctTable[1] = &Player::Pond;
  fctTable[2] = &Player::Avance;
  fctTable[3] = &Player::AssezNourriture;
  fctTable[4] = &Player::SearchNourriture;
  fctTable[5] = &Player::Avance;
  fctTable[6] = &Player::RamassezNourriture;
  fctTable[7] = &Player::PlaceSurServeur;
  fctTable[8] = &Player::Eclosion;
  fctTable[9] = &Player::GoToDir;

  // ------------------ Avance Ramasse... ------------------//
  // trTable[1][OK] = 2;
  // trTable[1][KO] = 3;
  // trTable[2][OK] = 1;
  // trTable[3][OK] = 4;
  // trTable[3][GODIR] = 6;
  // trTable[3][KO] = 5;
  // trTable[4][OK] = 2;
  // trTable[4][KO] = 5;
  // trTable[5][OK] = 3;
  // trTable[6][OK] = 3;
  // trTable[6][KO] = 3;


  // fctTable[1] = &Player::AssezNourriture;
  // fctTable[2] = &Player::Avance;
  // fctTable[3] = &Player::SearchNourriture;
  // fctTable[4] = &Player::RamassezAllNourriture;
  // fctTable[5] = &Player::Avance;
  // fctTable[6] = &Player::GoToDir;

  // ------------------ Monte Level ----------------//
  // trTable[1][OK] = 2;
  // trTable[2][OK] = 6;
  // trTable[2][KO] = 3;
  // trTable[2][ALREADY] = 8;
  // trTable[3][OK] = 17;
  // trTable[4][OK] = 5;
  // trTable[4][KO] = 27;
  // trTable[5][OK] = 27;
  // trTable[6][OK] = 7;
  // trTable[6][KO] = 3;
  // trTable[7][OK] = 8;
  // trTable[7][KO] = 3;
  // trTable[8][OK] = 9;
  // trTable[9][OK] = 10;
  // trTable[9][KO] = 12;
  // trTable[10][OK] = 24;
  // trTable[10][KO] = 7;
  // trTable[11][OK] = 22;
  // trTable[11][KO] = 24;
  // trTable[12][OK] = 13;
  // trTable[12][KO] = 14;
  // trTable[13][OK] = 25;
  // trTable[13][KO] = 8;
  // trTable[14][OK] = 28;
  // trTable[15][OK] = 16;
  // trTable[15][KO] = 18;
  // trTable[16][OK] = 18;
  // trTable[17][OK] = 4;
  // trTable[18][OK] = 9;
  // trTable[18][KO] = 19;
  // trTable[19][OK] = 20;
  // trTable[20][OK] = 21;
  // trTable[20][KO] = 19;
  // trTable[21][OK] = 9;
  // trTable[21][KO] = 19;
  // trTable[22][OK] = 23;
  // trTable[22][KO] = 7;
  // trTable[23][OK] = 26;
  // trTable[23][KO] = 22;
  // trTable[24][OK] = 11;
  // trTable[24][KO] = 7;
  // trTable[25][OK] = 11;
  // trTable[25][KO] = 25;
  // trTable[26][OK] = 11;
  // trTable[26][KO] = 7;
  // trTable[27][OK] = 23;
  // trTable[27][KO] = 2;
  // trTable[28][OK] = 24;
  // trTable[28][KO] = 14;

  // fctTable[1] = &Player::Pond;
  // fctTable[2] = &Player::RessourceForLvlSurCase;
  // fctTable[3] = &Player::Avance;
  // fctTable[4] = &Player::PlaceSurServeur;
  // fctTable[5] = &Player::Eclosion;
  // fctTable[6] = &Player::RamassezRessourceForLvl;;
  // fctTable[7] = &Player::AssezRessourceForLevel;
  // fctTable[8] = &Player::VideCase;
  // fctTable[9] = &Player::AssezPlayerForLvl;
  // fctTable[10] = &Player::PoserRessourceForLvl;
  // fctTable[11] = &Player::Incantation;
  // fctTable[12] = &Player::RecvRenfort;
  // fctTable[13] = &Player::GoToMsgRenfort;
  // fctTable[14] = &Player::CallRenfort;
  // fctTable[15] = &Player::PlaceSurServeur;
  // fctTable[16] = &Player::Eclosion;
  // fctTable[17] = &Player::VideCase;
  // fctTable[18] = &Player::AssezNourriture;
  // fctTable[19] = &Player::Avance;
  // fctTable[20] = &Player::NourritureSurCase;
  // fctTable[21] = &Player::RamassezAllNourriture;
  // fctTable[22] = &Player::RecvRenfort;
  // fctTable[23] = &Player::GoToMsgRenfort;
  // fctTable[24] = &Player::CaseReady;
  // fctTable[25] = &Player::CaseReady;
  // fctTable[26] = &Player::CaseReady;
  // fctTable[27] = &Player::RecvRenfort;
  // fctTable[28] = &Player::AssezPlayerForLvl;

  // ------------------ Retrouvaille... ------------------//
  // trTable[1][OK] = 2;
  // trTable[1][KO] = 1;
  // trTable[2][OK] = 3;
  // trTable[3][OK] = 3;
  // trTable[4][GODIR] = 5;
  // trTable[4][KO] = 4;
  // trTable[5][OK] = 4;
  // trTable[5][KO] = 4;
  // trTable[6][OK] = 4;
  // trTable[6][KO] = 4;

  // fctTable[1] = &Player::PlaceSurServeur;
  // fctTable[2] = &Player::Eclosion;
  // fctTable[3] = &Player::CallRenfort;
  // fctTable[4] = &Player::RecvRenfort;
  // fctTable[5] = &Player::GoToDir;
  //  fctTable[6] = &Player::VideCase;

  // ------------------ IA Simple ------------------//
  // trTable[1][OK] = 2;
  // trTable[1][KO] = 3;
  // trTable[2][OK] = 3;
  // trTable[3][OK] = 4;
  // trTable[3][KO] = 16;
  // trTable[4][OK] = 5;
  // trTable[4][KO] = 12;
  // trTable[5][OK] = 6;
  // trTable[6][OK] = 7;
  // trTable[6][KO] = 3;
  // trTable[7][OK] = 8;
  // trTable[7][LOOP] = 7;
  // trTable[7][KO] = 4;
  // trTable[8][OK] = 3;
  // trTable[8][KO] = 3;
  // trTable[9][OK] = 10;
  // trTable[9][KO] = 11;
  // trTable[9][ALREADY] = 4;
  // trTable[10][OK] = 11;
  // trTable[10][KO] = 11;
  // trTable[11][OK] = 3;
  // trTable[12][OK] = 13;
  // trTable[12][KO] = 14;
  // trTable[13][OK] = 15;
  // trTable[13][KO] = 16;
  // trTable[14][OK] = 4;
  // trTable[15][OK] = 8;
  // trTable[15][LOOP] = 15;
  // trTable[15][KO] = 3;
  // trTable[16][OK] = 13;
  // trTable[16][KO] = 10;
  // trTable[18][OK] = 15;
  // trTable[18][KO] = 17;
  // trTable[17][OK] = 5;

  // fctTable[1] = &Player::PlaceSurServeur;
  // fctTable[2] = &Player::Eclosion;
  // fctTable[3] = &Player::AssezRessourceForLevel;
  // fctTable[4] = &Player::AssezPlayerForLvl;
  // fctTable[5] = &Player::VideCase;
  // fctTable[6] = &Player::PoserRessourceForLvl;
  // fctTable[7] = &Player::CaseReady;
  // fctTable[8] = &Player::Incantation;
  // fctTable[9] = &Player::RessourceForLvlSurCase;
  // fctTable[10] = &Player::VideCase;
  // fctTable[11] = &Player::Avance;
  // fctTable[12] = &Player::RecvRenfort;
  // fctTable[13] = &Player::GoToMsgRenfort;
  // fctTable[14] = &Player::CallRenfort;
  // fctTable[15] = &Player::CaseReady;
  // fctTable[16] = &Player::RecvRenfort;
  // fctTable[17] = &Player::CallJGLR;
  // fctTable[18] = &Player::RecvJGLR;
  rDir = 0;
}
