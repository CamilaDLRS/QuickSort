#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* busca a posição onde X deve ser posicionado em v[a..b], sendo v um vetor ordenado.*/

static int busca(int x, int v[], int a, int b) {
	if (a > b)
		return a - 1;
	if (compara(x, v[b]) >= 0)
		return b;

	return busca(x, v, a, b - 1);
}

/* -------------------------------------------------------------------------- */
/* 	Sendo v[a..b-1] um vetor ordenado, insere o último elemento (v[b]) onde deve ser 
posicionado para que v continue ordenado.*/

static int *insere(int v[], unsigned int a, unsigned int b) {

	int p = busca(v[b], v, a, b - 1);

	for (unsigned int i = b; i > (p + 1); --i)
		troca(v, i, i - 1);

	return v;
}

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo método da inserção e devolve v */

int *insercao(int v[], unsigned int a, unsigned int b) {

	if (a >= b)
		return v;

	insercao(v, a, b - 1);
	insere(v, a, b);

  	return v;
}