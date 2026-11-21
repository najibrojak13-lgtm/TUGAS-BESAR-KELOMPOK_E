#ifndef STREAMER_H
#define STREAMER_H

#include <iostream>
#include <string>
using namespace std;

/* ananda */

struct Streamer {
    string idStreamer;
    string namaStreamer;
    string platform;
    int jumlahFollower;
};

typedef Streamer infotypeStreamer;
typedef struct ElmStreamer* adrStreamer;

struct ElmStreamer {
    infotypeStreamer info;
    adrStreamer next;
    adrStreamer prev;
};

struct ListStreamer {
    adrStreamer first;
    adrStreamer last;
};

void createListStreamer(ListStreamer &L);
bool isEmptyStreamer(ListStreamer L);
adrStreamer alokasiStreamer(infotypeStreamer x);
void dealokasiStreamer(adrStreamer &p);

void insertFirstStreamer(ListStreamer &L, adrStreamer p);
void insertLastStreamer(ListStreamer &L, adrStreamer p);
void insertAfterStreamer(ListStreamer &L, adrStreamer prec, adrStreamer p);

void deleteFirstStreamer(ListStreamer &L, adrStreamer &p);
void deleteLastStreamer(ListStreamer &L, adrStreamer &p);
void deleteStreamerByID(ListStreamer &L, string idStreamer, adrStreamer &p);

adrStreamer findStreamer(ListStreamer L, string idStreamer);
void printAllStreamer(ListStreamer L);

#endif
