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

/* Variable Definitions */
#define LOWER 0     /* lower limit of temp conversion table */
#define UPPER 300   /* Upper limit */
#define STEP  20    /* step size */

/* Function Declarations */
int fahrConvert();
int celConvert();
int tempConvertForLoop();
int fileCopy();
int whiteSpaceCounter();
int singleSpaceEdit();
int obviousEscapes();

/*
 * 
 */
int main() {
    /* Chapter 1 */
    /*
    printf("hello, world\n");
    printf("\nExercise 1-3, page 12\n");
    fahrConvert();
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
    */
}

/* C Programming Language Exercise 1-3, page 12
 * print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300
 */
int fahrConvert(){
    float fahr, celsius;
    
    printf("Fahrenheit to Celsius Conversion Table\n");
    printf(" %3s | %6s\n", "F", "C");
    printf("-------------\n");
    
    fahr = LOWER; 
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf(" %3.0f | %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
    
    return 1;
}

/*
 * C Programming Language Exercise 1-4, page 12
 * Print Celsius-Fahrenheit table for cel = 0, 10, ..., 100
 */
int celConvert() {
    float fahr, celsius;
    
    printf("Celsius to Fahrenheit Conversion Table\n");
    printf(" %3s | %6s\n", "C", "F");
    printf("-------------\n");
    
    celsius = LOWER;
    while (celsius <= UPPER) {
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf(" %3.0f | %6.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
    
    return 1;
}

/*
 * Fahrenheit to Celsius conversion using a FOR loop
 * Print Fahrenheit to Celsius table for Fahr = 0, 20, ..., 300
 */
int tempConvertForLoop(){
    int fahr;
    
    printf("Fahrenheit to Celsius Conversion Table\n");
    printf(" %3s | %6s \n", "F", "C");
    printf("--------------\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf(" %3d | %6.1f \n", fahr, (5.0/9.0)*(fahr-32));
    
    printf("Fahrenheit to Celsius Conversion Table (Reversed)\n");
    printf(" %3s | %6s \n", "F", "C");
    printf("--------------\n");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf(" %3d | %6.1f \n", fahr, (5.0/9.0)*(fahr-32));
}

/* File Copying Example, Page 15 
 * Example interaction:
 * input: This is a new line (hit enter key)
 * output: This is a new line\n 
 */
int fileCopy() {
    int c;
    long nc = 0;    /* string counter */
    
    while ((c = getchar()) != EOF) {
        ++nc;
        putchar(c);
    }
    printf("\nEOF = %d\n", c);
    printf("Count = %ld\n", nc);
}

/* 
 * Exercise 1-8 - Count blanks, tabs, and newlines
 * ctrl-d to exit
 */
int whiteSpaceCounter() {
    int bc = 0, tc = 0, nc = 0;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nc;
        } else if(c == '\t') {
            ++tc;
        } else if(c == ' ') {
            ++bc;
        } else {
            ;
        }
    }
    
    printf("Blank Spaces = %d, Tabs = %d, New Lines = %d\n", bc, tc, nc);
}

/*
 * Exercise 1-9 - Replace multiple white space sections with a single space
 */
int singleSpaceEdit() {
    int c;
    int sc = 0;     /* space counter, tracks when multiple spaces occur */
    
    while ((c = getchar()) != EOF) {
        if ((c == '\t' || c == ' ') && sc > 0) {
            /* Do nothing if multiple white space detected */  
            ;
        } else if (c != ' ' && c != '\t') {
            /* c is a character, print it */
            putchar(c);
            sc = 0;
        } else if ((c == ' ' || c == '\t') && sc == 0) {
            /* c is a whitespace value immediately after a non-whitespace value */
            putchar(' ');
            ++sc;
        }
    }
}

/*
 * Exercise 1-10 - Obvious Escapes 
 * Cannot manage backspace. Apparently "beyond programmatic control"
 */
int obviousEscapes(){
    int c;
    
    while ((c = getchar()) != EOF){
        switch (c) {
            case '\t': putchar ('\\'); putchar ('t'); break;
            case '\b': putchar ('\\'); putchar ('b'); break;
            case '\\': putchar ('\\'); putchar ('\\'); break;
            default:   putchar (c);
        }
    }
}