/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   chapter1.h
 * Author: nlading
 *
 * Created on November 8, 2018, 10:27 AM
 */

#ifndef CHAPTER1_H
#define CHAPTER1_H

/* Variable Definitions */
#define LOWER 0     /* lower limit of temp conversion table */
#define UPPER 300   /* Upper limit */
#define STEP  20    /* step size */
#define IN 1        /* Tracks whether execution is in a single state */
#define OUT 0       /* Tracks whether execution is out of a single state */

int fahrConvert();
int celConvert();
void tempConvertForLoop();
void fileCopy();
void whiteSpaceCounter();
void singleSpaceEdit();
void obviousEscapes();
void inputHistogram();
void foldLines(int);
void syntaxCheck();

#endif /* CHAPTER1_H */
