#ifndef LINKED_H
#define LINKED_H

#include "boolean.h"

// Definisi struktur Node
typedef struct Node {
    int info;  // Menyimpan informasi nomor antrian
    struct Node *next;  // Pointer ke node berikutnya
} Node;

// Definisi struktur LinkedList
typedef struct {
    Node *head;  // Pointer ke node pertama dalam linked list
} LinkedList;

// Deklarasi fungsi
void createList(LinkedList *L);
boolean isEmpty(LinkedList L);
Node* allocate(int value);
void Ins_Akhir(LinkedList *L, int value);
void Del_Awal(LinkedList *L, int *value);
void printList(LinkedList L);

#endif