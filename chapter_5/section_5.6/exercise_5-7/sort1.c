#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000		/* max #lines to be sorted */
#define ALLOCSIZE 100000	/* size of available space */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *allocbuf);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

FILE *file_p = NULL;

/* sort input lines */
int main()
{
	char allocbuf[ALLOCSIZE];	/* alloc */

	file_p = fopen("randlines.txt", "r");
	int nlines;	/* number of input lines read */

	clock_t begin = clock();
	if ((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0) {
		clock_t end = clock();
		double diff_t = (double)(end - begin) / CLOCKS_PER_SEC;

		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		fclose(file_p);
		printf("readlines() runtime: %le\n", diff_t);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		fclose(file_p);
		return 1;
	}
}

#define MAXLEN 1000	/* max length of any input line */
int get_line(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *allocbuf)
{
	int len, nlines;
	char line[MAXLEN], *p = allocbuf;

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=fgetc(file_p))!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left,int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
