#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membuat queue kosong
void CreateQueue(Queue *Q) {
    createList(Q);
}

// Fungsi untuk mengecek apakah queue kosong
boolean isEmptyQueue(Queue Q) {
    return isEmpty(Q);  // Memanggil fungsi isEmpty dari linked.c
}

// Fungsi untuk mengecek apakah queue penuh (tidak digunakan dalam linked list)
boolean isFull(Queue Q) {
    return false;  // Linked list tidak memiliki batasan kapasitas
}

// Fungsi untuk menambahkan elemen ke queue (enqueue)
void EnQueue(Queue *Q, int X) {
    Ins_Akhir(Q, X);
}

// Fungsi untuk menghapus elemen dari queue (dequeue)
void DeQueue(Queue *Q, int *X) {
    Del_Awal(Q, X);
}

// Fungsi untuk menghitung panjang queue
int PanjangQueue(Queue Q) {
    int count = 0;
    Node *temp = Q.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}