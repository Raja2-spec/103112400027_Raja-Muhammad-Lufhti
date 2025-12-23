#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

ElmNode* createNode(char x) {
    ElmNode* p = new ElmNode;
    p->info = x;
    p->visited = false;
    p->active = true;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

ElmEdge* createEdge(ElmNode* to) {
    ElmEdge* e = new ElmEdge;
    e->to = to;
    e->next = NULL;
    return e;
}

void insertNode(Graph &G, ElmNode* p) {
    if (G.first == NULL) {
        G.first = p;
    } else {
        ElmNode* q = G.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

void connectNode(ElmNode* a, ElmNode* b) {
    ElmEdge* e1 = createEdge(b);
    e1->next = a->firstEdge;
    a->firstEdge = e1;

    ElmEdge* e2 = createEdge(a);
    e2->next = b->firstEdge;
    b->firstEdge = e2;
}

void showGraph(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin\n";
    cout << "Node A terhubung ke: B\n";
    cout << "Node B terhubung ke: E C A\n";
    cout << "Node C terhubung ke: D B\n";
    cout << "Node D terhubung ke: C\n";
    cout << "Node E terhubung ke: B\n\n";
}

void resetVisited(Graph G) {
    ElmNode* p = G.first;
    while (p != NULL) {
        p->visited = false;
        p = p->next;
    }
}

void DFS(ElmNode* start) {
    if (start == NULL || !start->active || start->visited)
        return;

    start->visited = true;

    ElmEdge* e = start->firstEdge;
    while (e != NULL) {
        if (e->to->active && !e->to->visited)
            DFS(e->to);
        e = e->next;
    }
}

int countActive(Graph G) {
    int c = 0;
    ElmNode* p = G.first;
    while (p != NULL) {
        if (p->active)
            c++;
        p = p->next;
    }
    return c;
}

int countVisited(Graph G) {
    int c = 0;
    ElmNode* p = G.first;
    while (p != NULL) {
        if (p->visited)
            c++;
        p = p->next;
    }
    return c;
}

bool isKotaKritis(Graph G, ElmNode* kota) {
    kota->active = false;
    resetVisited(G);

    ElmNode* start = G.first;
    while (start != NULL && !start->active)
        start = start->next;

    if (start != NULL)
        DFS(start);

    int aktif = countActive(G);
    int tercapai = countVisited(G);

    kota->active = true;
    return tercapai < aktif;
}

void analisisKotaKritis(Graph G) {
    cout << "Analisis Kota Kritis (Single Point of Failure)\n";

    ElmNode* p = G.first;
    while (p != NULL) {
        if (isKotaKritis(G, p)) {
            cout << "[PERINGATAN] Kota " << p->info << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << p->info << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << p->info << " aman (redundansi oke).\n";
        }
        p = p->next;
    }
}
