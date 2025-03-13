#include <stdio.h>
#include "header.h"

int main(int argc, char** argv) {
    // Langkah 1: Insert 7 di awal
    insertFirst(7);
    printf("Langkah 1: Insert 7 di awal\n");
    printList();
    
    // Langkah 2: Insert 11 di akhir
    insertLast(11);
    printf("\nLangkah 2: Insert 11 di akhir\n");
    printList();
    
    // Langkah 3: Insert 9 setelah 7
    printf("\nLangkah 3: Insert 9 setelah 7\n");
    insertAfter(7, 9);
    printList();
    
    // Langkah 4: Insert 5 di awal
    insertFirst(5);
    printf("\nLangkah 4: Insert 5 di awal\n");
    printList();
    
    // Langkah 5: Insert 13 di akhir
    insertLast(13);
    printf("\nLangkah 5: Insert 13 di akhir\n");
    printList();
    
    // Langkah 6: Hapus elemen terakhir (13)
    printf("\nLangkah 6: Hapus elemen terakhir\n");
    deleteLast();
    printList();
    
    // Langkah 7: Hapus nilai 7
    printf("\nLangkah 7: Hapus nilai 7\n");
    deleteValue(7);
    printList();
    
    // Langkah 8: Hapus elemen pertama (5)
    printf("\nLangkah 8: Hapus elemen pertama\n");
    deleteFirst();
    printList();
    
    // Langkah 9: Hapus semua elemen
    printf("\nLangkah 9: Hapus semua elemen\n");
    freeList();
    printList();
    
    return 0;
}
