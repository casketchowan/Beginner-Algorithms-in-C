//algoattempt1.c
/*This program is meant to combine these three kind of algorithms: 
1. linear search
2. binary search
3. bubble sort
*/

#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void bubbleSort(int arr[], int size);

int main() {
    printf("Welcome to my attempt at an algorithm program. \n");
    printf("Make yourself comfortable and create your array: \n");

    int myElements = 0;
    printf("How many elements? \n");
    scanf("%d", &myElements);

    // Dynamically allocate memory for the array
    int *myArray = (int *)malloc(myElements * sizeof(int));
    if (myArray == NULL) {
        printf("Memory allocation failed! Run program again \n");
        return 1; // Exit if memory allocation fails
    }

    printf("Please enter ints for each element: \n");
    for (int i = 0; i < myElements; i++) {
        scanf("%d", &myArray[i]);
    }

    printf("Your int in element 0 is: %d\n", myArray[0]); //it works! :^)
    //both of these vars decalred below are used for input validation in loops
    int flag = 0;
    int search = 0;

    while (flag == 0) {
    printf("Seems like that worked! Choose an algorithm: \n");
    printf("1. Linear Search 2. Binary Search 3. Bubble Sort \n");
    int algoChoice = 0;
    int result = 0;
    scanf("%d",&algoChoice);
    switch (algoChoice) {
    case 1:
	while (search == 0) {
	int exc; //temp variable for search validation
	printf("Now choose an int to search for: \n");
	scanf("%d", &exc);
	if (exc == 0) {break;}
	search = exc;
    }
	result = linearSearch(myArray, myElements, search);
	printf("Your search has been found at index: %d\n", result);
	flag = 1;
	break;
    case 2:
	while (search == 0) {
	int exc = 0; //temp variable for search validation
	printf("Now choose an int to search for: \n");
	scanf("%d", &exc);
	if (exc == 0) {break;}
	search = exc;
    }
	result = binarySearch(myArray, myElements, search);
	printf("Your search has been found at index: %d\n", result);
	flag = 1;
	break;
    case 3:
	bubbleSort(myArray, myElements);
	printf("Your sorted array: \n");
	for (int i = 0; i < myElements;  i++) {
		printf("%d\n", myArray[i]);
    }
	flag = 1;
	break;
    default:
	printf("Error! Choose an int greater than 0 or less than 4 \n");
    }
    }
    printf("Thank you for using my algorithm program. Goodbye! \n");
    // Free the allocated memory
    free(myArray);

    return 0;
    }

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
	if (arr[i] == target) {
	     return i; //element found
    }
    }
    return -1; //element not found
    }

int binarySearch(int arr[], int size, int target) {
    int leftPtr = 0, rightPtr = size -1;
    while (leftPtr <= rightPtr) {
	int mid = leftPtr + (rightPtr - leftPtr) / 2;
	if (arr[mid] == target) {return mid;} //element found
	if (arr[mid] < target) {leftPtr = mid + 1;} else {rightPtr = mid - 1;}
    }
    return -1; //element not found
    }

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
	for (int j = 0; j < size - i - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			//swap arr[j] and arr[j + 1]
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
    }
    }
    }
    }
