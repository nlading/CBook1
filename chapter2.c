/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <limits.h>
#include <float.h>
#include <stdio.h>
#include "common.h"

void variableRanges() {
    printf("Exercise 2-1, Page 36\n");
    printf("BITS IN A CHAR: %d\n", CHAR_BIT);
    printf("CHAR MIN: %d\n", CHAR_MIN);
    printf("CHAR MAX: %d\n", CHAR_MAX);
    printf("INT MIN: %d\n", INT_MIN);
    printf("INT MAX: %d\n", INT_MAX);
    printf("LONG MIN: %ld\n", LONG_MIN);
    printf("LONG MAX: %ld\n", LONG_MAX);
    printf("SIGNED CHAR MIN: %d\n", SCHAR_MIN);
    printf("SIGNED CHAR MAX: %d\n", SCHAR_MAX);
    printf("SHRT MIN: %d\n", SHRT_MIN);
    printf("SHRT MAX: %d\n", SHRT_MAX);
    printf("UNSIGNED INT Max: %d\n", UINT_MAX);
    printf("UNSIGNED CHAR MAX: %d\n", UCHAR_MAX);
    printf("UNSIGNED Long MAX: %ld\n", ULONG_MAX);
    printf("UNSIGNED SHORT MAX: %d\n", USHRT_MAX);
}

/*
 * Exercise 2-3, page 45 - Convert a string of hexadecimal digits to its
 * equivalent value.
 */
int htoi(char s){
  return (int) s;
}
