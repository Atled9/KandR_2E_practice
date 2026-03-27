#include "strindex.h"

int main()
{
	char line[MAXLINE];
	char pattern[] = "ould";

	int found = 0;
	FILE* file_p = fopen("Omar_Khayyam_quatrain.txt", "r");

	while (fgets(line, MAXLINE, file_p) != NULL)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}
