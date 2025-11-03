#include "Doublylist.h"

int main() {
    List L;
    createList(L);
    infotype x;
    address P;
    string cariNopol;

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

    printInfo(L);

    cout << "\n\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;
    P = findElm(L, cariNopol);
    printFind(P);

    return 0;
}
