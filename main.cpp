#include <iostream>
#include "color.h"
#include "date.h"
#include "text.h"
#include "stock.h"
using namespace std;

int main() {
	// CARTEIRA DE A��ES
	// vetor de caracteres referente aos t�tulos para serem chamado na fun��o show_color()
	char text_titulo[][80] = { "Carteira de A��es\n", "Quantidade de empresas: [ ]\b\b","Transa��es Realizadas\n\n", "Resumo da Carteira\n\n", "Rentabilidade da Carteira\n", "Aporte anual R$[    ]\b\b\b\b\b", "Rendimento anual estimado [  ]%\b\b\b\b", "Rentabilidade da Carteira" };

	show_color(text_titulo[0], white, cyan);

	cout << endl;

	show_color(text_titulo[1], blue, black);

	// define a quantidade de empresas
	int num_empresas;
	cin >> num_empresas;

	// define caractere da linha
	char linha = '-';

	gerar_linhas(linha, 40, cyan, black);

	// vetor din�mico para guardar os dados
	empresa* vetor_empresa = new empresa[num_empresas];

	// la�o de repeti��o para ler os dados de cada empresa 
	for (int i = 0; i < num_empresas; i++)
	{
		// vetor de caracteres para serem par�metros da fun��o show_color()
		char text_empresa[3][15] = { "Empresa: ", "Ticker: ", "Transa��es: " };

		show_color(text_empresa[0], blue, black);
		cin.ignore();
		cin.getline(vetor_empresa[i].nome, 50); // permite entrada com espa�os

		show_color(text_empresa[1], blue, black);
		cin >> vetor_empresa[i].codigo;

		show_color(text_empresa[2], blue, black);
		cin >> vetor_empresa[i].num_transacoes;

		gerar_linhas(linha, 40, cyan, black);
	}

	system("cls");


	// TRANSA��ES REALIZADAS

	show_color(text_titulo[2], white, cyan);

	// la�o de repeti��o para ler todas as empresas
	for (int i = 0; i < num_empresas; i++) {

		// nome da empresa
		show_color(vetor_empresa[i].nome, cyan, black);
		char traco[] = " - ";
		show_color(traco, cyan, black);
		show_color(upper(vetor_empresa[i].codigo), cyan, black);
		cout << "\n\n";


		vetor_empresa[i].transacoes = new transacao[vetor_empresa[i].num_transacoes];

		// la�o de repeti��o para ler as transa��es de cada empresa
		for (int j = 0; j < vetor_empresa[i].num_transacoes; j++)
		{
			// cria um vetor din�mico para cada empresa


			// vetor de caracteres para serem par�metros da fun��o show_color()
			char text_transacao[2][15] = { "Quantidade: ", "Pre�o: " };

			// atribui os valores de data para o vetor din�mico das transa��es da empresa
			vetor_empresa[i].transacoes[j].data = read_date(); // l� a data

			show_color(text_transacao[0], blue, black);
			cin >> vetor_empresa[i].transacoes[j].quantidade; // quantidade de a��es

			show_color(text_transacao[1], blue, black);
			cin >> vetor_empresa[i].transacoes[j].preco; // pre�o de cada a��o

			cout << endl;

		}


	}


	system("cls");

	// RESUMO DA CARTEIRA

	alinhamento_left(text_titulo[3], white, cyan, 60);
	gerar_linhas(linha, 80, cyan, black);

	char text_resumo[5][20] = { " Empresa ", " Ticker ", " Qtd. ", " Pre�o M�dio ", " Investido " };

	alinhamento_left(text_resumo[0], white, cyan, 12);
	alinhamento_right(text_resumo[1], white, cyan, 12);
	alinhamento_right(text_resumo[2], white, cyan, 12);
	alinhamento_right(text_resumo[3], white, cyan, 12);
	alinhamento_right(text_resumo[4], white, cyan, 12);

	cout << "\n";


	float total_investido = resumo_da_carteira(vetor_empresa, num_empresas);

	gerar_linhas(linha, 80, cyan, black);
	cout << "\033[1;9" << white << "m\033[1;4" << cyan
		<< "m" << "Total investido:";
	cout.width(65);
	cout << total_investido << "\033[m";

	cout << endl;

	system("pause");
	system("cls");

	// RENTABILIDADE DA CARTEIRA

	// define os dados para gerar a rentabilidade da carteira
	float aporte_anual;
	show_color(text_titulo[5], blue, black);
	cin >> aporte_anual;

	int rendimento_anual;
	show_color(text_titulo[6], blue, black);
	cin >> rendimento_anual;

	cout << "\n";

	// t�tulo
	show_color(text_titulo[4], white, cyan);
	gerar_linhas(linha, 80, cyan, black);

	char text_rentabilidade[5][20] = { " Ano  ", " Investido  ", " Rendimento  ", " Acumulado  ", " Gr�fico " };

	alinhamento_left(text_rentabilidade[0], white, cyan, 5);
	alinhamento_left(text_rentabilidade[1], white, cyan, 12);
	alinhamento_left(text_rentabilidade[2], white, cyan, 12);
	alinhamento_left(text_rentabilidade[3], white, cyan, 12);

	float investido[21] = { total_investido };

	cout << "\n";
	// Exibe o primeiro valor da rentabilidade
	alinhamento_left_int(0, white, cyan, 5); cout << " ";
	alinhamento_left_float(total_investido, white, black, 5);

	for (int i = 1; i <= 20; i++)
	{
		// Adiciona ao vetor de �ndice i o elemento anterior + o aporte
		investido[i] = investido[i - 1] + aporte_anual;
		cout << "\n";
		alinhamento_left_int(i, white, cyan, 5); cout << " ";
		alinhamento_left_float(investido[i], white, black, 10);

		//float acumulado[21] =
	}

	// Deleta cada vetor din�mico criado
			for (int i = 0; i < num_empresas; i++)
			{
				delete[] vetor_empresa;
			}

	return 0;
}