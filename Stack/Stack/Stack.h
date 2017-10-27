#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SSIZE 100
#define SINCREASE 10
typedef int Element;
typedef struct Stack {
	Element *base;
	Element *top;
	int stacksize;
};
void InitStack(Stack &S);
bool StackEmpty(Stack S);
bool StackFull(Stack S);
void ClearStack(Stack &S);
Element getop(Stack S, Element &e);
Element push(Stack S, Element e);
Element pop(Stack S, Element &e);
void StackDestroy(Stack &S);
