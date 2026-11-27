#include "../../header/aktivitas.h"

void insertAfterAktivitas(ListAktivitas &L, adrAktivitas Prec, adrAktivitas P) {
    if (Prec != NULL) {
        if (Prec == L.last) {
            insertLastAktivitas(L, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void insertLastAktivitas(ListAktivitas &L, adrAktivitas P) {
    if (isEmptyAktivitas(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirstAktivitas(ListAktivitas &L, adrAktivitas &P) {
    if (!isEmptyAktivitas(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    } else {
        P = NULL;
    }
}

void deleteLastAktivitas(ListAktivitas &L, adrAktivitas &P) {
    if (!isEmptyAktivitas(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    } else {
        P = NULL;
    }
}

void deleteAfterAktivitas(ListAktivitas &L, adrAktivitas Prec, adrAktivitas &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        if (P == L.last) {
            deleteLastAktivitas(L, P);
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    } else {
        P = NULL;
    }
}

void printInfoAktivitas(ListAktivitas L) {
    if (isEmptyAktivitas(L)) {
        cout << "Data aktivitas kosong." << endl;
        return;
    }
    adrAktivitas P = L.first;
    while (P != NULL) {
        cout << "Tanggal: " << P->info.tanggal
             << " | Status: " << P->info.status
             << " | Tingkatan: " << P->info.tingkatan << endl;
        P = P->next;
    }
}

infotypeAktivitas inputAktivitas() {
    infotypeAktivitas x;
    cout << "Tanggal: ";
    cin >> x.tanggal;
    cout << "Status: ";
    cin >> x.status;
    cout << "Tingkatan: ";
    cin >> x.tingkatan;
    return x;
}
