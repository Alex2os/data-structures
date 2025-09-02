// this is another way to make the reference parameters in c++/c, instead of just using the & in the function.

#include <iostream>

using namespace std;

void intercambio(int *, int*);

int main() {
	int a = 1, b = 2;
	cout << "a = " << a << " " << "b = " << b << endl;
	intercambio(&a, &b);
	cout << "a = " << a << " " << "b = " << b << endl;
	return 0;
}

void intercambio(int *x, int *y) {
	int temp =0;
	temp = *x;
	*x = *y;
	*y = temp;
}
