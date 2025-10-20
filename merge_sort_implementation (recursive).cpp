vector<int> MergeSort(vector<int> arr, int n) {

	if (n == 1) return arr;

	vector<int> temp_arr = arr;
	int slice = n / 2;

	vector<int> sliced_array1;
	vector<int> sliced_array2;

		for (int j = 0; j < n; j++) {

			if (j < slice) {;
				sliced_array1.push_back(temp_arr[j]);
			}
			else{
				sliced_array2.push_back(temp_arr[j]);
			}
		}

		sliced_array1 = MergeSort(sliced_array1, sliced_array1.size());
		sliced_array2 = MergeSort(sliced_array2, sliced_array2.size());

		int sliced1_index = 0;
		int sliced2_index = 0;

		bool arr1_finished = false;
		bool arr2_finished = false;

		for (int i = 0; i < n; i++) {
			if (arr1_finished){
				temp_arr[i] = sliced_array2[sliced2_index];
				sliced2_index++;
			}

			else if (arr2_finished){
				temp_arr[i] = sliced_array1[sliced1_index];
				sliced1_index++;
			}

			else if (sliced_array1[sliced1_index] < sliced_array2[sliced2_index]) {
				temp_arr[i] = sliced_array1[sliced1_index];
				sliced1_index++;
				if (sliced1_index == sliced_array1.size()) arr1_finished = true;
			}
			else{
				temp_arr[i] = sliced_array2[sliced2_index];
				sliced2_index++;
				if (sliced2_index == sliced_array2.size()) arr2_finished = true;
			}
		}

	return temp_arr;
}
