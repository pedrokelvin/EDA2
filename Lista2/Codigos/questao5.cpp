#include <bits/stdc++.h>
using namespace std;

// sorts a small group with insertion sort
// group has 5 itens or less
void sort_group(vector<int>& numbers, int i, int group_size) {

	for (int j = i + 1; j < i + group_size; j++) {
		int k = j;
		while ((k > i) && (numbers[k] < numbers[k-1])) {
			int aux = numbers[k-1];
			numbers[k-1] = numbers[k];
			numbers[k] = aux;
			k--;
		}
	}
}

// breaks numbers into groups of five itens
// last group may be not complete
void divide_groups(vector<int>& numbers, int size) {

	int i = 0;

	/*  if size = 14
	 *  two groups of 5 itens
	 *  last group has 4 itens
	 */

	for (i = 0; i <= (size - 5); i = i + 5) {
		sort_group(numbers, i, 5);
	}

	int last_size = size % 5; // last group size

	if (last_size > 0) {
		sort_group(numbers, i, last_size);
	}
	else {
		// do nothing, there is no incomplete group
	}

}


// copy median of each group to a second array
// caution with last group
void medians_copy(vector<int>& source, int source_size,vector<int>& destiny, int destiny_size) {

	int number_of_complete_groups = source_size / 5;
    int i = 0;

	// copy medians of complete groups
	for (i = 0; i < number_of_complete_groups; i++) {
		destiny[i] = source[i * 5 + 2];
	}

	// from now on, deals with last group

	int last_group_size = source_size % 5;

	if (last_group_size > 0) {

	    // last group first position
	    int first_position = i * 5;

		int last_median = 0;

		// defines position of last median accordingly to group size
		// extract its value
		switch (last_group_size) {
			case 1:
			case 2:
				last_median = source[first_position];
				break;
			case 3:
			case 4:
				last_median = source[first_position + 1];
				break;
			//case 5:
				//last_median = source[first_position + 2];
				//break;
			default: // last group is not bigger than 4 itens
				//assert(FALSE);
				break;
		}

		// copy last median to second array
		destiny[destiny_size - 1] = last_median;
	}
	else {
		// do nothing, has only complete groups
	}
}

// copies left or right partition to a new array
vector<int>  partition_copy(vector<int> &source, int start, int end) {

	int destiny_size = (end + 1) - start;
	vector<int> destiny(destiny_size);

	for (int i = start; i <= end; i++) {
		destiny[i - start] = source[i];
	}

	return destiny;
}

// simple swap of two numbers of array
void swap(	vector<int> & input, int first_index, int second_index) {
	int aux = input[first_index];
	input[first_index] = input[second_index];
	input[second_index] = aux;
}

// finds first occurence of value
int find_index(vector<int>& input, int size, int value) {

	int value_index = -1;

	for (int i = 0; i < size; i++) {
		if (input[i] == value) {
			value_index = i;
			break;
		}
	}

	return value_index;
}

// smallers numbers to the left, bigger numbers to the right
// [small numbers][mom][bigger numbers]
// has problems with very small input, 1 or 2 itens
void partition_numbers_around_mom (vector<int>& input_numbers,
                                   int input_numbers_size,
								   int median_of_medians) {

    // short-circuit, fix me!
	if (input_numbers_size == 2) {
		if (input_numbers[0] > input_numbers[1]) {
			swap(input_numbers, 0, 1);
		}
		return;
	}
	else if (input_numbers_size == 1) {
		return;
	}

	int mom_index = find_index(input_numbers, input_numbers_size, median_of_medians);
	swap(input_numbers, 0, mom_index);

	int i = 1;
	int j = input_numbers_size - 1;

	while (i < j) {

		// finds a greater in the left side
		while (input_numbers[i] < median_of_medians) {
			i++;
		}

		// finds a smaller in the right side
		while (input_numbers[j] > median_of_medians) {
			j--;
		}

		swap(input_numbers, i, j);
	}

	// both numbers on the middle are inverted
	// mom is at index 0
	swap(input_numbers, 0, i-1);
	swap(input_numbers, 0, i);

}

// oracle implements Median of Medians algorithm
int ask_oracle_for_median(vector<int> &input_numbers, int input_numbers_size) {

	divide_groups(input_numbers, input_numbers_size);

	int last_medians_size = input_numbers_size / 5;

	if ((input_numbers_size % 5) > 0) {
		last_medians_size = last_medians_size + 1;
	}
	else {
		// do nothing
	}

    vector<int> last_medians(last_medians_size);

	medians_copy(input_numbers, input_numbers_size, last_medians, last_medians_size);

	while (last_medians_size > 1) {


		divide_groups(last_medians, last_medians_size);


		int current_medians_size = 0;

		if ((last_medians_size % 5) > 0) {
			current_medians_size = (last_medians_size / 5) + 1;
		}
		else {
			current_medians_size = last_medians_size / 5;
		}

	    vector<int> current_medians (current_medians_size);

		medians_copy(last_medians, last_medians_size, current_medians, current_medians_size);

		//free(last_medians);

		last_medians = current_medians;
		last_medians_size = current_medians_size;
	}

	return last_medians[0]; // this is the Median of Medians
}

int exoteric_select (vector<int>&input_numbers, int input_numbers_size, int k_esimo) {


	int mom = ask_oracle_for_median(input_numbers, input_numbers_size);

	partition_numbers_around_mom(input_numbers, input_numbers_size, mom);
	int mom_index = find_index(input_numbers, input_numbers_size, mom);

	int expected_size = k_esimo;
	int median = -1;

	if (mom_index > expected_size) {

		// oracle guessed too high

		int left_size = mom_index;

		vector<int> left_partition = partition_copy(input_numbers, 0, left_size - 1);

		median = exoteric_select(left_partition, left_size, k_esimo);
	}
	else if (mom_index < expected_size) {

		// oracle guessed too low


		int right_size = (input_numbers_size - 1) - mom_index;
		int partition_start = mom_index + 1;

		vector<int> right_partition = partition_copy(input_numbers, partition_start, input_numbers_size - 1);

		k_esimo = k_esimo - (mom_index + 1);
		median = exoteric_select(right_partition, (input_numbers_size - 1) - mom_index, k_esimo);
	}
	else {

		// oracle is correct!

		median = mom;
	}

	return median;
}

void quickSort(vector<int>& A, int lo = 0, int hi = -1)
{
	if(hi == -1) 
		hi = A.size();
	if(lo < hi)
	{
		vector<int> AA = A;
	    vector<int> aux = partition_copy(AA, 0, AA.size() - 1);
		sort_group(aux, 0, AA.size()); // sort_group also works with large groups
		int k_esimo = (AA.size() - 1) / 2; // median is at middle
		int median = exoteric_select(AA, AA.size(), k_esimo);
		int i = lo;

		for(int j = lo + 1; j < hi; j++)
			if(A[j] <= A[lo])//A[lo] = pivot
			{
				i++;
				swap(A[i], A[j]);
			}
		swap(A[i], A[lo]);
		quickSort(A, lo, i);  
		quickSort(A, i+1, hi);
	}
}

int main(){

    vector<int> v = {2,5,9,19,24,54,5,87,9,10,44,32,18,13,2,4,23,26,16,19,25,39,47,56,71};
    quickSort(v);

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
