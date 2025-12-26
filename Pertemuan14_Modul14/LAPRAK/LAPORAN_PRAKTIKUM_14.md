# <h1 align="center">Laporan Praktikum Modul 14 - Graph </h1>
<p align="center">Raja Muhammad Lufhti - 103112400027</p>

## Dasar Teori
Graph merupakan struktur data non-linear yang terdiri dari himpunan simpul (vertex/node) dan sisi (edge) yang merepresentasikan hubungan antar simpul. Berdasarkan arah sisi, graph dibedakan menjadi graph berarah (directed graph) dan graph tidak berarah (undirected graph). Dalam modul ini, graph direpresentasikan menggunakan multilist (adjacency list) berbasis pointer, yang lebih efisien untuk graph dinamis dibanding matriks ketetanggaan karena penggunaan memori bergantung pada jumlah edge. Penelusuran graph dilakukan menggunakan dua algoritma utama, yaitu Depth First Search (DFS) yang mengeksplorasi graph secara mendalam hingga mentok sebelum backtracking, serta Breadth First Search (BFS) yang menelusuri graph secara melebar berdasarkan level menggunakan struktur antrian. Kedua algoritma ini memanfaatkan penanda visited untuk mencegah kunjungan berulang, terutama pada graph yang memiliki siklus.


## Guided

### 1.Graph
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
#### graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```
#### graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}
```

#### graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}
```

#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Program ini mengimplementasikan struktur data **Graph** menggunakan pendekatan **Adjacency List** berbasis pointer. Setiap simpul direpresentasikan oleh struktur `ElmNode` yang menyimpan informasi node, status kunjungan, serta pointer ke daftar edge dan node berikutnya. Hubungan antar simpul direpresentasikan oleh struktur `ElmEdge` yang menyimpan pointer ke simpul tujuan. Proses pembentukan graph diawali dengan inisialisasi graph kosong, dilanjutkan dengan penambahan node dan penghubungan node menggunakan edge. Program juga menyediakan fungsi untuk menampilkan struktur graph, sehingga hubungan antar node dapat diamati secara jelas. Implementasi ini memberikan pemahaman dasar mengenai konsep graph serta penggunaan pointer dalam merepresentasikan relasi antar data secara dinamis.

## Unguided 
### 1. Implementasi Graph Tidak Berarah Lengkap dengan DFS dan BFS
#### Graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);

void PrintInfoGraph(Graph G);

void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif

```
#### Graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}

#include <queue>
void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}

```
#### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    adrNode A = G.first;
    adrNode B = A->Next;
    adrNode C = B->Next;
    adrNode D = C->Next;
    adrNode E = D->Next;

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, E);

    cout << "Graph:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS Traversal: ";
    ResetVisited(G);
    PrintDFS(G, A);

    cout << "\n\nBFS Traversal: ";
    ResetVisited(G);
    PrintBFS(G, A);

    cout << endl;
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan14_Modul14/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED.png)

**Program C++ ini** File graph.h berfungsi sebagai definisi ADT Graph tidak berarah yang menetapkan struktur data node, edge, dan operasi dasar graph seperti pembuatan graph, penambahan node, penghubungan node, serta traversal DFS dan BFS; graph.cpp merupakan implementasi konkret dari ADT tersebut menggunakan representasi multilist berbasis pointer, di mana setiap node menyimpan daftar tetangga dan mekanisme visited untuk menghindari kunjungan berulang saat penelusuran; sedangkan main.cpp digunakan sebagai program uji untuk membangun graph sederhana, menghubungkan antar node, serta menampilkan struktur graph dan hasil penelusuran DFS dan BFS, sehingga membuktikan bahwa ADT Graph telah bekerja sesuai konsep dan tujuan Modul 14.

## Kesimpulan
Modul Graph memberikan pemahaman fundamental tentang bagaimana hubungan antar data dapat dimodelkan secara fleksibel menggunakan struktur graph. Implementasi graph dengan multilist memungkinkan pengelolaan data yang dinamis dan efisien, terutama untuk kasus nyata seperti jaringan, peta, dan relasi antar entitas. Algoritma DFS dan BFS berperan penting dalam eksplorasi graph dengan karakteristik traversal yang berbeda, sehingga pemilihannya harus disesuaikan dengan tujuan pemrosesan data. Secara keseluruhan, modul ini menekankan bahwa keberhasilan pengolahan graph tidak hanya bergantung pada algoritma, tetapi juga pada representasi data dan pengelolaan struktur pointer yang tepat.

## Referensi
[1]. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).
Introduction to Algorithms (3rd ed.). MIT Press.

[2]Gross, J. L., & Yellen, J. (2005).
Graph Theory and Its Applications. Chapman & Hall/CRC.

[3]Tarjan, R. E. (1972).
Depth-First Search and Linear Graph Algorithms.
SIAM Journal on Computing, 1(2), 146–160.