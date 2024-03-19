#include "color.h"
#include <iostream>
using namespace std;

	// altera a cor do texto e do fundo do vetor indicado
void show_color(char* text, int text_color, int backg_color) {
	cout << "\033[1;9" << text_color << "m\033[1;4" << backg_color
		<< "m" << text << "\033[m";
}
