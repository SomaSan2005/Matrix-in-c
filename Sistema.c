#include "MyFunctions.h"
#include <stdio.h>


int main() {
	int MatriceCoef[ordineMAX][ordineMAX];
	int TerminiNoti[ordineMAX];
	float Soluzione[ordineMAX];
	int ordine = 0;
	float Det = 0; //determinante matrice dei coefficienti
	float DetSol = 0; //determinante matrice dei coefficienti in cui la colonna dei termini noti sostituisce i coefficienti dell'incognita. 
	int MatriceCopia[ordineMAX][ordineMAX];

	// inserimento coerfficienti del sistema

	do
	{
		printf("ordine della matrice ");
		scanf("%d", &ordine);
		if (ordine > ordineMAX)
			printf("ordine deva essere minore di %d\n", ordineMAX);
	} while (ordine > ordineMAX);

	InitMatrice(MatriceCoef, ordineMAX);
	InitVettore(TerminiNoti, ordineMAX);
	InitVettore(Soluzione, ordineMAX);

	//richiesta dei valori dei coeficienti
	printf("inserisci valori degli elmenti\n\n");

	//inserimento valori matrice M
	for (int j = 0; j < ordine; j++)
		for (int i = 0; i < ordine; i++)
		{
			printf("metti il coeficiente %d,%d: ", j + 1, i + 1);
			scanf("%d", &MatriceCoef[j][i]);
		}

	//richiesta dei valori dei termini noti 
	printf("inserisci valori dei termini noti \n\n");

	for (int i = 0; i < ordine; i++)
	{
		printf("metti il termine noto %d: ", i + 1);
		scanf("%d", &TerminiNoti[i]);
	}

	Det = CalcolaDet(MatriceCoef, ordine);
	if (Det == 0)
		printf("\nsoluzioni indeterminate\n");
	else
	{
		//calcolo cordinate soluzione (x,y,z...)
		for (int s = 0; s < ordine; s++) {

			//copia matrice coeficienti 
			for (int r = 0; r < ordineMAX; r++)
				for (int c = 0; c < ordineMAX; c++)
					MatriceCopia[r][c] = MatriceCoef[r][c];

			//Sostituzione del vettore dei termini noti  nella collonna [soluzione] della matrice dei coefficienti
			for (int r = 0; r < ordine; r++)
				MatriceCopia[r][s] = TerminiNoti[r];
			DetSol = CalcolaDet(MatriceCopia, ordine);
			Soluzione[s] = (DetSol / Det);
		}

		printf("soluzione sistema\n");
		for (int s = 0; s < ordine; s++)
			printf("%0.3f; ", Soluzione[s]);
	}

	return 0;
}