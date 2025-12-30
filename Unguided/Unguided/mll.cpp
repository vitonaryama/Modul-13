#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

bool isEmptyInduk(listInduk LInduk){
    return LInduk.first == NULL;
}

bool isEmptyAnak(listAnak LAnak){
    return LAnak.first == NULL;
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = NULL;
    LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = NULL;
    LAnak.last = NULL;
}

NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent p = new nodeParent;
    p->isidata.idKategori = idKategori;
    p->isidata.namaKategori = namaKategori;
    p->next = NULL;
    p->prev = NULL;
    createListAnak(p->L_Anak);
    return p;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild p = new nodeChild;
    p->isidata.idMakanan = idMakanan;
    p->isidata.namaMakanan = namaMakanan;
    p->isidata.harga = harga;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void dealokasiNodeChild(NodeChild &p) {
    if(p != NULL) {
        p->next = NULL;
        p->prev = NULL;
        delete p;
        p = NULL;
    }
}

void dealokasiNodeParent(NodeParent &p) {
    if(p != NULL) {
        p->next = NULL;
        p->prev = NULL;
        delete p;
        p = NULL;
    }
}

void insertFirstParent(listInduk &LInduk, NodeParent p) {
    if(isEmptyInduk(LInduk)) {
        LInduk.first = LInduk.last = p;
    } else {
        p->next = LInduk.first;
        LInduk.first->prev = p;
        LInduk.first = p;
    }
    cout << "Parent " << p->isidata.namaKategori << " ditambahkan di awal list induk" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent p) {
    if(isEmptyInduk(LInduk)) {
        LInduk.first = LInduk.last = p;
    } else {
        p->prev = LInduk.last;
        LInduk.last->next = p;
        LInduk.last = p;
    }
    cout << "Parent " << p->isidata.namaKategori << " ditambahkan di akhir list induk" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent p, NodeParent prec) {
    if(prec == NULL) {
        cout << "Node referensi tidak valid" << endl;
    } else if(prec == LInduk.last) {
        insertLastParent(LInduk, p);
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
        cout << "Parent " << p->isidata.namaKategori << " disisipkan setelah " << prec->isidata.namaKategori << endl;
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk)){
        cout << "List induk kosong" << endl;
    } else {
        NodeParent p = LInduk.first;
        if(LInduk.first == LInduk.last){
            LInduk.first = LInduk.last = NULL;
        } else {
            LInduk.first = p->next;
            LInduk.first->prev = NULL;
            p->next = NULL;
        }
        hapusListAnak(p->L_Anak);
        dealokasiNodeParent(p);
        cout << "Parent pertama berhasil dihapus" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk)){
        cout << "List induk kosong" << endl;
    } else {
        NodeParent p = LInduk.last;
        if(LInduk.first == LInduk.last){
            LInduk.first = LInduk.last = NULL;
        } else {
            LInduk.last = p->prev;
            LInduk.last->next = NULL;
            p->prev = NULL;
        }
        hapusListAnak(p->L_Anak);
        dealokasiNodeParent(p);
        cout << "Parent terakhir berhasil dihapus" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent prec){
    if(isEmptyInduk(LInduk)){
        cout << "List induk kosong" << endl;
    } else if(prec != NULL && prec->next != NULL){
        NodeParent p = prec->next;
        prec->next = p->next;
        if(p->next != NULL){
            p->next->prev = prec;
        } else {
            LInduk.last = prec;
        }
        p->next = NULL;
        hapusListAnak(p->L_Anak);
        dealokasiNodeParent(p);
        cout << "Parent setelah " << prec->isidata.namaKategori << " berhasil dihapus" << endl;
    } else {
        cout << "Node referensi tidak valid" << endl;
    }
}

void findParentByID(listInduk &LInduk, string key){
    if(isEmptyInduk(LInduk)){
        cout << "List induk kosong" << endl;
    } else {
        NodeParent p = LInduk.first;
        int pos = 1;
        bool found = false;
        while(p != NULL){
            if(p->isidata.idKategori == key){
                cout << "Parent ditemukan pada posisi ke-" << pos << endl;
                cout << "ID : " << p->isidata.idKategori << endl;
                cout << "Nama : " << p->isidata.namaKategori << endl;
                found = true;
                break;
            }
            p = p->next;
            pos++;
        }
        if(!found){
            cout << "Parent tidak ditemukan" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string key, string namaBaru) {
    NodeParent p = LInduk.first;
    bool found = false;
    while(p != NULL){
        if(p->isidata.idKategori == key){
            p->isidata.namaKategori = namaBaru;
            cout << "Data parent berhasil diperbarui" << endl;
            found = true;
            break;
        }
        p = p->next;
    }
    if(!found){
        cout << "Parent tidak ditemukan" << endl;
    }
}
