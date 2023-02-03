#include <stdio.h>
#include <locale.h>
#define tvetor 5

void p_v(int v[], int tam);
void m_v(int v[], int tam);
void o_v(int v[], int tam, int tipo);

int main() {
	setlocale(LC_ALL, "Portuguese_Brazil");
	int idades[tvetor];
	
	printf("Informe as idades: \n\n");
	p_v(idades, tvetor);
	o_v(idades, tvetor, -1);
	m_v(idades, tvetor);
	
	return 0;
}

void p_v(int v[], int tam) {
	for(int i = 0; i < tam; i++) {
		printf("Informe o %dº valor: ", i+1);
		scanf("%d", &v[i]);
	}
}

void m_v(int v[], int tam) {
	for(int i = 0; i < tam; i++) {
		printf("%d ", v[i]);
	}
}

void o_v(int v[], int tam, int tipo) {
	int aux, valor;
	
	for(int i = 0; i < tam; i++) {
		valor = i;
		
		for(int j = (i+1); j < tam; j++) {
			if(tipo == -1) {
				if(v[j] > v[valor]) {
					valor = j;
				}
			} else {
				if(v[j] < v[valor]) {
					valor = j;
				}
			}
		}
		
		if(i != valor) {
			aux = v[valor];
			v[valor] = v[i];
			v[i] = aux;
		}
	}
}
