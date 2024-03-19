#include <iostream>
#include "stock.h"
#include "color.h"
#include "text.h"
using namespace std;

float resumo_da_carteira(empresa vetor_empresa[], int tam) {

    float total_investido = 0;

    // For para cada empresa
    for (int i = 0; i < tam; i++) {
        // Vetores para armazenar os valores calculados para cada empresa
        float preco_total, preco_medio;
        int qtd = 0, qtd_total = 0;

        float investido = 0;

        // For para cada transação da empresa
        for (int j = 0; j < vetor_empresa[i].num_transacoes; j++) {
            

            // Adiciona à quantidade de ações da transação atual o total de ações da empresa
            qtd = vetor_empresa[i].transacoes[j].quantidade;
            preco_total = qtd * vetor_empresa[i].transacoes[j].preco;
            investido += preco_total;
            qtd_total += qtd;
        }

        cout.width(15); cout << left;
        cout << vetor_empresa[i].nome;

        // Calcula o preço médio ponderado
        preco_medio = investido / qtd_total;

        alinhamento_right(vetor_empresa[i].codigo, white, black, 8);
        alinhamento_right_int(qtd_total, white, black, 12);
        // limita a quantidade de casa decimal
        cout << fixed; cout.precision(2);
        alinhamento_right_float(preco_medio, white, black, 18);
        alinhamento_right_float(investido, white, black, 17);
        cout << "\n";

        total_investido += investido;
    }

    return total_investido;
}
