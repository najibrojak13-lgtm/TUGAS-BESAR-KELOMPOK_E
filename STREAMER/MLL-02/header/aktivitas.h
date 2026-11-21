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

//typedef infotypeAktivitas infotype;        // variabel alias untuk info
typedef struct elmAktivitas *adrAktivitas;  // variabel alias untuk pointer

// kerangka dari elemen list
struct elmAktivitas
{
    infotypeAktivitas info;
    adrAktivitas next;
    adrAktivitas prev;
};

// kerangka dari list
struct ListAktivitas
{
    adrAktivitas first;
    adrAktivitas last;
};

// pengecekan apakah list kosong
bool isEmptyAktivitas(ListAktivitas L);
/* I.S. list L terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void createListAktivitas(ListAktivitas &L);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
adrAktivitas alokasiAktivitas(infotypeAktivitas x);
/* I.S. info aktivitas x terdefinisi
   F.S. mengembalikan alamat elemen aktivitas berisi x, next NULL, dan prev NULL */

void dealokasiAktivitas(adrAktivitas &P);
/* I.S. pointer P terdefinisi
   F.S. elemen aktivitas di-dealokasi */

// pencarian sebuah elemen list
adrAktivitas findElmAktivitas(ListAktivitas L, string tanggal);
/* I.S. list L milik game dan tanggal aktivitas terdefinisi
   F.S. mengembalikan alamat elemen aktivitas yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirstAktivitas(ListAktivitas &L, adrAktivitas P);
/* I.S. terdefinisi list L yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfterAktivitas(ListAktivitas &L, adrAktivitas Prec, adrAktivitas P);
/* I.S. terdefinisi list L yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLastAktivitas(ListAktivitas &L, adrAktivitas P);
/* I.S. terdefinisi list L yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirstAktivitas(ListAktivitas &L, adrAktivitas &P);
/* I.S. terdefinisi list L yang mungkin kosong dan elemen list P
   F.S. P adalah alamat elemen pertama list yang akan dihapus dan elemen list selanjutnya
        akan menjadi elemen list pertama atau tidak ada elemen list pertama */

void deleteLastAktivitas(ListAktivitas &L, adrAktivitas &P);
/* I.S. terdefinisi list L yang mungkin kosong dan elemen list P
   F.S. P adalah alamat elemen terakhir list yang akan dihapus dan elemen list sebelumnya
        akan menjadi elemen list terakhir atau tidak ada elemen list terakhir */

void deleteAfterAktivitas(ListAktivitas &L, adrAktivitas Prec, adrAktivitas &P);
/* I.S. terdefinisi list L yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. P adalah alamat elemen list setelah Prec yang akan dihapus dan elemen list
        setelah P akan terhubung langsung dengan Prec atau tidak ada elemen list setelahnya */

// menampilkan data
void printInfoAktivitas(ListAktivitas L);
/* I.S. terdefinisi list L yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

// input data dari user
infotypeAktivitas inputAktivitas();
/* I.S. ~
   F.S. meminta data aktivitas dari user */

#endif // AKTIVITAS_H_INCLUDED