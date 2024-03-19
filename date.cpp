#include <iostream>
#include "date.h"
#include "color.h"
using namespace std;

date read_date() {
	date date;
	char text[] = "Data: ";
	show_color(text, blue, black);
		// lendo a data
	cin >> date.day;
	cin.ignore(1);
	cin >> date.month;
	cin.ignore(1);
	cin >> date.year;

	return date;
}
void show_date(date d) {
	char text[] = "Data: ";
	show_color(text, blue, black);
		// exibindo a data
	cout << d.day << "/" << d.month << "/" << d.year;
}