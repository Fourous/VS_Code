#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"
#define QUEUEOVER 100
#define OVERFLOW 1
#define ERROR 0
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
queueptr	p = (queueptr)malloc(sizeof(node));
if (!p)			exit(OVERFLOW);
p->data = e;
p->next = NULL;
Q.rear->next = p;
Q.rear = p;

}
int DeQueue(queuelink &Q, int &e) {
	if (Q.font == Q.rear)		return ERROR;
	queueptr p = Q.font->next;
	e = p->data;
	Q.font->next = p->next;
	if (p == Q.rear)		Q.font = Q.rear;
	free(p);
}
void Destroy(queuelink &Q) {
	while (Q.font) {
		Q.rear = Q.font->next;
		free(Q.font);
		Q.font = Q.rear;
	}
}