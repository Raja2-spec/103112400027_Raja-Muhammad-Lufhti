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
