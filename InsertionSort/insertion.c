#include <stdio.h>

void insert_sort(int arr[], int n) {
    int i, k, j;

    for (i = 1; i < n; i++) {
        k = arr[i]; // element to be inserted
        j = i - 1; // index of the last element of a sorted part

        // move elements that greater than k to the right
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

int main() {
   int start_arr[] = {2, 4, 1, 9, 30, 6};
   int n = sizeof(start_arr) / sizeof(start_arr[0]); // array's size

   insert_sort(start_arr, n);
   printf("sorted arrray: \n");

   // sorted array
   for (int i = 0; i < n; i++) {
      printf("%d ", start_arr[i]);
   }
   printf("\n");

   return 0;   
}