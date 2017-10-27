#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}*queueptr;

typedef struct {
	queueptr font;
	queueptr rear;
}queuelink;

void InitQueue(queuelink &Q);
bool QueueFull(queuelink Q);
bool QueueEmpty(queuelink Q);
void Clearqueue(queuelink &Q);
int EnQueue(queuelink &Q,int e);
int DeQueue(queuelink &Q,int &e);
void Destroy(queuelink &Q);