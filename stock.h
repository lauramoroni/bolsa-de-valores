#pragma once
#include "date.h"

struct transacao {
	date data;
	int quantidade;
	float preco;
};
struct empresa {
	char nome[20];
	char codigo[10];
	int num_transacoes;
	transacao* transacoes;
};


float resumo_da_carteira(empresa[], int);