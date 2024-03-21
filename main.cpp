#include <iostream>
#include <cmath>
#include "color.h"
#include "date.h"
#include "text.h"
#include "stock.h"
using namespace std;

int main() {
	// CARTEIRA DE AÇÕES
	// vetor de caracteres referente aos títulos para serem chamado na função show_color()
	char text_titulo[][100] = { "Carteira de Ações\n", "Quantidade de empresas: [ ]\b\b","Transações Realizadas\n\n", "                              Resumo da Carteira                                \n", "                            Rentabilidade da Carteira                           \n", "Aporte anual R$[    ]\b\b\b\b\b", "Rendimento anual estimado [  ]%\b\b\b\b", "Rentabilidade da Carteira" };

	show_color(text_titulo[0], white, cyan);

	cout << endl;

	show_color(text_titulo[1], blue, black);

	// define a quantidade de empresas
	int num_empresas;
	cin >> num_empresas;

	// define caractere da linha
	char linha = '-';

	gerar_linhas(linha, 40, cyan, black);

	// vetor dinâmico para guardar os dados
	empresa* vetor_empresa = new empresa[num_empresas];

	// laço de repetição para ler os dados de cada empresa 
	for (int i = 0; i < num_empresas; i++)
	{
		// vetor de caracteres para serem parâmetros da função show_color()
		char text_empresa[3][15] = { "Empresa: ", "Ticker: ", "Transações: " };

		show_color(text_empresa[0], blue, black);
		cin.ignore();
		cin.getline(vetor_empresa[i].nome, 50); // permite entrada com espaços

		show_color(text_empresa[1], blue, black);
		cin >> vetor_empresa[i].codigo;

		show_color(text_empresa[2], blue, black);
		cin >> vetor_empresa[i].num_transacoes;

		gerar_linhas(linha, 40, cyan, black);
	}

	system("cls");


	// TRANSAÇÕES REALIZADAS

	show_color(text_titulo[2], white, cyan);

	// laço de repetição para ler todas as empresas
	for (int i = 0; i < num_empresas; i++) {

		// nome da empresa
		show_color(vetor_empresa[i].nome, cyan, black);
		char traco[] = " - ";
		show_color(traco, cyan, black);
		show_color(upper(vetor_empresa[i].codigo), cyan, black);
		cout << "\n\n";


		// cria um vetor dinâmico para cada empresa
		vetor_empresa[i].transacoes = new transacao[vetor_empresa[i].num_transacoes];

		// laço de repetição para ler as transações de cada empresa
		for (int j = 0; j < vetor_empresa[i].num_transacoes; j++)
		{
			// vetor de caracteres para serem parâmetros da função show_color()
			char text_transacao[2][15] = { "Quantidade: ", "Preço: " };

			// atribui os valores de data para o vetor dinâmico das transações da empresa
			vetor_empresa[i].transacoes[j].data = read_date(); // lê a data

			show_color(text_transacao[0], blue, black);
			cin >> vetor_empresa[i].transacoes[j].quantidade; // quantidade de ações

			show_color(text_transacao[1], blue, black);
			cin >> vetor_empresa[i].transacoes[j].preco; // preço de cada ação

			cout << endl;

		}


	}


	system("cls");

	// RESUMO DA CARTEIRA

	alinhamento_left(text_titulo[3], white, cyan, 60);
	gerar_linhas(linha, 80, cyan, black);

	char text_resumo[5][20] = { " Empresa ", " Ticker ", " Qtd. ", " Preço Médio ", " Investido " };

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
	show_color(text_titulo[5], cyan, black);
	cin >> aporte_anual;

	float rendimento_anual;
	show_color(text_titulo[6], cyan, black);
	cin >> rendimento_anual;
	rendimento_anual /= 100;

	cout << "\n";

	// título
	show_color(text_titulo[4], white, cyan);
	gerar_linhas(linha, 80, cyan, black);

	char text_rentabilidade[5][50] = { " Ano  ", " Investido     ", "   Rendimento ", " Acumulado ", "      Gráfico                     " };

	alinhamento_left(text_rentabilidade[0], white, cyan, 5);
	alinhamento_left(text_rentabilidade[1], white, cyan, 18);
	alinhamento_left(text_rentabilidade[2], white, cyan, 25);
	alinhamento_left(text_rentabilidade[3], white, cyan, 12);
	alinhamento_left(text_rentabilidade[4], white, cyan, 12);

	float investido[21] = { total_investido };
	float acumulado[21] = { total_investido };
	float rendimento[21] = { 0 };

	cout << "\n";

	// Variáveis para gerar o gráfico
	int normalizado[21];
	char quadrado = '\xdc';
	char mat[21][21];

	for (int i = 1; i <= 20; i++)
	{
		// Calcula os valores
		investido[i] = investido[i - 1] + aporte_anual; // adiciona ao vetor de índice i o elemento anterior + o aporte
		rendimento[i] = rendimento_anual * (acumulado[i - 1] + aporte_anual);
		acumulado[i] = acumulado[i - 1] + aporte_anual + rendimento[i]; // acumulado do ano anterior mais o aporte anual e o rendimento obtido 
	}
	for (int i = 0; i <= 20; i++)
	{
		normalizado[i] = int(ceil((acumulado[i] / acumulado[20]) * 21)); // normalização do vetor
	}

	for (int i = 0; i <= 20; i++)
	{
		// Exibe os valores
		alinhamento_left_int(i, white, cyan, 5); cout << " ";
		alinhamento_left_float(investido[i], white, black, 13); // total do investimento acrescido do aporte anual
		alinhamento_right_float(rendimento[i], white, black, 14); // rendimento do ano i
		alinhamento_right_float(acumulado[i], white, black, 13); cout << "   "; // valor acumulado do ano i

		for (int j = 21; j >= 0; j--)
		{
			if (i >= (21 - normalizado[j-1]))
			{
				cout << right; cout << quadrado << " ";
			}
			else {
				cout << " ";
			}
		}

		cout << endl;
	}

	gerar_linhas(linha, 80, cyan, black);

		// Deleta cada vetor dinâmico criado
		for (int i = 0; i < num_empresas; i++)
		{
			delete[] vetor_empresa;
		}
	
		return 0;
	}
