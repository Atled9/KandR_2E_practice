#include "line_utils.h"

char line[MAXLINE];	/* current input line */

/* print longest input line; using external variables */
int main()
{
	int in_len;
	int in_pos, out_pos;
	int spaces, out_pos_holder;

	while ((in_len = get_line()) > 0) {
		out_pos = 0;

		/* line[in_len - 1] = '\n' */
		for (in_pos = 0; in_pos < in_len; ++in_pos) {
			if (line[in_pos] == ' ') {
				spaces = 0;
				for (out_pos_holder = out_pos; line[out_pos_holder] == ' '; ++out_pos_holder)
					++spaces;
				while (spaces > 0) {
					if (spaces >= (out_pos/TABSTOP + 1)*TABSTOP - out_pos) {
						printf("\t");
						spaces = spaces - ((out_pos/TABSTOP + 1)*TABSTOP - out_pos);
						out_pos = (out_pos/TABSTOP + 1)*TABSTOP;
					}
					else {
						printf(" ");
						--spaces;
						++out_pos;
					}
				}
			} else {
				printf("%c", line[in_pos]);
				++out_pos;
			}
		}
	}
	return 0;
}
