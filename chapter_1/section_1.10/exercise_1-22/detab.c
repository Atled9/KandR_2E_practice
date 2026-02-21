#include "detab.h"

void detab(char arr[], char arr_d[]) 
{
	int tabspace, spaces;
	int in_pos, d_pos;

	in_pos = d_pos = 0;
	for(in_pos = 0; arr[in_pos] != '\0'; ++in_pos) {
		if (arr[in_pos] == '\t') {
			
			tabspace = ((d_pos/TABSTOP) + 1)*TABSTOP - d_pos;
			for(spaces = 0; spaces < tabspace; ++spaces) {
				arr_d[d_pos] = ' ';
				++d_pos;
			}
		} else {
			arr_d[d_pos] = arr[in_pos];
			++d_pos;
		}
	}
	arr_d[d_pos] = '\0';
	return;
}

