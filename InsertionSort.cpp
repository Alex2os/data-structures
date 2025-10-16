#include <iostream>

using namespace std;


void InsertionSort(int arr[], int tam) {

	for (int i = 1; i < tam; i++) {

		int elemento_actual = arr[i];

		int j = i - 1;

		while (j >= 0 && arr[j] > elemento_actual) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = elemento_actual;

	}
}


void ImprimirArreglo(int arr[], int tam) { for (int i = 0; i < tam; i++) cout << arr[i] << " "; }

int main() {

	int arreglo[10] = {2, 11 ,4 ,5 ,9 ,10, 76, 8, 4, 29};

	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	InsertionSort(arreglo, tam);

	ImprimirArreglo(arreglo, tam);

	return 0;
}