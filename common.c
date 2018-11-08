/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>

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
