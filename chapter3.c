#include <stdio.h>
#include "common.h"


/*  Performs a binary search for element x
        in array v[], which has n elements      */

int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while ( low <= high ) {
        mid = (low+high) / 2;
        if ( x < v[mid] )
            high = mid - 1;
        else if ( x > v[mid] )
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/*
  Exercise 3-1: Rewrite binsearch() such that it requires only one
  test per loop
*/
int binsearch2(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  while(low <= high && x != v[mid])
  {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
  }
  if (x == v[mid])
    return mid;
  else
    return -1;
}
