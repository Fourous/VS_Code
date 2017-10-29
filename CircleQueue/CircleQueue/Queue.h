#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50
typedef struct Queue {
	int *data;//¶¯Ì¬·ÖÅäÄÚ´æ
	int font;
	int rear;
};

void InitQueue(Queue &Q);
void Destroy(Queue &Q);
bool QueFull(Queue Q);
bool QueEmpty(Queue Q);
int QueLength(Queue Q);
void EnQueue(Queue &Q,int e);
int DeQueue(Queue &Q,int &e);