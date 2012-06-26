//
// IA.cpp for IA in /home/haulot_a//zappy-2015-2014s-haulot_a/IA
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Thu Jun 14 12:51:45 2012 alexandre haulotte
// Last update Tue Jun 26 10:20:41 2012 alexandre haulotte
//

#include	"Player.hh"

void	Player::initTab()
{
  // ------------------ Test IA 3 ----------------//

  // Compo 1
  trTable[1][OK] = 2;
  trTable[2][OK] = 3;
  trTable[2][KO] = 9;
  trTable[3][OK] = 4;
  trTable[3][KO] = 2;
  trTable[4][OK] = 1;
  trTable[5][OK] = 7;
  trTable[5][GODIR] = 6;
  trTable[5][KO] = 8;
  trTable[6][OK] = 5;
  trTable[7][OK] = 2;
  trTable[7][KO] = 5;
  trTable[8][OK] = 5;
  trTable[9][LOOP] = 5;
  trTable[9][OK] = 2;


  fctTable[1] = &Player::Pond;
  fctTable[2] = &Player::IfFoodSup30;
  fctTable[3] = &Player::PlaceSurServeur;
  fctTable[4] = &Player::Eclosion;
  fctTable[5] = &Player::SearchNourriture;
  fctTable[6] = &Player::GoToDir;
  fctTable[7] = &Player::RamassezAllNourriture;
  fctTable[8] = &Player::Avance;
  fctTable[9] = &Player::While10;

  // Compo 2
  trTable[10][OK] = 16;
  trTable[10][KO] = 11;
  trTable[11][LOOP] = 12;
  trTable[11][OK] = 10;
  trTable[12][OK] = 15;
  trTable[12][GODIR] = 13;
  trTable[12][KO] = 14;
  trTable[13][OK] = 12;
  trTable[14][OK] = 12;
  trTable[15][OK] = 11;
  trTable[15][KO] = 12;
  trTable[16][OK] = 19;
  trTable[16][GODIR] = 18;
  trTable[16][KO] = 17;
  trTable[17][OK] = 32;
  trTable[17][KO] = 23;
  trTable[18][OK] = 35;
  trTable[19][LOOP] = 39;
  trTable[19][OK] = 20;
  trTable[19][KO] = 39;
  trTable[20][OK] = 10;
  trTable[20][LOOP] = 21;
  trTable[21][OK] = 41;
  trTable[21][KO] = 20;
  trTable[22][OK] = 28;
  trTable[22][KO] = 33;
  trTable[23][OK] = 34;
  trTable[23][GODIR] = 24;
  trTable[23][KO] = 10;
  trTable[24][OK] = 23;
  trTable[25][OK] = 10;
  trTable[25][KO] = 23;
  //  trTable[26][OK] = 23;
  trTable[27][OK] = 31;
  trTable[28][OK] = 29;
  trTable[28][KO] = 10;
  trTable[29][OK] = 30;
  trTable[29][KO] = 10;
  trTable[29][LOOP] = 29;
  trTable[30][OK] = 41;
  trTable[30][KO] = 10;
  trTable[31][OK] = 10;
  trTable[31][LOOP] = 22;
  trTable[32][OK] = 22;
  trTable[32][KO] = 10;
  trTable[33][OK] = 19;
  trTable[33][GODIR] = 18;
  trTable[33][KO] = 27;
  trTable[34][OK] = 26;
  trTable[34][KO] = 25;
  trTable[35][OK] = 19;
  trTable[35][GODIR] = 18;
  trTable[35][KO] = 36;
  trTable[36][OK] = 16;
  trTable[36][LOOP] = 35;
  // trTable[37][OK] = 16;
  // trTable[37][LOOP] = 19;
  // trTable[38][OK] = 10;
  // trTable[38][LOOP] = 11;
  trTable[39][OK] = 40;
  trTable[39][KO] = 10;
  trTable[40][OK] = 19;
  trTable[40][KO] = 10;
  trTable[41][UN] = 10;
  trTable[41][DEUX] = 10;
  trTable[41][TROIS] = 10;
  trTable[41][QUATRE] = 10;
  trTable[41][CINQ] = 10;
  trTable[41][SIX] = 10;
  trTable[41][SEPT] = 42;

  fctTable[10] = &Player::IfFoodSup30;
  fctTable[11] = &Player::While5;
  fctTable[12] = &Player::SearchNourriture;
  fctTable[13] = &Player::GoToDir;
  fctTable[14] = &Player::Avance;
  fctTable[15] = &Player::RamassezAllNourriture;
  fctTable[16] = &Player::RecvRenfort;
  fctTable[17] = &Player::AssezRessourceForLevel;
  fctTable[18] = &Player::GoToDir;
  fctTable[19] = &Player::CaseReady;
  fctTable[20] = &Player::While5;
  fctTable[21] = &Player::Incantation;
  fctTable[22] = &Player::AssezPlayerForLvl;
  fctTable[23] = &Player::SearchRessourceForLvl;
  fctTable[24] = &Player::GoToDir;
  fctTable[25] = &Player::VideCase;
  //fctTable[26] = &Player::Avance;
  fctTable[27] = &Player::CallRenfort;
  fctTable[28] = &Player::PoserRessourceForLvl;
  fctTable[29] = &Player::CaseReady;
  fctTable[30] = &Player::Incantation;
  fctTable[31] = &Player::While10;
  fctTable[32] = &Player::VideCase;
  fctTable[33] = &Player::RecvRenfort;
  fctTable[34] = &Player::JoueurSurCase;
  fctTable[35] = &Player::RecvRenfort;
  fctTable[36] = &Player::While5;
  //fctTable[37] = &Player::While10;
  //fctTable[38] = &Player::While5;
  fctTable[39] = &Player::IfFoodSup10;
  fctTable[40] = &Player::JoueurSurCase;
  fctTable[41] = &Player::MyLvl;


  // Compo 3
  trTable[42][OK] = 43;
  trTable[42][KO] = 52;
  trTable[43][OK] = 45;
  trTable[43][KO] = 48;
  trTable[43][GODIR] = 44;
  trTable[44][OK] = 61;
  trTable[45][OK] = 51;
  trTable[45][KO] = 47;
  trTable[47][OK] = 45;
  trTable[47][KO] = 42;
  trTable[48][OK] = 49;
  trTable[48][KO] = 56;
  trTable[49][OK] = 60;
  trTable[50][KO] = 42;
  trTable[50][OK] = 51;
  trTable[51][KO] = 42;
  trTable[51][OK] = 1;
  trTable[52][GODIR] = 53;
  trTable[52][OK] = 55;
  trTable[52][KO] = 54;
  trTable[53][OK] = 52;
  trTable[54][KO] = 52;
  trTable[55][OK] = 42;
  trTable[55][KO] = 52;
  trTable[56][OK] = 58;
  trTable[56][KO] = 42;
  trTable[56][GODIR] = 57;
  trTable[57][OK] = 56;
  trTable[58][KO] = 56;
  trTable[58][OK] = 42;
  trTable[59][KO] = 56;
  trTable[60][OK] = 62;
  trTable[60][KO] = 49;
  trTable[61][OK] = 45;
  trTable[61][KO] = 61;
  trTable[61][GODIR] = 44;
  trTable[62][KO] = 42;
  trTable[62][OK] = 50;

  fctTable[42] = &Player::IfFoodSup10;
  fctTable[43] = &Player::RecvRenfort;
  fctTable[44] = &Player::GoToDir;
  fctTable[45] = &Player::CaseReady;
  fctTable[46] = &Player::Incantation;
  fctTable[47] = &Player::IfFoodSup5;
  fctTable[48] = &Player::AssezRessourceForLevel;
  fctTable[49] = &Player::CallRenfort;
  fctTable[50] = &Player::PoserRessourceForLvl;
  fctTable[51] = &Player::Incantation;
  fctTable[52] = &Player::SearchNourriture;
  fctTable[53] = &Player::GoToDir;
  fctTable[54] = &Player::Avance;
  fctTable[55] = &Player::RamassezNourriture;
  fctTable[56] = &Player::SearchRessourceForLvl;
  fctTable[57] = &Player::GoToDir;
  fctTable[58] = &Player::RamassezRessourceForLvl;
  fctTable[59] = &Player::Avance;
  fctTable[60] = &Player::AssezPlayerForLvl;
  fctTable[61] = &Player::RecvRenfort;
  fctTable[62] = &Player::VideCase;
// ------------------ Lapin Mania ----------------//
  // trTable[1][OK] = 2;
  // trTable[2][OK] = 6;
  // trTable[3][OK] = 7;
  // trTable[3][KO] = 4;
  // trTable[4][OK] = 1;
  // trTable[4][GODIR] = 9;
  // trTable[4][KO] = 5;
  // trTable[5][OK] = 4;
  // trTable[6][OK] = 7;
  // trTable[6][KO] = 5;
  // trTable[7][OK] = 8;
  // trTable[7][KO] = 9;
  // trTable[8][OK] = 9;
  // trTable[9][OK] = 4;
  // trTable[9][KO] = 4;

  // fctTable[1] = &Player::Pond;
  // fctTable[2] = &Player::Avance;
  // fctTable[3] = &Player::IfFoodSup30;
  // fctTable[4] = &Player::SearchNourriture;
  // fctTable[5] = &Player::Avance;
  // fctTable[6] = &Player::RamassezNourriture;
  // fctTable[7] = &Player::PlaceSurServeur;
  // fctTable[8] = &Player::Eclosion;
  // fctTable[9] = &Player::GoToDir;

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


  // fctTable[1] = &Player::IfFoodSup30;
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
  // trTable[2][GODIR] = 29;
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
  // trTable[12][GODIR] = 14;
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
  // trTable[20][GODIR] = 30;
  // trTable[20][KO] = 19;
  // trTable[21][OK] = 9;
  // trTable[21][KO] = 19;
  // trTable[22][GODIR] = 23;
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
  // trTable[29][OK] = 2;
  // trTable[29][KO] = 2;
  // trTable[30][OK] = 20;
  // trTable[30][KO] = 20;

  // fctTable[1] = &Player::Pond;
  // fctTable[2] = &Player::SearchRessourceForLvl;
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
  // fctTable[13] = &Player::GoToDir;
  // fctTable[14] = &Player::CallRenfort;
  // fctTable[15] = &Player::PlaceSurServeur;
  // fctTable[16] = &Player::Eclosion;
  // fctTable[17] = &Player::VideCase;
  // fctTable[18] = &Player::IfFoodSup30;
  // fctTable[19] = &Player::Avance;
  // fctTable[20] = &Player::SearchNourriture;
  // fctTable[21] = &Player::RamassezAllNourriture;
  // fctTable[22] = &Player::RecvRenfort;
  // fctTable[23] = &Player::GoToDir;
  // fctTable[24] = &Player::CaseReady;
  // fctTable[25] = &Player::CaseReady;
  // fctTable[26] = &Player::CaseReady;
  // fctTable[27] = &Player::RecvRenfort;
  // fctTable[28] = &Player::AssezPlayerForLvl;
  // fctTable[29] = &Player::GoToDir;
  // fctTable[30] = &Player::GoToDir;

  // -------------- Retrouvaille...(player creator compo = 4) -------------//
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
  // trTable[9][GODIR] = 19;
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
  // trTable[16][GODIR] = 13;
  // trTable[16][KO] = 10;
  // trTable[18][GODIR] = 15;
  // trTable[18][KO] = 17;
  // trTable[17][OK] = 5;
  // trTable[19][OK] = 9;
  // trTable[19][KO] = 9;

  // fctTable[1] = &Player::PlaceSurServeur;
  // fctTable[2] = &Player::Eclosion;
  // fctTable[3] = &Player::AssezRessourceForLevel;
  // fctTable[4] = &Player::AssezPlayerForLvl;
  // fctTable[5] = &Player::VideCase;
  // fctTable[6] = &Player::PoserRessourceForLvl;
  // fctTable[7] = &Player::CaseReady;
  // fctTable[8] = &Player::Incantation;
  // fctTable[9] = &Player::SearchRessourceForLvl;
  // fctTable[10] = &Player::VideCase;
  // fctTable[11] = &Player::Avance;
  // fctTable[12] = &Player::RecvRenfort;
  // fctTable[13] = &Player::GoToDir;
  // fctTable[14] = &Player::CallRenfort;
  // fctTable[15] = &Player::CaseReady;
  // fctTable[16] = &Player::RecvRenfort;
  // fctTable[17] = &Player::CallJGLR;
  // fctTable[18] = &Player::RecvJGLR;
  // fctTable[19] = &Player::GoToDir;

  //------------------ SearchRessource (enlever linemate +1) ---------//
  // trTable[1][OK] = 3;
  // trTable[1][ALREADY] = 4;
  // trTable[1][GODIR] = 2;
  // trTable[1][KO] = 4;
  // trTable[2][OK] = 1;
  // trTable[2][KO] = 1;
  // trTable[3][OK] = 1;
  // trTable[3][KO] = 1;
  // trTable[4][OK] = 1;

  // fctTable[1] = &Player::SearchRessourceForLvl;
  // fctTable[2] = &Player::GoToDir;
  // fctTable[3] = &Player::VideCase;
  // fctTable[4] = &Player::Avance;

  //-------------------- Test ------------//
  // trTable[1][OK] = 4;
  // trTable[1][KO] = 3;
  // trTable[1][GODIR] = 2;
  // trTable[2][OK] = 1;
  // trTable[3][OK] = 1;
  // trTable[4][OK] = 1;
  // trTable[4][KO] = 1;

  // fctTable[1] = &Player::SearchNourriture;
  // fctTable[2] = &Player::GoToDir;
  // fctTable[3] = &Player::Avance;
  // fctTable[4] = &Player::RamassezNourriture;
  rDir = 0;
}
