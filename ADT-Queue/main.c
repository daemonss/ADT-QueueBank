#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"
#include "menu.h"

int main() {
    int numQueues;
    printf("Masukkan jumlah teller yang ingin dibuat: ");
    scanf("%d", &numQueues);

    // Array untuk menyimpan nama teller
    char tellerNames[numQueues][20];  // Misalnya, "Teller 1", "Teller 2", dst.
    for (int i = 0; i < numQueues; i++) {
        sprintf(tellerNames[i], "Teller %d", i + 1);  // Memberi nama teller
    }

    Queue queues[numQueues];
    for (int i = 0; i < numQueues; i++) {
        CreateQueue(&queues[i]);
    }

    int choice;
    int nextNumber = 1;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int recommendedQueue = recommendQueue(queues, numQueues);
                printf("Rekomendasi antrian tercepat: %s\n", tellerNames[recommendedQueue]);
                printf("Masukkan nomor teller yang dipilih (1-%d): ", numQueues);

                int queueNumber;
                scanf("%d", &queueNumber);

                if (queueNumber < 1 || queueNumber > numQueues) {
                    printf("Nomor teller tidak valid!\n");
                    break;
                }

                EnQueue(&queues[queueNumber - 1], nextNumber);
                printf("Nomor antrian %d telah ditambahkan ke %s.\n", nextNumber, tellerNames[queueNumber - 1]);
                nextNumber++;
                break;
            }
            case 2: {
                printf("Masukkan nomor teller yang akan diproses (1-%d): ", numQueues);

                int queueNumber;
                scanf("%d", &queueNumber);

                if (queueNumber < 1 || queueNumber > numQueues) {
                    printf("Nomor teller tidak valid!\n");
                    break;
                }

                int processedNumber;
                if (!isEmptyQueue(queues[queueNumber - 1])) {
                    DeQueue(&queues[queueNumber - 1], &processedNumber);
                    printf("Nomor antrian %d telah diproses dari %s.\n", processedNumber, tellerNames[queueNumber - 1]);
                } else {
                    printf("%s kosong, tidak ada yang bisa diproses.\n", tellerNames[queueNumber - 1]);
                }
                break;
            }
            case 3: {
                for (int i = 0; i < numQueues; i++) {
                    printf("%s:\n", tellerNames[i]);
                    printf("Antrian: ");
                    printList(queues[i]);
                }
                break;
            }
            case 4: {
                printf("Keluar dari program.\n");
                break;
            }
            default: {
                printf("Pilihan tidak valid!\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}