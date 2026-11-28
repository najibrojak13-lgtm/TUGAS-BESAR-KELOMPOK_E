#include "../../header/aktivitas.h"

bool isEmptyAktivitas(ListAktivitas L)
{
    return L.first == NULL;
}

void createListAktivitas(ListAktivitas &L)
{
    L.first = NULL;
    L.last = NULL;
}

adrAktivitas alokasiAktivitas(infotypeAktivitas x)
{
    adrAktivitas P = new elmAktivitas;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiAktivitas(adrAktivitas &P)
{
    delete P;
    P = NULL;
}

adrAktivitas findElmAktivitas(ListAktivitas L, string tanggal)
{
    adrAktivitas P = L.first;
    while (P != NULL && P->info.tanggal != tanggal)
    {
        P = P->next;
    }
    return P; // NULL jika tidak ditemukan
}

void insertFirstAktivitas(ListAktivitas &L, adrAktivitas P)
{
    if (isEmptyAktivitas(L))
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}