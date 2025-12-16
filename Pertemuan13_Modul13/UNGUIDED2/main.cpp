#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent G1 = alokasiParent("G001", "Aves");
    NodeParent G2 = alokasiParent("G002", "Mamalia");
    NodeParent G3 = alokasiParent("G003", "Pisces");
    NodeParent G4 = alokasiParent("G004", "Amfibi");

    insertLastParent(L, G1);
    insertLastParent(L, G2);
    insertLastParent(L, G3);
    insertLastParent(L, G4);

    insertLastChild(G2->child, alokasiChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G2->child, alokasiChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G2->child, alokasiChild("M002","Kucing","Darat",true,4));

    insertLastChild(G4->child, alokasiChild("AM001","Kodok","Sawah",false,0.2));

    tampilkanChildDanParent(L, "G002", 2);
    tampilkanChildDanParent(L, "G004", 1);

    return 0;
}
