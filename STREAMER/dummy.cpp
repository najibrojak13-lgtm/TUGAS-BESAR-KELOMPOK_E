#include "dummy.h"
#include <iostream>
using namespace std;

void runDummyStreamer(ListStreamer &LS) {
    cout << "=== DUMMY STREAMER (MLL PARENT) ===" << endl;
    createListStreamer(LS);

    infotypeStreamer s1 = {"STR-01", "RakaGaming", "YouTube", 125000};
    infotypeStreamer s2 = {"STR-02", "NadiaPlay", "Twitch", 84000};
    infotypeStreamer s3 = {"STR-03", "DimasLive", "TikTok", 53000};

    insertFirstStreamer(LS, alokasiStreamer(s1));
    insertLastStreamer(LS, alokasiStreamer(s2));

    adrStreamer prec = findStreamer(LS, "STR-01");
    insertAfterStreamer(LS, prec, alokasiStreamer(s3));

    printAllStreamer(LS);

    adrStreamer cari = findStreamer(LS, "STR-02");
    if (cari != NULL) {
        cout << "Ditemukan streamer: " << cari->info.namaStreamer << endl;
    }

    adrStreamer dihapus = NULL;
    deleteStreamerByID(LS, "STR-03", dihapus);
    if (dihapus != NULL) {
        dealokasiStreamer(dihapus);
    }

    cout << "Setelah hapus STR-03:" << endl;
    printAllStreamer(LS);
    cout << endl;
}

void runDummyGame(ListGame &LG) {
    cout << "=== DUMMY GAME (MLL CHILD) ===" << endl;
    createListGame(LG);

    infotypeGame g1 = {"GM-01", "Valorant", "FPS", 8.7f};
    infotypeGame g2 = {"GM-02", "Mobile Legends", "MOBA", 8.2f};
    infotypeGame g3 = {"GM-03", "Elden Ring", "RPG", 9.5f};

    insertFirstGame(LG, alokasiGame(g1));
    insertLastGame(LG, alokasiGame(g2));
    insertLastGame(LG, alokasiGame(g3));

    printAllGame(LG);

    adrGame cari = findGame(LG, "GM-03");
    if (cari != NULL) {
        cout << "Ditemukan game: " << cari->info.judulGame << endl;
    }

    adrGame dihapus = NULL;
    deleteGameByID(LG, "GM-02", dihapus);
    if (dihapus != NULL) {
        dealokasiGame(dihapus);
    }

    cout << "Setelah hapus GM-02:" << endl;
    printAllGame(LG);
    cout << endl;
}

void runDummyAktivitas(ListAktivitas &LA) {
    cout << "=== DUMMY AKTIVITAS (MLL) ===" << endl;
    createListAktivitas(LA);

    infotypeAktivitas a1 = {"2026-11-20", "Selesai", "Tinggi"};
    infotypeAktivitas a2 = {"2026-11-22", "Berlangsung", "Sedang"};
    infotypeAktivitas a3 = {"2026-11-25", "Terjadwal", "Rendah"};

    insertFirstAktivitas(LA, alokasiAktivitas(a1));
    insertLastAktivitas(LA, alokasiAktivitas(a2));

    adrAktivitas prec = findElmAktivitas(LA, "2026-11-20");
    insertAfterAktivitas(LA, prec, alokasiAktivitas(a3));

    printInfoAktivitas(LA);

    adrAktivitas dihapus = NULL;
    deleteFirstAktivitas(LA, dihapus);
    if (dihapus != NULL) {
        dealokasiAktivitas(dihapus);
    }

    cout << "Setelah hapus elemen pertama aktivitas:" << endl;
    printInfoAktivitas(LA);
    cout << endl;
}

void runDummySesiBST(BSTSesi &TBS) {
    cout << "=== DUMMY SESI STREAMING (BST) ===" << endl;
    createBSTSesi(TBS);

    infotypeSesi d1 = {"SES-050", "STR-01", "GM-01", "2026-11-20", 180, 4200, 15000, 1250000.0};
    infotypeSesi d2 = {"SES-020", "STR-01", "GM-03", "2026-11-21", 240, 6100, 22000, 2100000.0};
    infotypeSesi d3 = {"SES-080", "STR-02", "GM-01", "2026-11-22", 150, 3100, 11000, 950000.0};
    infotypeSesi d4 = {"SES-010", "STR-03", "GM-02", "2026-11-23", 120, 1900, 7500, 600000.0};

    insertNodeSesi(TBS, alokasiSesi(d1));
    insertNodeSesi(TBS, alokasiSesi(d2));
    insertNodeSesi(TBS, alokasiSesi(d3));
    insertNodeSesi(TBS, alokasiSesi(d4));

    cout << "In-Order:" << endl;
    printInOrderSesi(TBS);

    cout << "Pre-Order: ";
    printPreOrderSesi(TBS);

    cout << "Post-Order: ";
    printPostOrderSesi(TBS);

    cout << "Jumlah node: " << countNodeSesi(TBS)
         << " | Tinggi BST: " << heightBSTSesi(TBS) << endl;

    adrNodeSesi minN = minNodeSesi(TBS);
    adrNodeSesi maxN = maxNodeSesi(TBS);
    if (minN != NULL) cout << "Min ID Sesi: " << minN->info.idSesi << endl;
    if (maxN != NULL) cout << "Max ID Sesi: " << maxN->info.idSesi << endl;

    deleteByIdSesi(TBS, "SES-020");
    cout << "In-Order setelah hapus SES-020:" << endl;
    printInOrderSesi(TBS);
    cout << endl;
}

void runAllDummy() {
    ListStreamer LS;
    ListGame LG;
    ListAktivitas LA;
    BSTSesi TBS;

    runDummyStreamer(LS);
    runDummyGame(LG);
    runDummyAktivitas(LA);
    runDummySesiBST(TBS);
}
