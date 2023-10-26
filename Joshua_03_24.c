/*
Roll no:03
Batch:A
Author Name:Joshua Bara
Date:2/10/23
Description:Program to implement Quick Sort 
*/
#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array into two subarrays, elements less than the pivot
// and elements greater than or equal to the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);    // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place the pivot element in its correct position
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two subarrays
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1); // Call quickSort to sort the array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
