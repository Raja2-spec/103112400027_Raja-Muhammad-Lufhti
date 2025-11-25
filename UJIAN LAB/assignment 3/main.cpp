#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    S.dataMahasiswa[++S.Top] = {"Venti", "11111", 75.7f, 82.1f, 65.5f};
    S.dataMahasiswa[++S.Top] = {"Xiao", "22222", 87.4f, 88.9f, 81.9f};
    S.dataMahasiswa[++S.Top] = {"Kazuha", "33333", 92.3f, 88.8f, 82.4f};
    S.dataMahasiswa[++S.Top] = {"Wanderer", "44444", 95.5f, 85.5f, 90.5f};
    S.dataMahasiswa[++S.Top] = {"Lynete", "55555", 77.7f, 65.4f, 79.9f};
    S.dataMahasiswa[++S.Top] = {"Chasca", "66666", 99.9f, 93.6f, 87.3f};
     
    cout << "Stack setelah input awal:" << endl;
    View(S);

    Pop(S);
    cout << "\nSetelah pop 1x:" << endl;
    View(S);

    cout << "\nUpdate posisi ke-3:" << endl;
    Update(S, 3);

    cout << "\nStack setelah update:" << endl;
    View(S);

    cout << "\nSearch nilai akhir dalam rentang 85.5 - 95.5:" << endl;
    SearchNilaiAkhir(S, 85.5f, 95.5f);

    cout << "\nData dengan nilai akhir terbesar:" << endl;
    MaxNilaiAkhir(S);

    return 0;
}
