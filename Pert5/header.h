#ifndef HEADER_H
#define HEADER_H

// Struktur node untuk linked list
typedef struct Node {
    int info;
    struct Node *next;
} Node;

// Deklarasi fungsi ADT Linked List
void insertFirst(int data);
void insertLast(int data);
void insertAfter(int target, int data);
void deleteFirst();
void deleteLast();
void deleteValue(int data);
void printList();
int isEmpty();
void freeList();

#endif
