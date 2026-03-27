#include <stdio.h>	/* for printf() and getchar() */
#include <stdlib.h>	/* for atof() */
#include <string.h>	/* for strcmp() */
#include <math.h>	/* for sin(), cos(), exp(), and pow() */

#define MAXOP 	100	/* max size of operand or operator */
#define NUMBER 	'0'	/* signal that a number was found */
#define NAME	'n'	/* signal that a name was found */

int getop(char s[]);
void push(double f);
double pop(void);
void clear(void);
void mathfnc(char s[]);

/* reverse Polish (postfix) calculator */
int main()
{
	int type;		/* number, mathfnc name, operator, or newline */
	double op1, op2;	/* holders for non-commutative operations and swapping */
	char s[MAXOP];		/* holds number for atof(), or name for mathfnc() */

	while((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfnc(s);
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
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '?':	/* print top element of the stack */
				op2 = pop();
				printf("\t%.8lf\n", op2);
				push(op2);
				break;
			case 'c':	/* clear the stack */
				clear();
				break;
			case 'd':	/* duplicate top element of the stack */
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's':	/* swap the top two elements */
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
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

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[])
{
	double op2;

	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));	/* returns euler's number raised to the argument */
	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	} else
		printf("error: %s is not supported \n", s);
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

/* clear: clear the stack */
void clear(void) {
	sp = 0;
}

#include <ctype.h>	/* for isdigit() and islower() */

int getch(void);	/* read from this program's input buffer */
void ungetch(int);	/* push (most likely whitespace) into this program's input buffer */

/* getop: get next operator or numberic operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') /* move c past whitespace */
		;		/* breaks when non-whitespace appended */
	s[1] = '\0';
	i = 0;
	if (islower(c)) {	/* command or NAME */
		while (islower(s[++i] = c = getch()))	/* read into s starting at index 1 */
			;
		s[i] = '\0';	/* replace last non-digit with null in case of strcmp() */
		if (c != EOF)
			ungetch(c);	/* push whitespace into program buffer */
		if (strlen(s) > 1)
			return NAME;	/* it is a mathfnc name */
		else
			return c;	/* it is a lowercase command */
	}
	if (!isdigit(c) && c != '.')
		return c;	/* operator symbol, or non-lowercase command */
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))	/* breaks when non-digit appended */
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))	/* breaks when non-digit appended */
			;
	s[i] = '\0';	/* repace last non-digit with null for atof() */
	if (c != EOF)
		ungetch(c);	/* push whitespace non-digit into program buffer */
	return NUMBER;
}

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void)	/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
