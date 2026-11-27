#include "../../header/game.h"

void insertLastGame(ListGame &L, adrGame p) {
    if (isEmptyGame(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

adrGame findGame(ListGame L, string idGame) {
    adrGame p = L.first;
    while (p != NULL) {
        if (p->info.idGame == idGame) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deleteGameByID(ListGame &L, string idGame, adrGame &p) {
    adrGame target = findGame(L, idGame);
    if (target == NULL) {
        p = NULL;
    } else if (target == L.first && target == L.last) {
        p = target;
        L.first = NULL;
        L.last = NULL;
    } else if (target == L.first) {
        p = target;
        L.first = p->next;
        L.first->prev = NULL;
        p->next = NULL;
    } else if (target == L.last) {
        p = target;
        L.last = p->prev;
        L.last->next = NULL;
        p->prev = NULL;
    } else {
        p = target;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = NULL;
        p->prev = NULL;
    }
}

void printAllGame(ListGame L) {
    if (isEmptyGame(L)) {
        cout << "Data Game kosong." << endl;
        return;
    }
    adrGame p = L.first;
    while (p != NULL) {
        cout << "[" << p->info.idGame << "] " << p->info.judulGame
             << " | Genre: " << p->info.genre
             << " | Rating: " << p->info.rating << endl;
        p = p->next;
    }
}
