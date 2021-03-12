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
void printList();
void printElement(int n);
