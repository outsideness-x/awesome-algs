#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // temporary arrays
        // malloc - memory allocation
        int *L = (int *)malloc(n1 * sizeof(int));
        int *R = (int *)malloc(n2 * sizeof(int));

        // copying data to temporary arrays
        // n1/n2 - number of elements in the left/right array
        // mid - middle index of the array
        for (int i = 0; i < n1; i++)
                L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                        arr[k] = L[i];
                        i++;
                } else {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }

         while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        free(L);
        free(R);
}

// main function of MergeSort
void mergeSort(int arr[], int left, int right) {
        if (left < right) {
                int mid = left + (right - left) / 2;

                // sorting of first and second parts
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                // draining the sorted parts
                merge(arr, left, mid, right);
        }
}

// print-function
void printArr(int A[], int size) {
        for (int i = 0; i < size; i++) {
                printf("%d ", A[i]);
        }
        printf("\n");

}

// func. using
int main() {

        // sizeof(arr) - total size of the array in bytes
        // sizeof(arr[1]) - size of one element of array
        int arr[] = {20, 11, 12, 9, 19, 4, 1, 17};
        int arr_size = sizeof(arr) / sizeof(arr[0]);

        printf("array is: \n");
        printArr(arr, arr_size);

        mergeSort(arr, 0, arr_size - 1);

        printf("sorted array is: \n");
        printArr(arr, arr_size);

        return 0;
}

