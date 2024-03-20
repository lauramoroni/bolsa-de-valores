	char text_rentabilidade[5][30] = { " Ano  ", " Investido ", " Rendimento ", " Acumulado ", " Gráfico " };

	alinhamento_left(text_rentabilidade[0], white, cyan, 5);
	alinhamento_left(text_rentabilidade[1], white, cyan, 12);
	alinhamento_left(text_rentabilidade[2], white, cyan, 12);
	alinhamento_left(text_rentabilidade[3], white, cyan, 12);

	float investido[21] = { total_investido };
	float acumulado[21] = { total_investido };
	float rendimento[21] = { 0 };

	cout << "\n";

	float normalizado[21];
	char quadrado[] = { "\xdc" };

	for (int i = 1; i <= 20; i++)
	{
		// Calcula os valores
		// Adiciona ao vetor de índice i o elemento anterior + o aporte
		investido[i] = investido[i - 1] + aporte_anual;
		rendimento[i] = rendimento_anual * (acumulado[i - 1] + aporte_anual);
		acumulado[i] = acumulado[i - 1] + aporte_anual + rendimento[i]; // acumulado do ano anterior mais o aporte anual e o rendimento obtido 
	}

	

	for (int i = 0; i <= 20; i++)
	{
		normalizado[i] = (acumulado[i] / acumulado[21]) * 21;

		// Exibe os valoreas
		alinhamento_left_int(i, white, cyan, 5); cout << " ";
		alinhamento_left_float(investido[i], white, black, 20); cout << "\t\t"; // total do investimento acrescido do aporte anual
		alinhamento_left_float(rendimento[i], white, black, 15); cout << "\t\t";
		alinhamento_left_float(acumulado[i], white, black, 15); cout << "\t\t";
		gerar_linhas(linha, normalizado[i], blue, black);
	}

	cout << "\n";
	gerar_linhas(linha, 80, cyan, black);
