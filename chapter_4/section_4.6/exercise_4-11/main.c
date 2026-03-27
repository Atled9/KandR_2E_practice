#include <stdio.h>	/* for printf() and getchar() */
#include <stdlib.h>	/* for atof() */

#define MAXOP 	100	/* max size of operand or operator */
#define NUMBER 	'0'	/* signal that a number was found */

int getop(char []);
void push(double f);
double pop(void);

/* reverse Polish (postfix) calculator */
int main()
{
	int type;	/* number, operator, or newline */
	double op2;	/* holder for non-commutative operations */
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8lf\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

/* The order in which the two calls of pop in push(pop() - pop()) are evaluated
 * is not defined. To guarantee the right order, it us necessary to pop the first
 * value into a temporary variable (op2). However, + and * are commutative. 
 * */

#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %lf\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>	/* for isdigit() */

int getch(void);	/* read from this program's input buffer */
void ungetch(int);	/* push (most likely whitespace) into this program's input buffer */

/* getop: get next operator or numberic operand */
int getop(char s[])
{
	int i, c;
	static int buff = '\0';

	if (buff == '\0')
		c = getch();
	else {
		c = buff;
		buff = '\0';
	}

	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();		/* move c past whitespace*/
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number (most likely an operator symbol) */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))	/* breaks when non-digit appended */
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))	/* breaks when non-digit appended */
			;
	s[i] = '\0';	/* repace last non-digit with null for atof() */
	if (c != EOF)
		buff = c;	/* push whitespace non-digit into program buffer */
	return NUMBER;
}
/*
#define BUFSIZE	100

char buf[BUFSIZE];	
int bufp = 0;		
*/
int getch(void)	
{
	return getchar();
}
/*
void ungetch(int c)	
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
*/
