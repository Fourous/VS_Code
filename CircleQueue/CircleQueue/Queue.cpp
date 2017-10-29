#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#define OVERFLOW 1


void InitQueue(Queue &Q) {
	Q.data = (int *)malloc(MAX*sizeof(int));
	if (!Q.data)		exit(OVERFLOW);
	Q.font = Q.rear;

}
void Destroy(Queue &Q) {
		Q.font = Q.rear = 0;
		free(Q.data);
}
bool QueFull(Queue Q) {
	if ((Q.rear + 1) % MAX == Q.font)		return true;
	else return false;
}
bool QueEmpty(Queue Q) {
	if (Q.font%MAX == Q.rear)		return true;
	else return false;
}
int QueLength(Queue Q) {
	return (Q.rear - Q.font+MAX) % MAX;
}
void EnQueue(Queue &Q, int e) {
	if (QueFull)		exit(OVERFLOW);
	Q.data[Q.rear + 1]=e;
	Q.rear = (Q.rear + 1) % MAX;

}
int DeQueue(Queue &Q, int &e) {
	if (QueEmpty)	exit(OVERFLOW);
	e = Q.data[Q.font];
	Q.font = (Q.font+1) % MAX;
}