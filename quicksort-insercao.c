#include "insercao.h"
#include "particiona.h"


/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort com inserção e devolve v       */

int *quicksort_insercao(int v[], int a, int b, unsigned int m) {
	
	if ((b - a + 1) <= m)
		return insercao(v, a, b); 
	
	unsigned int n = particiona(v, a, b, v[b]);

	quicksort_insercao(v, a, n - 1, m);
	quicksort_insercao(v, n + 1, b, m);
}