#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    listInduk L;
    createListInduk(L);
    cout << "=== DATA MENU BERHASIL DIBUAT ===" << endl << endl;

    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);

    cout << endl;

    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);

    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);

    cout << endl;

    cout << "=== MENU AWAL ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    cout << "=== PENGUJIAN PENCARIAN ===" << endl;
    findParentByID(L, "K02");
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");
    cout << "---------------------------" << endl << endl;

    cout << "=== PENGUJIAN UPDATE DATA ===" << endl;
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;

    cout << "\n=== DATA SETELAH UPDATE ===" << endl;
    printListInduk(L);
    cout << endl;
    printListAnak(L, Kat1);
    cout << endl;

    cout << "=== PENGUJIAN HAPUS DATA ===" << endl;
    cout << "> Menghapus data child D02" << endl;
    deleteFirstChild(Kat2->L_Anak);

    cout << "> Menghapus data parent terakhir" << endl;
    deleteLastParent(L);

    cout << "\n=== MENU AKHIR ===" << endl;
    printStrukturMLL(L);

    return 0;
}
