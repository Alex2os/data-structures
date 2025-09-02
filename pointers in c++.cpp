#include <iostream>

using namespace std; // this is just to not have to put std::cout or std::cin in the program. this imports everything it needs for every command that needs std::. this, however, doesn't cause the program itself to use more memory, but it does in the compile-time

int main() {
	int var1 = 0, var2 = 0;
	// initially, a pointer declared like int *ip; will point to trash, as it's not initialized and we don't know where it's pointing to
	
	int* zapato = NULL; // null equals "zero". it's used to specify that there's nothing in the variable itself, but counts as a variable at the same time, just that we don't have anything there.
	int* zapato2 = nullptr; // nullptr is the value of an empty pointer. this is another way to initialize an empty pointer, but this should be better to initialize pointers.
	var1 = 5;

	// zapato = &var1; // if we do this, then we will print the direction of the memory of var1.
	// cout << zapato; // if we do this, then we will just print the memory value in hexadecimal value.
	// cout << *zapato; // if we now do this, then now we will print the value that the zapato variable is pointing to, not the direction in memory
	
	cout << zapato << endl; // this prints zeros, as there is nothing in the zapato variable
	cout << zapato2 << endl; // this prints zero (or zeros)

	// *zapato = *zapato * 5; // this turns to be an error, because we have a nullptr multiplied by 5, which is not possible and the program doesn't work.
	// we can do the following to print 25 in the screen, using the pointer value and etc.

	zapato = &var1; // when assigning a memory direction, we don't have to put the * in the variable, as it will not allow us to assign it.
	*zapato = *zapato * 5;  // we can now do this to convert the value of the pointer (which would be 5, as it points to var1) and use to turn it to 25
	cout << *zapato; // finally, we can print the value that now we have, and, in this case, we will print 25.

	int arr[1]; // arrays are pointers.
	cout << arr; // if we do this, this will print the point in memory where the array starts.
	return 0;
}
