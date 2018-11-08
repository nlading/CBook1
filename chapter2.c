/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <limits.h>
#include <float.h>
#include <stdio.h>
#include <ctype.h>
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
 *
 * I am ignoring this one because the prompt is unclear
 */

/*
  Exercise 2-4, Page 48 - rewrite squeeze(s1,s2) such that it deletes each
  character in s1 that matches any character in the string s2.

  Original squeeze:
  void squeeze(char s[], int c)
  {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
      if (s[i] != c)
        s[j++] = s[i];
    s[j] = '\0';
  }
 */
 void squeeze()
 {
   char s1[] = "Hidy Ho There Partnerino!";
   char s2[] = "Hoe";
   int i, j, k;
   int deleteChars[93] = {0};

   printf("Original: %s\n", s1);

   /* determine which characters are in s2 to avoid duplicates */
   for (i = 0; s2[i] != '\0'; i++)
   {
    j = s2[i];
    if (33 <= s2[i] && s2[i] <= 126)
    {
      deleteChars[s2[i]-33] = 1;
    }
   }
   /* Remove True vals in deleteChars from s1 */
   for (i = 0; i < sizeof(deleteChars)/sizeof(int); ++i)
   {
     if (deleteChars[i] == 1)
     {
       printf("Checking on: %c\n", i+33);
       for (j = k = 0; s1[j] != '\0'; j++)
       {
         if (s1[j] != i+33)
          s1[k++] = s1[j];
       }
     }
   }
   s1[k] = '\0';
   /* Display Result */
   printf("Result: %s\n", s1);
 }
