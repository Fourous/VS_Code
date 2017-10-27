#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"
#define QUEUEOVER 100
#define OVERFLOW 1
void InitQueue(queuelink &Q) {
	Q.font = Q.font = (queueptr)malloc(sizeof(node));
	if (!Q.font && !Q.rear)		exit(OVERFLOW);
	Q.rear->next = NULL;
}
bool QueueFull(queuelink Q) {
	
}
bool QueueEmpty(queuelink Q);
void Clearqueue(queuelink &Q);
//Èë¶Ó
int EnQueue(queuelink &Q, int e) {
	p=(queueptr0)
}
int DeQueue(queuelink &Q, int &e);
void Destroy(queuelink &Q) {
	while (Q.font) {
		Q.rear = Q.font->next;
		free(Q.font);
		Q.font = Q.rear;
	}
}