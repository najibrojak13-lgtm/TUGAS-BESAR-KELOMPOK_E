#include "../header/sesi_streaming.h"

static void inOrderRec(adrNodeSesi root) {
    if (root != NULL) {
        inOrderRec(root->left);
        cout << "ID Sesi: " << root->info.idSesi
             << " | Streamer: " << root->info.idStreamer
             << " | Game: " << root->info.idGame
             << " | Tanggal: " << root->info.tanggalStreaming
             << " | Durasi: " << root->info.durasi
             << " | Penonton: " << root->info.jumlahPenonton
             << " | Penayangan: " << root->info.jumlahPenayangan
             << " | Pendapatan: " << root->info.pendapatan << endl;
        inOrderRec(root->right);
    }
}

static void preOrderRec(adrNodeSesi root) {
    if (root != NULL) {
        cout << "[" << root->info.idSesi << "] ";
        preOrderRec(root->left);
        preOrderRec(root->right);
    }
}

static void postOrderRec(adrNodeSesi root) {
    if (root != NULL) {
        postOrderRec(root->left);
        postOrderRec(root->right);
        cout << "[" << root->info.idSesi << "] ";
    }
}

static int heightRec(adrNodeSesi root) {
    if (root == NULL) return 0;
    int kiri = heightRec(root->left);
    int kanan = heightRec(root->right);
    return 1 + (kiri > kanan ? kiri : kanan);
}

static int countRec(adrNodeSesi root) {
    if (root == NULL) return 0;
    return 1 + countRec(root->left) + countRec(root->right);
}

void printInOrderSesi(BSTSesi T) {
    if (isEmptySesi(T)) {
        cout << "BST Sesi Streaming kosong." << endl;
        return;
    }
    inOrderRec(T.root);
}

void printPreOrderSesi(BSTSesi T) {
    if (isEmptySesi(T)) {
        cout << "BST Sesi Streaming kosong." << endl;
        return;
    }
    preOrderRec(T.root);
    cout << endl;
}

void printPostOrderSesi(BSTSesi T) {
    if (isEmptySesi(T)) {
        cout << "BST Sesi Streaming kosong." << endl;
        return;
    }
    postOrderRec(T.root);
    cout << endl;
}

adrNodeSesi minNodeSesi(BSTSesi T) {
    if (T.root == NULL) return NULL;
    adrNodeSesi curr = T.root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

adrNodeSesi maxNodeSesi(BSTSesi T) {
    if (T.root == NULL) return NULL;
    adrNodeSesi curr = T.root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

int heightBSTSesi(BSTSesi T) {
    return heightRec(T.root);
}

int countNodeSesi(BSTSesi T) {
    return countRec(T.root);
}

infotypeSesi inputSesiStreaming() {
    infotypeSesi x;
    cout << "ID Sesi: ";
    cin >> x.idSesi;
    cout << "ID Streamer: ";
    cin >> x.idStreamer;
    cout << "ID Game: ";
    cin >> x.idGame;
    cout << "Tanggal Streaming: ";
    cin >> x.tanggalStreaming;
    cout << "Durasi: ";
    cin >> x.durasi;
    cout << "Jumlah Penonton: ";
    cin >> x.jumlahPenonton;
    cout << "Jumlah Penayangan: ";
    cin >> x.jumlahPenayangan;
    cout << "Pendapatan: ";
    cin >> x.pendapatan;
    return x;
}
