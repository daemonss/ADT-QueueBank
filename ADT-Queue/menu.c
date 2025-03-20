#include "menu.h"
#include <stdio.h>

// Fungsi untuk menampilkan menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Ambil Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Cetak Antrian\n");
    printf("4. Keluar\n");
    printf("Pilih menu: ");
}

// Fungsi untuk merekomendasikan antrian tercepat
int recommendQueue(Queue queues[], int numQueues) {
    int shortestQueue = 0;
    int shortestLength = PanjangQueue(queues[0]);

    for (int i = 1; i < numQueues; i++) {
        int currentLength = PanjangQueue(queues[i]);
        if (currentLength < shortestLength) {
            shortestQueue = i;
            shortestLength = currentLength;
        }
    }

    return shortestQueue;
}