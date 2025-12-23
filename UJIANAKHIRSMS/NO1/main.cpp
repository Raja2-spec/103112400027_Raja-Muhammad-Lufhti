#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    Node* root;
    createTree(root);

    insertNode(root, newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(root, newNode("Haklan Ismail", 50, "Bronze"));
    insertNode(root, newNode("Olivia Saevali", 65, "Silver"));
    insertNode(root, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(root, newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(root, newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(root, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(root, newNode("Davl Ilyas", 68, "Silver"));
    insertNode(root, newNode("Abdad Mubarok", 81, "Gold"));

    cout << "=== Traversal InOrder ===\n";
    inOrder(root);

    cout << "\n\nNode MostLeft  : " << mostLeft(root)->beratBadan;
    cout << "\nNode MostRight : " << mostRight(root)->beratBadan;

    cout << "\n\n=== Search Berat Badan 70 ===\n";
    searchByBeratBadan(root, 70);

    return 0;
}
