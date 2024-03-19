#include <iostream>
#include "text.h"
#include "color.h"
using namespace std;

void gerar_linhas(char linha, int tamanho_linha, int text_color, int backg_color) 
{
	// gera linhas com tamanho, caracteres e cores diferentes
	for (int i = 0; i < tamanho_linha; i++) {
		cout << "\033[1;9" << text_color << "m\033[1;4" << backg_color
			<< "m" << linha << "\033[m";
	}
	cout << "\n";
}
char* upper(char* ch) 
{
	// transforma o texto em maiúsculo através da tabela ASCII
	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] >= 97 && ch[i] <= 122) {
			ch[i] -= 32;
		}
		else {
			ch = ch;
		}
	}
	return ch;
}
void alinhamento_left(char* text, int text_color, int backg_color, int qtd)
{
	cout.width(qtd); cout << left;
	show_color(text, text_color, backg_color);
}
void alinhamento_right(char* text, int text_color, int backg_color, int qtd)
{
	cout.width(qtd); cout << right;
	show_color(text, text_color, backg_color);
}
void alinhamento_left_int(int num, int text_color, int backg_color, int qtd)
{
	cout << "\033[1;9" << text_color << "m\033[1;4" << backg_color << "m";
	cout.width(qtd); cout << left;
	cout << num << "\033[m";
}
void alinhamento_right_int(int num, int text_color, int backg_color, int qtd)
{
	cout << "\033[1;9" << text_color << "m\033[1;4" << backg_color << "m";
	cout.width(qtd); cout << right;
	cout << num << "\033[m";
}
void alinhamento_left_float(float num, int text_color, int backg_color, int qtd)
{
	cout.width(qtd); cout << left;
	cout << "\033[1;9" << text_color << "m\033[1;4" << backg_color << "m" << num << "\033[m";
}
void alinhamento_right_float(float num, int text_color, int backg_color, int qtd)
{
	cout.width(qtd); cout << right;
	cout << "\033[1;9" << text_color << "m\033[1;4" << backg_color << "m" << num << "\033[m";
}
