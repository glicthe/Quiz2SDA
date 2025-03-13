#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node *head = NULL; // Deklarasi head sebagai variabel global

// Fungsi untuk memeriksa apakah list kosong
int isEmpty() {
    return (head == NULL);
}

// Fungsi untuk memasukkan elemen di awal list
void insertFirst(int info) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal! (Overflow)\n");
        return;
    }
    newNode->info = info;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk memasukkan elemen di akhir list
void insertLast(int info) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal! (Overflow)\n");
        return;
    }
    newNode->info = info;
    newNode->next = NULL;
    
    if (isEmpty()) {
        head = newNode;
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Fungsi untuk memasukkan elemen setelah target tertentu
void insertAfter(int target, int info) {
    if (isEmpty()) {
        printf("List kosong, tidak bisa insert after\n");
        return;
    }
    
    Node *curr = head;
    while (curr != NULL && curr->info != target) {
        curr = curr->next;
    }
    
    if (curr == NULL) {
        printf("Target %d tidak ditemukan\n", target);
        return;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal! (Overflow)\n");
        return;
    }
    newNode->info = info;
    newNode->next = curr->next;
    curr->next = newNode;
}

// Fungsi untuk menghapus elemen pertama
void deleteFirst() {
    if (isEmpty()) {
        printf("List kosong! (Underflow)\n");
        return;
    }
    Node *curr = head;
    head = head->next;
    free(curr);
}

// Fungsi untuk menghapus elemen terakhir
void deleteLast() {
    if (isEmpty()) {
        printf("List kosong! (Underflow)\n");
        return;
    }
    
    if (head->next == NULL) { // Hanya 1 elemen
        free(head);
        head = NULL;
    } else {
        Node *prev = NULL;
        Node *last = head;
        while (last->next != NULL) {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        free(last);
    }
}

// Fungsi untuk menghapus elemen tertentu
void deleteValue(int info) {
    if (isEmpty()) {
        printf("List kosong! (Underflow)\n");
        return;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    
    // Cari node yang akan dihapus
    while (curr != NULL && curr->info != info) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        printf("Elemen %d tidak ditemukan\n", info);
        return;
    }
    
    if (prev == NULL) { // Hapus elemen pertama
        head = head->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

// Fungsi untuk mencetak list
void printList() {
    if (isEmpty()) {
        printf("{}\n");
        return;
    }
    Node *curr = head;
    printf("Elemen List: {");
    while (curr != NULL) {
        printf("%d", curr->info);
        if (curr->next != NULL) printf(", ");
        curr = curr->next;
    }
    printf("}\n");
}

// Fungsi untuk menghapus semua elemen
void freeList() {
    while (!isEmpty()) {
        deleteFirst();
    }
}
