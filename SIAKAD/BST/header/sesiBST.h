#ifndef SESISTREAMINGBST_H_INCLUDED
#define SESISTREAMINGBST_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

struct SesiStreaming
{
    string idSesi;
    string idStreamer;
    string idGame;
    string tanggalStreaming;
    int durasi;            // dalam menit atau detik sesuai kebutuhan
    int jumlahPenonton;
    int jumlahPenayangan;
    double pendapatan;
};

typedef SesiStreaming infotypeSesi;         // variabel alias untuk info
typedef struct nodeSesi *adrNodeSesi;       // variabel alias untuk pointer

// kerangka dari elemen node
struct nodeSesi
{
    infotypeSesi info;
    adrNodeSesi left;
    adrNodeSesi right;
};

// kerangka dari BST
struct BSTSesi
{
    adrNodeSesi root;
};

// pengecekan apakah BST kosong
bool isEmptySesi(BSTSesi T);
/* I.S. BST T terdefinisi
   F.S. true jika BST kosong dan false jika tidak kosong */

// pembuatan BST kosong
void createBSTSesi(BSTSesi &T);
/* I.S. ~
   F.S. terbentuk BST kosong */

// manajemen memori
adrNodeSesi alokasiSesi(infotypeSesi x);
/* I.S. info sesi x terdefinisi
   F.S. mengembalikan alamat node berisi x dengan anak kiri dan kanan NULL */

void dealokasiSesi(adrNodeSesi &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen node
adrNodeSesi findNodeSesi(BSTSesi T, string idSesi);
/* I.S. BST T dan idSesi terdefinisi
   F.S. mengembalikan alamat node dengan idSesi yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertNodeSesi(BSTSesi &T, adrNodeSesi P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. menempatkan elemen beralamat P pada BST terurut berdasarkan idSesi */

// penghapusan node
void deleteNodeSesi(BSTSesi &T, adrNodeSesi &P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. P adalah alamat dari alamat elemen yang akan dihapus;
        elemen lain menggantikan posisi elemen P yang dihapus sesuai aturan BST */

void deleteByIdSesi(BSTSesi &T, string idSesi);
/* I.S. terdefinisi BST T dan idSesi terdefinisi
   F.S. node dengan idSesi yang cocok dihapus jika ditemukan */

// traversal
void printInOrderSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. seluruh record sesi ditampilkan dengan traversal in-order */

void printPreOrderSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. seluruh record sesi ditampilkan dengan traversal pre-order */

void printPostOrderSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. seluruh record sesi ditampilkan dengan traversal post-order */

// informasi pohon
adrNodeSesi minNodeSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan idSesi minimum atau NULL jika BST kosong */

adrNodeSesi maxNodeSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan idSesi maksimum atau NULL jika BST kosong */

int heightBSTSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan tinggi BST; tinggi pohon kosong adalah 0 */

int countNodeSesi(BSTSesi T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan jumlah node dalam BST */

// input dari user
infotypeSesi inputSesiStreaming();
/* I.S. ~
   F.S. meminta data sesi streaming dari user */

#endif // SESISTREAMINGBST_H_INCLUDED