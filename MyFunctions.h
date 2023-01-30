#define ordineMAX 8 // ordine massimo della matrice

extern void InitMatrice(int Matrice[][ordineMAX], int ordine);
extern float CalcolaDet(int Matrice[][ordineMAX], int ordine);
extern int Segno(int numero);
extern void InitVettore(int Vettore[ordineMAX], int ordine);