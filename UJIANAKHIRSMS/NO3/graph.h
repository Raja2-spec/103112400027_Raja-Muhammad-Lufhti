#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

struct ElmEdge;
struct ElmNode;

struct ElmEdge {
    ElmNode* to;
    ElmEdge* next;
};

struct ElmNode {
    char info;
    bool visited;
    bool active;
    ElmEdge* firstEdge;
    ElmNode* next;
};

struct Graph {
    ElmNode* first;
};

void createGraph(Graph &G);
ElmNode* createNode(char x);
ElmEdge* createEdge(ElmNode* to);
void insertNode(Graph &G, ElmNode* p);
void connectNode(ElmNode* a, ElmNode* b);

void showGraph(Graph G);

void resetVisited(Graph G);
void DFS(ElmNode* start);
int countActive(Graph G);
int countVisited(Graph G);

bool isKotaKritis(Graph G, ElmNode* kota);
void analisisKotaKritis(Graph G);

#endif
