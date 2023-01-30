#include "MyFunctions.h"
#include <stdio.h>

int main1()
{   
	int MatriceNxN[ordineMAX][ordineMAX];
	int ordine = 0; // ordine dellla matrice
	int D = 0;

	do
	{
		printf("ordine della matrice ");
		scanf("%d", &ordine);
		if (ordine > ordineMAX)
			printf("ordine deva essere minore di %d\n", ordineMAX);
	} while (ordine > ordineMAX);

	// inilizazione matrice NxN
	InitMatrice(MatriceNxN, ordineMAX);

	//richiesta dei valori dei coeficienti
	printf("inserisci valori degli elmenti\n\n");

	//inserimento valori matrice M
	for (int j = 0; j < ordine; j++)
		for (int i = 0; i < ordine; i++)
		{
			printf("metti il coeficiente %d,%d: ", j + 1, i + 1);
			scanf("%d", &MatriceNxN[j][i]);
		}
	D = CalcolaDet(MatriceNxN, ordine);
	printf("Determinante = %d\n\n", D);


	return 0;

}

