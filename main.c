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
#include "common.h"
#include "chapter1.h"
#include "chapter2.h"

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
    */
    char s1[] = "This is the first string";
    char s2[] = "xyz";
    unsigned x = 555;
    int p = 8;
    int n = 3;
    unsigned y = 19;
    unsigned result = invert(x, p, n);
    printf("Result: %u\n", result);
    return 0;
}
