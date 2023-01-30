#include "MyFunctions.h"
#include <stdio.h>

int Matrice2x2(int a11, int a12, int a21, int a22);
void EstraiMin(int IN_Matrice[][ordineMAX], int IN_ordine, int IN_colonna, int OUT_Minore[][ordineMAX]);


void InitMatrice(int IO_Matrice[][ordineMAX], int IN_ordine) {
	// inizializza la matrice 
	for (int h = 0; h < IN_ordine; h++)
		for (int k = 0; k < IN_ordine; k++)
			IO_Matrice[h][k] = 0;
}

float CalcolaDet(int Matrice[][ordineMAX], int ordine) {

	int Minore[ordineMAX][ordineMAX];
	float DetMin = 0;
	float Determinante = 0;

	InitMatrice(Minore, ordineMAX);

	if (ordine == 2)
		Determinante = Determinante + Matrice2x2(Matrice[0][0], Matrice[0][1], Matrice[1][0], Matrice[1][1]);
	else
		for (int colonna = 0; colonna < ordine; colonna++) {
			EstraiMin(Matrice, ordine, colonna, Minore);
			DetMin = CalcolaDet(Minore, ordine - 1);
			Determinante = Determinante + Segno(colonna) * Matrice[0][colonna] * DetMin;
		}
	return Determinante;

}

void EstraiMin(int IN_Matrice[][ordineMAX], int IN_ordine, int IN_colonna, int OUT_Minore[][ordineMAX]) {

	InitMatrice(OUT_Minore, ordineMAX);
	for (int rm = 1; rm < IN_ordine; rm++)
	{
		int cm = 0;
		int cp = 0;
		do {
			if (cm == IN_colonna)
				cm++;
			else {
				OUT_Minore[rm - 1][cp] = IN_Matrice[rm][cm];
				cm++;
				cp++;
			}
		} while (cm < IN_ordine);

	}
}
int Matrice2x2(int a11, int a12, int a21, int a22) {

	return ((a11 * a22) - (a12 * a21));
}
int Segno(int numero) {

	if (numero % 2 == 0)
		return 1;
	else
		return -1;
}

void InitVettore(int IO_Vettore[ordineMAX], int IN_ordine) {

	for (int r = 0; r < IN_ordine; r++) 
		IO_Vettore[r] = 0;
}