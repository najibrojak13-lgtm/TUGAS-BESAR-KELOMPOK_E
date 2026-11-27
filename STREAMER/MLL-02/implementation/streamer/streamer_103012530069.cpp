#include "../../header/streamer.h"

void insertAfterStreamer(ListStreamer &L, adrStreamer prec, adrStreamer p) {
    if (prec != NULL) {
        if (prec == L.last) {
            insertLastStreamer(L, p);
        } else {
            p->next = prec->next;
            p->prev = prec;
            prec->next->prev = p;
            prec->next = p;
        }
    }
}

adrStreamer findStreamer(ListStreamer L, string idStreamer) {
    adrStreamer p = L.first;
    while (p != NULL) {
        if (p->info.idStreamer == idStreamer) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deleteFirstStreamer(ListStreamer &L, adrStreamer &p) {
    if (!isEmptyStreamer(L)) {
        p = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = p->next;
            L.first->prev = NULL;
            p->next = NULL;
        }
    } else {
        p = NULL;
    }
}

void deleteLastStreamer(ListStreamer &L, adrStreamer &p) {
    if (!isEmptyStreamer(L)) {
        p = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = p->prev;
            L.last->next = NULL;
            p->prev = NULL;
        }
    } else {
        p = NULL;
    }
}

void deleteStreamerByID(ListStreamer &L, string idStreamer, adrStreamer &p) {
    adrStreamer target = findStreamer(L, idStreamer);
    if (target == NULL) {
        p = NULL;
    } else if (target == L.first) {
        deleteFirstStreamer(L, p);
    } else if (target == L.last) {
        deleteLastStreamer(L, p);
    } else {
        p = target;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = NULL;
        p->prev = NULL;
    }
}

void printAllStreamer(ListStreamer L) {
    if (isEmptyStreamer(L)) {
        cout << "Data Streamer kosong." << endl;
        return;
    }
    adrStreamer p = L.first;
    while (p != NULL) {
        cout << "[" << p->info.idStreamer << "] " << p->info.namaStreamer
             << " | Platform: " << p->info.platform
             << " | Follower: " << p->info.jumlahFollower << endl;
        p = p->next;
    }
}
