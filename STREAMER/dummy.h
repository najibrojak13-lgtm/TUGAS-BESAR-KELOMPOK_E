#ifndef DUMMY_H_INCLUDED
#define DUMMY_H_INCLUDED

#include "MLL-02/header/streamer.h"
#include "MLL-02/header/game.h"
#include "MLL-02/header/aktivitas.h"
#include "BST/header/sesi_streaming.h"

void runDummyStreamer(ListStreamer &LS);
void runDummyGame(ListGame &LG);
void runDummyAktivitas(ListAktivitas &LA);
void runDummySesiBST(BSTSesi &TBS);
void runAllDummy();

#endif // DUMMY_H_INCLUDED
