#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0;
	std::cout << "arr size: ";
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	int total_water = 0;
	bool keep_checking = false;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			if (i == 0) break;

			std::cout << "i value:" << i << "j value: " << j << endl;
			std::cout << "i arr value " << arr[i] << " j arr value: " << arr[j] << endl;

			if (arr[j] < arr[i]) keep_checking = true;


			if (arr[j] >= arr[i] && keep_checking) {
				std::cout << "entered" << endl;
				std::cout << " arreglo i num: " << arr[i] << "arreglo j num: " << arr[j] << endl;

				for (int z = i + 1; z < j; z++) {
					std::cout << "entered sum";
					int maximum_water_between = min(arr[i], arr[j]);
					total_water += maximum_water_between - arr[z];
					std::cout << "maximum water (min):" << maximum_water_between << " arreglo en z:" << arr[z] << endl;
					std::cout << "total_water in sum:" << total_water << endl;
				}

				i = j-1;
				break;

			}

			if (arr[j] >= arr[i] && !keep_checking) break;

		std::cout << endl << endl;
		}

		keep_checking = false;
	}

	std::cout << total_water;

	return 0;
}
