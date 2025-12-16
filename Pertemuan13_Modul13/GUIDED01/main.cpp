#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    //1. inisialisasi list 
    listInduk LInduk;
    createListInduk(LInduk);

    //2. membuat data parent (kategori makanan)
    NodeParent K01 = alokasiNodeParent("K01", "makanan berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "desert");
    insertLastParent(LInduk, K03);
    cout << endl;

    NodeChild M01 = alokasiNodeChild("M01", "nasi goreng spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "ayam bakar madu");
    insertLastChild(K01->L_Anak, M02);

    NodeChild D02 = alokasiNodeChild("D02", "jus alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "es teh manis");
    insertLastChild(K02->L_Anak, D01);
    // --> isi kategori dessert (k03)
    NodeChild S01 = alokasiNodeChild("S01", "puding coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl;

    //4. print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5. searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    //6. delete node child
    deleteAfterChild(K01->L_Anak, M01);
    cout << endl;
    //7. delete node parent
    deleteAfterParent(LInduk, K02);
    cout << endl;
    //8. print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;

}

