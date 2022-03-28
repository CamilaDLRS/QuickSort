#include "particiona.h"
#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */

static int mediana(unsigned int a, unsigned int b, unsigned int c) {
	
	if (compara(a, b) >= 0) {
		if (compara(a, c) <= 0)
			return a;
		if (compara(b, c) >= 0)
			return b;
		return c;
	}
	if (compara(a, c) >= 0)
		return a;

	if (compara(b, c) >= 0)
			return c;
	return b;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b) {
	
	if (a >= b)
		return v;
	
	unsigned int n1 = sorteia(a, b), n2 = sorteia(a, b), n3 = sorteia(a, b);

	int pivo = mediana(v[n1], v[n2], v[n3]);

	if (v[n3] == pivo)
		troca(v, b, n3);
	else if (v[n2] == pivo)
		troca(v, b, n2);
	else
		troca(v, b, n1);

	unsigned int m = particiona(v, a, b, pivo);

	quicksort_mediana(v, a, m - 1);
	quicksort_mediana(v, m + 1, b);
}



