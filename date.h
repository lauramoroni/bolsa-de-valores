#pragma once

struct date {
	int day;
	int month;
	int year;
};

// protótipos
date read_date();
void show_date(date);
// protótipos
/*
istream& operator>>(istream&, date&); // ler dados
ostream& operator<<(ostream&, date); // exibir dados
*/