#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node_t;

typedef struct node_t {
    int data;
    node_t* next;
} node_t;

extern node_t *start;

void init();
int add(int data);
int addAfter(int n, int k);
int addPrev(int n, int k);
int addEnd(int n);

int dellFirst(int *n);
void dellEnd(int *n);
node_t* dellElemReturnAfter(int *n, int k);

node_t* search_iter(int k);

void printAfter(node_t *curr);
void printList();
