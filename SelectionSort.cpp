#include <iostream>

using namespace std;

void SelectionSort(int arr[], int tam) {

	// el hecho de poner el tam - 1 y el i + 1 prevee una iteración extra al final del arreglo.
	for (int i = 0; i < tam - 1; i++) {

		int indice_minimo = i;

		for (int j = i + 1; j < tam; j++) if (arr[j] < arr[indice_minimo]) indice_minimo = j;

		if (indice_minimo != i) {
			int temp = arr[i];
			arr[i] = arr[indice_minimo];
			arr[indice_minimo] = temp;
		}
	}
}


void ImprimirArreglo(int arr[], int tam) { for (int i = 0; i < tam; i++) cout << arr[i] << " "; }

int main() {

	int arreglo[10] = {2, 11 ,4 ,5 ,9 ,10, 76, 8, 4, 29};

	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	SelectionSort(arreglo, tam);

	ImprimirArreglo(arreglo, tam);

	return 0;
}