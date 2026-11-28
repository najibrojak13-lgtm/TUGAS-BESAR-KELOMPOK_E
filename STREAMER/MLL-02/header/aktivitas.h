#ifndef AKTIVITAS_H_INCLUDED
#define AKTIVITAS_H_INCLUDED
#include "game.h"
#include <string>
#include <iostream>

using namespace std;

struct infotypeAktivitas
{
    string tanggal;
    string status;
    string tingkatan;
};
typedef struct elmAktivitas *adrAktivitas;  
struct elmAktivitas
{
    infotypeAktivitas info;
    adrAktivitas next;
    adrAktivitas prev;
};
struct ListAktivitas
{
    adrAktivitas first;
    adrAktivitas last;
};
bool isEmptyAktivitas(ListAktivitas L);
void createListAktivitas(ListAktivitas &L);
adrAktivitas alokasiAktivitas(infotypeAktivitas x);
void dealokasiAktivitas(adrAktivitas &P);
adrAktivitas findElmAktivitas(ListAktivitas L, string tanggal);
void insertFirstAktivitas(ListAktivitas &L, adrAktivitas P);
void insertAfterAktivitas(ListAktivitas &L, adrAktivitas Prec, adrAktivitas P);
void insertLastAktivitas(ListAktivitas &L, adrAktivitas P);
void deleteFirstAktivitas(ListAktivitas &L, adrAktivitas &P);
void deleteLastAktivitas(ListAktivitas &L, adrAktivitas &P);
void deleteAfterAktivitas(ListAktivitas &L, adrAktivitas Prec, adrAktivitas &P);
void printInfoAktivitas(ListAktivitas L);
infotypeAktivitas inputAktivitas();
#endif // AKTIVITAS_H_INCLUDED