#include <stdio.h>
#include <string.h>
#include "common.h"
#include "chapter4.h"

int pattern_search(char line[], char pattern[])
{
	int found = 0;

	while(get_line(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* getline: get line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
	{
		s[i++] = c;
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}



