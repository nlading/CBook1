/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: nlading
 *
 * Created on November 7, 2018, 9:07 AM
 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include "common.h"
#include "chapter1.h"
#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"

/*
 *
 */
int main() {
    /* Chapter 1 */
    /*
    printf("hello, world\n");
    printf("\nExercise 1-3, page 12\n");
    fahrConvert()
    printf("\nExercise 1-4, page 12\n");
    celConvert();
    printf("\nExercise 1-5, Page 14\n");
    tempConvertForLoop();
    printf("\nExample, page 15\n");
    fileCopy();
    printf("\nExercise 1-8, page 19\n");
    whiteSpaceCounter();
    printf("\nExercise 1-9, page 19\n");
    singleSpaceEdit();
    printf("\nExercise 1-10, page 19\n");
    obviousEscapes();
    printf("\nExercise 1-13, page 24\n");
    inputHistogram();
    foldLines(10);
    syntaxCheck();
    */
    /* Chapter 2 */
    /*
    variableRanges();
    squeeze();
    int result = any(s1, s2);
    int setbits_result = setbits(65535, 15, 4, 5);
    unsigned rotate_result = rightrot(x, n);

    char s1[] = "This is the first string";
    char s2[] = "xyz";
    unsigned x = 555;
    int p = 5;
    int n = 3;
    unsigned y = 19;
    char c[5] = {'A', 'a', 'y', '\?', '*'};
    for (int i = 0; c[i] != '\0'; ++i)
    {
      printf("%c converted to: %c\n", c[i], lower(c[i]));
    }
    */
    /* Chapter 3 */
    /* Comparing runtime */
    /*
    Exercise 3-1
    int v[MAXELEMENT];
    int i, result1, result2;
    clock_t time_taken;
    for (int i = 0; i <= MAXELEMENT; i++)
      v[i] = i;

    // Perform process
    for (i = 0, time_taken = clock(); i <= 100000000; i++)
      result1 = binsearch(-1, v, MAXELEMENT);
    time_taken = clock() - time_taken;

    double time_spent = (unsigned long)time_taken / CLOCKS_PER_SEC;
    printf("Time consumed v1: %ld\n", time_spent);

    // Perform process
    for (i = 0, time_taken = clock(); i <= 100000000; i++)
      result2 = binsearch2(-1, v, MAXELEMENT);
    time_taken = clock() - time_taken;

    time_spent = (unsigned long)time_taken / CLOCKS_PER_SEC;
    printf("Time consumed v2: %ld\n", time_spent);

    printf("Result 1: %d\nResult 2: %d\n", result1, result2);
    char instring[100];
    int n = -pow(2, INT_MAX-2);
    itoa(n, instring);
    printf("Original: %d\nResult: %s", n, instring);
    */

    /* Chapter 4 */
    char source[MAXLINE] = "\
Ah Love! could you and I with Fate conspire\n\
To grasp this sorry Scheme of Things entire,\n\
Would not we shatter it to bits -- and then\n\
Re-mould it nearer to the Heart\'s Desire!\n\
    ";
    char pattern[] = "ould";

    int i;

    printf("Searching for\n\n%s\n\nin\n\n%s\n", pattern, source);

    i = pattern_search(source, pattern);
    printf("Result: %d", i);


    return 0;
}
