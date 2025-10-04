#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	cout << "arr size:";
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			arr.erase(arr.begin() + i);
			arr.push_back(0);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
