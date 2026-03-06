#ifndef SEARCH_UTILS
#define SEARCH_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DSIZE 20
#define ASIZE 640000
#define TESTS 256000

int comp(const void *a, const void *b);
int binsearch(int x, int v[], int n);
int binsearch_mod(int x, int v[], int n);

#endif
