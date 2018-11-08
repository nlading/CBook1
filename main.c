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
#define IN 1        /* Tracks whether execution is in a single state */
#define OUT 0       /* Tracks whether execution is out of a single state */

/* Function Declarations */
int fahrConvert();
int celConvert();
int tempConvertForLoop();
int fileCopy();
int whiteSpaceCounter();
int singleSpaceEdit();
int obviousEscapes();
int inputHistogram();
void foldLines(int);
void syntaxCheck();

void resetStringArray(char *, int);

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
    */
    syntaxCheck();
    
    return 0;
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

/* Exercise 1-13 - Histogram of input 
 * Produces a horizontal and a vertical histogram of the lengths
 * of words in an input.
 */
int inputHistogram() {
    int c, i, j;
    int ndigit[UPPER];
    int len = 0, max = 0;
    
    /* initialize digit counting array to 0 */
    for (i = 0; i < UPPER; ++i)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') 
        {
            if (len > 0)
                ++ndigit[len];
            len = 0;
        } 
        else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        {
            /* A character is recognized, a word exists */
            ++len;
        }
    
    /* Produce horizontal histogram */
    printf("\nHorizontal Histogram of Word Length in Input\n");
    for (i = 0; i < UPPER; ++i){
        if (ndigit[i] > 0){
            printf("%3d: ", i);
            for (j = 0; j < ndigit[i]; ++j)
                printf("-");
            printf("\n");
        }
    }
        
    /* Produce vertical histogram */
    /* Find max count */
    for (i = 0; i < UPPER; ++i){
        if (ndigit[i] > max)
            max = ndigit[i];
    }
    /* Create histogram "bars" */
    printf("\nVertical Histogram of Word Length in Input\n");
    for (i = max; i > 0; --i)
    {
        for (j = 0; j < UPPER; ++j)
        {
            if (ndigit[j] > 0 && ndigit[j] >= i)
            {
                printf("%3s", "|");
            }
            else if (ndigit[j] > 0 && ndigit[j] < i)
            {
                printf("%3s", " ");
            }
        }
        printf("\n");
    }
    /* Print labels */
    for (i = 0; i < UPPER; ++i)
    {
        if (ndigit[i] > 0)
        {
            printf("%3d", i);
        }
    }
}

/* Exercise 1-22 - fold long input lines into two or more shorter lines 
 * after the last non-blank character that occurs before the n-th col of input
 * 
 * Issues: Adds a space or whitespace character to every end of line. 
 *          - Will not pursue a fix for now.
 */
void foldLines(int maxlength){
    int c, i;
    int linelen = 0;
    int wordlen = 0;
    char word[UPPER];
    
    printf("\nExercise 1-22, page 33\n");
    
    while ((c = getchar()) != EOF)
    {
       /* Pull next word in the input */
        if (c == ' ' || c == '\t' || c == '\n')
        {
            /* Print word if added chars is less than max line length */
            if (linelen + wordlen > maxlength && wordlen <= maxlength)
            {
                /* Print word on new line if word cannot fit on current line */
                printf("\n%s", word);
                linelen = 0;
            }
            else if (linelen + wordlen > maxlength && wordlen > maxlength)
            {
                /* Print word over multiple lines if word length > line length */
                for (i = 0; i < wordlen; ++i)
                {
                    if (i > 0 && i % (maxlength-1) == 0)
                    {
                        printf("-\n");
                        linelen = 0;
                    }
                    printf("%c", word[i]);
                    linelen++;
                }
            }
            else
            {
                /* Print the word if it fits on the line */
                printf("%s", word);
                linelen = linelen + wordlen;
            }
            putchar(c);
            linelen++;
            wordlen = 0;
            for (i = 0; i < UPPER; i++)
            {
                word[i] = 0;
            }
        }
        else
        {
            word[wordlen] = c;
            wordlen++;
        }
    }
}

/* 
 * Exercise 1-23 & 1-24 - Remove comments from a C program and check for 
 * rudimentary syntax errors.
 * 
 * Checks Syntax one line at a time, as of 11/8/18 it does not have multi-line 
 * functionality. 
 */
void syntaxCheck() {
    int c, i, j;
    int lineCount = 1;
    int startParenthesis = 0, endParaenthesis = 0;
    char currLine[UPPER];
    int lineLen = 0;
    
    char pairedCharacters[10] = {'(', ')',
                                 '{', '}',
                                 '[', ']',
                                 '<', '>',
                                 '\'', '\"',
    };
    int pairOccurrances[10] = {0};
    
    printf("\n");
    
    while ((c = getchar()) != EOF)
    {
        /* Traverse input, line by line */
        if (c == '\n')
        {
            /* Report missing end of line semicolons */
            if (currLine[lineLen-1] != 59)
            {
                printf("\nERROR: Missing semicolon on line: %d\n", lineCount);
            }
            /* Check for balanced brackets/parenthesis/etc. */
            /* ***Needs to be improved to allow for multi-line syntax */
            for (i = 0; currLine[i] != 0; ++i)
            {
                /* Tally paired characters */
                for (j = 0; j <= 9; ++j)
                {
                    if (currLine[i] == pairedCharacters[j])
                        pairOccurrances[j] = ++pairOccurrances[j];
                }
            }
            if (pairOccurrances[0] != pairOccurrances[1])
                printf("\nERROR: Unbalanced () pair on line %d\n", lineCount);
            if (pairOccurrances[2] != pairOccurrances[3])
                printf("\nERROR: Unbalanced {} pair on line %d\n", lineCount);
            if (pairOccurrances[4] != pairOccurrances[5])
                printf("\nERROR: Unbalanced [] pair on line %d\n", lineCount);
            if (pairOccurrances[6] != pairOccurrances[7])
                printf("\nERROR: Unbalanced <> pair on line %d\n", lineCount);
            if ((pairOccurrances[8] % 2) != 0)
                printf("\nERROR: Unbalanced single-quote pair on line %d\n", lineCount);
            if ((pairOccurrances[9] % 2) != 0)
                printf("\nERROR: Unbalanced double-quote pair on line %d\n", lineCount);
            
            /* Reset line string array and counters */
            for (i = 0; i < 10; ++i)
                pairOccurrances[i] = 0;
            resetStringArray(currLine, 0);
            lineLen = 0;
            lineCount++;
        }
        else
        {
            currLine[lineLen] = c;
            ++lineLen;
        }
    }
}

/*
 * Sets all values in the passed in array (instring) to a value specified
 * by (defaultVal) 
 */
void resetStringArray(char* instring, int defaultVal){
    int arraySize = 0;
    char n;
    while (instring[arraySize] != 0)
        ++arraySize;
    for (int i = 0; i < arraySize; ++i)
    {
        instring[i] = defaultVal;
    }
}