#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#define OVERFLOW 1
#define ERROR 0
#define OK 1
void InitStack(Stack &S) {
	S.base = (Element *)malloc(SSIZE * sizeof(Element));
	if (!S.base)   exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = SSIZE;
};
bool StackEmpty(Stack S) {
	if (S.top = S.base)  return true;
}
bool StackFull(Stack S) {
	if (S.top - S.base >= SSIZE)
		return true;
	else return false;
}
Element getop(Stack S, Element &e) {
	if (S.top == S.base)   return ERROR;
	else
		e = *(S.top - 1);
}
Element push(Stack S, Element e) {
	if (StackFull(S)) {
		S.base = (Element *)realloc(S.base, (S.stacksize + SINCREASE) * sizeof(Element));
		if (! S.base)     exit(OVERFLOW);
		else
			S.top = S.base + S.stacksize;
		S.stacksize += SINCREASE;
	}
	*S.top++ = e;
}
Element pop(Stack S, Element &e) {
	if (!StackEmpty(S))    return false;
	else
		e = *--S.top;
}
void ClearStack(Stack &S) {
		S.top = S.base;
	S.stacksize = SSIZE;
}
void StackDestroy(Stack &S) {
	S.top = NULL;
	S.stacksize = 0;
	free(S.base);
}
