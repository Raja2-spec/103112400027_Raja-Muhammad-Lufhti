#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

bool isEmpty(Node* root);
void createTree(Node* &root);

Node* newNode(string nama, float berat, string tier);
void insertNode(Node* &root, Node* p);

void inOrder(Node* root);

Node* mostLeft(Node* root);
Node* mostRight(Node* root);

void searchByBeratBadan(Node* root, float key, Node* parent = NULL);

#endif
