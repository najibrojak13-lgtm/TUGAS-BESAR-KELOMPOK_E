#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
using namespace std;

/* ananda */

struct Game {
    string idGame;
    string judulGame;
    string genre;
    float rating;
};

typedef Game infotypeGame;
typedef struct ElmGame* adrGame;

struct ElmGame {
    infotypeGame info;
    adrGame next;
    adrGame prev;
};

struct ListGame {
    adrGame first;
    adrGame last;
};

void createListGame(ListGame &L);
bool isEmptyGame(ListGame L);
adrGame alokasiGame(infotypeGame x);
void dealokasiGame(adrGame &p);

void insertFirstGame(ListGame &L, adrGame p);
void insertLastGame(ListGame &L, adrGame p);
void deleteGameByID(ListGame &L, string idGame, adrGame &p);

adrGame findGame(ListGame L, string idGame);
void printAllGame(ListGame L);

#endif
