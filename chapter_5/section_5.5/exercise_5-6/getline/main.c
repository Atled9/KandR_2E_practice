#define MAXLINE 1000

int printf(const char *restrict format, ...);
void getline(char *s);

int main()
{
	char line[MAXLINE];
	getline(line);
	printf("%s", line);

	return 0;
}
