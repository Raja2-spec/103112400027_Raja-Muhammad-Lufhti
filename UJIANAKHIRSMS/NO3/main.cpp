#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    ElmNode* A = createNode('A');
    ElmNode* B = createNode('B');
    ElmNode* C = createNode('C');
    ElmNode* D = createNode('D');
    ElmNode* E = createNode('E');

    insertNode(G, A);
    insertNode(G, B);
    insertNode(G, C);
    insertNode(G, D);
    insertNode(G, E);

    connectNode(A, B);
    connectNode(B, C);
    connectNode(C, D);
    connectNode(B, E);

    showGraph(G);
    analisisKotaKritis(G);

    return 0;
}
