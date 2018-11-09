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

/*
  Exercise 2-5 - Return the first location in string s1 where any character
  from the string s2 occurs, or -1 is s1 contains no characters from s2.

  Function is case-independent, meaning H = h
 */
 int any(char s1[], char s2[])
 {
   int pos = -1;    /* The position of any found character */
   int i, j;

   for (i = 0; s1[i] != '\0'; ++i)
   {
     for (j = 0; s2[j] != '\0'; ++j)
     {
       if (tolower(s1[i]) == tolower(s2[j]))
       {
         pos = i;
         break;
       }
     }
     if (pos >= 0)
      break;
   }

   return (int) pos;
 }

 /*
 Exercise 2-6, page 49 - Set n bits at position p in x to the rightmost n bits
 if y and return x.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  /*
  Step 1: Create an all-1's value the length of p-n to have trailing 1s:
    ~(~0 << (p+1-n))
  Step 2: Isolate n bits in y and shift to position p
    ((y & ~(~0 << n)) << (p+1-n))
  Step 3: OR isolated y with trailing 1s
    (~(~0 << (p+1-n))) | (((y & ~(~0 << n)) << (p+1-n)))
  Step 4: OR isolated y with a series of shifted 1s to account for MSBs in x
    ((~0 << (p+1))) | (~(~0 << (p+1-n))) | (((y & ~(~0 << n)) << (p+1-n)))
  Step 5: Set n bits in x at position p to y with AND
  */
  return (x & ((~0 << (p+1)) | (~(~0 << (p+1-n))))) | ((y & ~(~0 << n)) << (p+1-n));
}

/*
  Exercise 2-7, page 49: return x with the n bits beginning at position p
  inverted.
*/
unsigned invert(unsigned x, int p, int n)
{
  /*
    To invert 1 to 0:
      AND with 0
      XOR with 1
    To invert 0 to 1:
      AND with 0
      OR with 1
      XOR with 1
    Common thread: XOR n bits beginning at position p with all 1s
  */
  /*
  Step 1: Create n bits set to 1
    ~(~0 << (n))
  Step 2: Shift 1 bits to position p
    ~(~0 << (n)) << (p+1-n)
  Step 3: XOR with x
  */
  return (x ^ (~(~0 << (n)) << (p+1-n)));
}
