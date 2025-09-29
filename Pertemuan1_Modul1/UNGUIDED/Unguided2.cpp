#include <iostream>
using namespace std;
int main() {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", 
                        "empat belas", "lima belas", "enam belas", 
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", 
                        "delapan puluh", "sembilan puluh"};

    int n;
    cout << "Masukkan angka (0 - 100): ";
    cin >> n;

    cout << n << " : ";

    if (n == 0) {
        cout << "nol";
    } 
    else if (n == 100) {
        cout << "seratus";
    }
    else if (n < 10) {
        cout << satuan[n];
    }
    else if (n < 20) {
        cout << belasan[n - 10];
    }
    else {
        int puluh = n / 10;
        int sisa = n % 10;
        cout << puluhan[puluh];
        if (sisa != 0) {
            cout << " " << satuan[sisa];
        }
    }

    cout << endl;
    return 0;
}