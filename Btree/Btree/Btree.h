#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct BNode {
	int data;
	Btree left;
	Btree right;
}*Btree;


