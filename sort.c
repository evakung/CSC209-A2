#include <stdio.h>

#define N 10

void print_array(int [], int);
void print_array1(const char a[], int size);
void bubbleSort(int [], int);
void reverse(int [], int);

int main(void){

	int array[N] = {13, 12, 10, 3, 5, 10, 1, 5, 20, 14};
	const char array1[N+1] = {".", ".", ".", ".", ".", ".", ".", ".", ".", ".","\0"};

	printf("Initial Array: ");
	print_array(array, N);

	/* Reverse array */
	reverse(array, N);
	printf("Reversed Array: ");
	print_array(array, N);
	

	/* Sort array using Bubble Sort */
	bubbleSort(array, N);
	printf("Sorted Array: ");
	print_array(array, N);

	printf("test ");
	print_array(array1, N+1);

	return 0;
}

/* prints the elements of an array */
void print_array(int a[], int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}

void print_array1(char a[], int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}

/* Sort an array using Bubble Sort */
void bubbleSort(int numbers[], int array_size){

	int i, j, temp;

	for (i = (array_size - 1); i > 0; i--){
		for (j = 1; j <= i; j++){
			if (numbers[j-1] > numbers[j]){
				temp = numbers[j-1];
				numbers[j-1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

/* Reverses the order of elements in an array */
void reverse(int list[], int size){
	int low, high, temp;
	for (low = 0, high = size - 1; low < high; low++, high--){
		temp = list[low];
		list[low] = list[high];
		list[high] = temp;
	}
	
	return;
}
