#include <iostream>

using namespace std;

void BubbleSort(int arr[], int tam) {

	for (int i = 0; i < tam - 1 ; i++) {

		bool hayCambio = false;

		for (int j = 0; j < tam - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				hayCambio = true;
			}
		}

		if (!hayCambio) break;
	}

}

void ImprimirArreglo(int arr[], int tam) { for (int i = 0; i < tam; i++) cout << arr[i] << " "; }

int main() {

	int arreglo[10] = {2, 11 ,4 ,5 ,9 ,10, 76, 8, 4, 29};

	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	BubbleSort(arreglo, tam);

	ImprimirArreglo(arreglo, tam);

	return 0;
}