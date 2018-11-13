#include <stdio.h>
#include <string.h>
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

  According to my tests, there is no difference in runtime. However, my test pc
  is very very powerful
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

/*
  From K&R page 62: reverse string s in place
*/
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/*
  Exercise 3-4: Modify itoa in the book to handle the largest
  negative number
*/
void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)   /* record sign */
    n = -n;             /* make n positive */

  i = 0;
  do {    /* generate digits in reverse order */
    s[i++] = n % 10 + '0';  /* get next digit */
  } while ((n /= 10) > 0);  /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
