#include <stdio.h>
#include <time.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
	time_t current = time(NULL);
	struct tm *t = localtime(&current);

	int current_year = t->tm_year + 1900;
	int current_month = t->tm_mon + 1;
	int current_day = t->tm_mday;

	int yearday, month, day;

	printf("date: %d %d %d\n", current_year, current_month, current_day);

	yearday = day_of_year(current_year, current_month, current_day);
	printf("day of year: %d\n", yearday);

	month_day(2026, yearday, &month, &day);
	printf("month: %d, day: %d\n", month, day);

	return 0;
}
