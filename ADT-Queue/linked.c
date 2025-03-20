#include "linked.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membuat linked list kosong
void createList(LinkedList *L) {
    L->head = NULL;
}

// Fungsi untuk mengecek apakah linked list kosong
boolean isEmpty(LinkedList L) {
    return L.head == NULL;
}

// Fungsi untuk mengalokasikan memori untuk node baru
Node* allocate(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->info = value;
        newNode->next = NULL;
    } else {
        printf("ERROR: Alokasi memori gagal, insertion ditolak!\n");
    }
    return newNode;
}

// Fungsi untuk menyisipkan node di akhir linked list
void Ins_Akhir(LinkedList *L, int value) {
    Node *newNode = allocate(value);
    if (newNode != NULL) {
        if (L->head == NULL) {
            L->head = newNode;
        } else {
            Node *last = L->head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        }
    }
}

// Fungsi untuk menghapus node pertama
void Del_Awal(LinkedList *L, int *value) {
    if (isEmpty(*L)) {
        printf("ERROR: List kosong, deleteFirst ditolak!\n");
        return;
    }
    Node *temp = L->head;
    *value = temp->info;
    L->head = L->head->next;
    free(temp);
}

// Fungsi untuk mencetak isi linked list
void printList(LinkedList L) {
    Node *temp = L.head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}