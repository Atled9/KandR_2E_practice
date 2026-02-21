#include "detab.h"

int main()
{
	char line[MAXLINE];
	char line_detab[MAXLINE];
	int in_pos, out_pos;
	int begin, end;
	int inside_word;
	int word_len, word_pos;

	while (fgets(line, MAXLINE, stdin) != NULL) {

		detab(line, line_detab);
		begin = end = 0;
		out_pos = 0;
		inside_word = FALSE;

		for (in_pos = 0; line_detab[in_pos] != '\0'; ++in_pos) {
			if (line_detab[in_pos] != ' ' && !inside_word) {
				inside_word = TRUE;
				begin = in_pos;
			}
			if ((line_detab[in_pos] == ' ' || line_detab[in_pos] == '\n') && inside_word) {
				inside_word = FALSE;
				end = in_pos - 1;

				word_len = end - begin + 1;
				
				if (out_pos + word_len > MAXCHAR && out_pos != 0) {
					fputc('\n', stdout);
					out_pos = 0;
				}
				for (word_pos = begin; word_pos <= end; ++word_pos) {
					if (out_pos >= MAXCHAR) { // folds when word_len > MAXCHAR
						fputc('\n', stdout);
						out_pos = 0;
					}
					fputc(line_detab[word_pos], stdout);
					++out_pos;
				}
			}
			if (line_detab[in_pos] == ' ' && !inside_word) {
				if (out_pos + 1 <= MAXCHAR) {
					fputc(' ', stdout);
					++out_pos;
				}
			}
			if (line_detab[in_pos] == '\n') {
				fputc('\n', stdout);
			}
		}
	}
	return 0;
}
