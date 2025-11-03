#include "Doublylist.h"

int main() {
    List L;
    createList(L);
    infotype x;
    address P, Q;
    string cariNopol, hapusNopol;

    for (int i = 0; i < 3; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (findElm(L, x.nopol) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
            i--;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        P = alokasi(x);
        insertLast(L, P);
        cout << endl;
    }

    cout << "masukkan nomor polisi: ";
    cin >> x.nopol;
    if (findElm(L, x.nopol) != Nil) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        P = alokasi(x);
        insertLast(L, P);
    }

    printInfo(L);

    cout << "\n\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;
    P = findElm(L, cariNopol);
    printFind(P);

    cout << "\n\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    P = findElm(L, hapusNopol);
    if (P == Nil) {
        cout << "Data tidak ditemukan, tidak bisa dihapus." << endl;
    } else {
        if (P == L.first) {
            deleteFirst(L, Q);
        } else if (P == L.last) {
            deleteLast(L, Q);
        } else {
            deleteAfter(P->prev, Q);
        }
        dealokasi(Q);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    }

    printInfo(L);

    return 0;
}
