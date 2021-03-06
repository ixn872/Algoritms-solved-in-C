#include <iostream> 

using namespace std;

void quicksort(int arr[],int low,int high) {

	if (low < high){

		for (int j = low; j < high; j++) {
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j + 1]);
			    quicksort(arr, low, j + 1);
				
			}
		}

	}

}

void printArray(int arr[],int n){
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<",";
	}

}

int main() {

	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int low = 0;
	int high = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr, low, high);
	printArray(arr, high);
	return 0;

}
