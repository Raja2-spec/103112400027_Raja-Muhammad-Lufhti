#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(Stack &S);
bool isFull(Stack &S);
void createStack(Stack &S);
void Push(Stack &S);
void Pop(Stack &S);
void Update(Stack &S, int pos);
void View(Stack &S);
void SearchNilaiAkhir(Stack &S, float minVal, float maxVal);
void MaxNilaiAkhir(Stack &S);

#endif
