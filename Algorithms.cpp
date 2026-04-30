#include "Algorithms.h"
#include <iostream>
#include <utility>

using namespace std;

/* Selection Sort:
   Finds the smallest value in the unsorted part of the array,
   then moves that value to the front. Each loop puts one more
   value into its final sorted position. */
void SelectionSort(int arr[], int n) {

    // Move the boundary between the sorted and unsorted parts.
    for(int i = 0; i < n-1; i++) {
        int min_Index = i;  // Start by assuming the first unsorted value is the smallest.

        // Look through the rest of the unsorted part for a smaller value.
        for (int j = i + 1; j < n; j++){

            // Save the index of the smallest value found so far.
            if (arr[j] < arr[min_Index]){
                min_Index = j;
            }
        }

        // Put the smallest unsorted value at the front of the unsorted part.
        swap(arr[i], arr[min_Index]);
    }

}

/* Insertion Sort:
   Builds a sorted section from left to right. Each new value is
   inserted into the correct spot among the values already sorted. */
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The value we want to place correctly.
        int j = i - 1;     // Start checking values just before the key.

        // Shift larger values one position to the right to make room for key.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key in the empty spot after all larger values were shifted.
        arr[j + 1] = key;
    }
}

/* Bubble Sort:
   Repeatedly compares neighboring values and swaps them if they
   are in the wrong order. Large values "bubble" toward the end. */
void BubbleSort(int arr[], int n) {
    bool swapped;

    // Each pass moves the largest remaining value to the end.
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Compare neighbors only in the unsorted part of the array.
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps happened, the array is already sorted.
        if (!swapped) {
            break;
        }
    }
}

/* partition:
   Helper for Quick Sort. It chooses one value as the pivot, then
   rearranges the array so smaller values are on the left and larger
   values are on the right. It returns the pivot's final index. */
int partition(int arr[], int low, int high) {
    // Pick a random pivot to reduce the chance of consistently bad splits.
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high]; // Store the pivot value at the end for now.
    int i = low - 1;       // i tracks the end of the "less than pivot" section.

    // Move values less than or equal to pivot into the left section.
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Put the pivot between the smaller and larger sections.
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

/* quickSort:
   Recursive Quick Sort helper. It partitions the current section,
   then sorts the left and right sections around the pivot. */
void quickSort(int arr[], int low, int high) {
    // Stop when the section has zero or one value, because it is already sorted.
    if (low < high) {
        int pi = partition(arr, low, high); // pi is the pivot's final position.

        // Sort values before and after the pivot.
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* QuickSortMain:
   Simple wrapper so the rest of the program can call Quick Sort with
   only the array and its size, instead of low and high indexes. */
void QuickSortMain(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

/* Merge:
   Helper for Merge Sort. It takes two sorted neighboring sections
   and combines them into one larger sorted section. */
void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast - leftFirst + 1; // Total number of values being merged.
    int* mergedNumbers = new int[mergedSize];  // Temporary array for the merged result.

    int mergePos = 0;           // Next open spot in mergedNumbers.
    int leftPos = leftFirst;    // Current value in the left section.
    int rightPos = leftLast + 1; // Current value in the right section.

    // Pick the smaller front value from either section until one section is empty.
    while (leftPos <= leftLast && rightPos <= rightLast) {
        if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            leftPos++;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            rightPos++;
        }
        mergePos++;
    }

    // Copy any leftover values from the left section.
    while (leftPos <= leftLast) {
        mergedNumbers[mergePos] = numbers[leftPos];
        leftPos++;
        mergePos++;
    }

    // Copy any leftover values from the right section.
    while (rightPos <= rightLast) {
        mergedNumbers[mergePos] = numbers[rightPos];
        rightPos++;
        mergePos++;
    }

    // Copy the merged sorted values back into the original array.
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
        numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    // Free the temporary array to avoid a memory leak.
    delete[] mergedNumbers;
}

/* MergeSort:
   Recursive Merge Sort helper. It splits the array section in half,
   sorts both halves, then merges the sorted halves together. */
void MergeSort(int* numbers, int leftFirst, int rightLast) {
    // Stop when the section has one value, because one value is already sorted.
    if (leftFirst < rightLast) {
        int mid = leftFirst + (rightLast - leftFirst) / 2;

        // Sort the left half, sort the right half, then combine them.
        MergeSort(numbers, leftFirst, mid);
        MergeSort(numbers, mid + 1, rightLast);
        Merge(numbers, leftFirst, mid, rightLast);
    }
}

/* MergeSortMain:
   Simple wrapper so the rest of the program can call Merge Sort with
   only the array and its size. */
void MergeSortMain(int arr[], int n) {
    if (n > 0) {
        MergeSort(arr, 0, n - 1);
    }
}


/* max_heapify:
   Helper for Heap Sort. It fixes one spot in a max heap so the parent
   value is larger than its children. A max heap keeps the biggest value
   at the root, which is index 0. */
void max_heapify(int arr[], int n, int i) {
    int largest = i;      // Assume the parent is the largest.
    int left = 2 * i + 1; // Index of the left child.
    int right = 2 * i + 2; // Index of the right child.

    // If the left child exists and is bigger, remember it.
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child exists and is bigger, remember it.
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If a child was bigger, swap and keep fixing the affected subtree.
    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

/* buildMaxHeap:
   Turns the array into a max heap, meaning every parent is greater
   than or equal to its children. */
void buildMaxHeap(int arr[], int n) {
    // Start at the last parent node and move backward to the root.
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

/* Heap Sort:
   Builds a max heap, then repeatedly moves the largest value to the
   end of the array and repairs the heap for the remaining values. */
void HeapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    // Move the current largest value to the end, one position at a time.
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        // The sorted end is ignored, so the heap size becomes i.
        max_heapify(arr, i, 0);
    }
}


/* Counting Sort:
   Counts how many times each value appears, then uses those counts
   to place every value into its sorted position. This version works
   for non-negative integers. */
void CountingSort(int arr[], int n) {
    if (n == 0) {
        return;
    }

    // Find the largest value so we know how big the count array must be.
    int max_key = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_key) {
            max_key = arr[i];
        }
    }

    int* count = new int[max_key + 1](); // count[value] stores how many times value appears.
    int* output = new int[n];            // Temporary array for sorted values.

    // Count each value from the original array.
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Turn counts into positions. After this, count[x] tells where x should end.
    for (int i = 1; i <= max_key; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted output array from right to left to keep equal values stable.
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted values back into the original array.
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the temporary arrays to avoid memory leaks.
    delete[] count;
    delete[] output;
}


/* getDigit:
   Returns one decimal digit from value. pos 0 means the ones digit,
   pos 1 means the tens digit, pos 2 means the hundreds digit, and so on. */
int getDigit(int value, int pos) {
    // Remove digits on the right until the wanted digit is in the ones place.
    for (int i = 0; i < pos; i++) {
        value /= 10;
    }

    // Return only the ones digit.
    return value % 10;
}

/* CountingSortByDigit:
   Helper for Radix Sort. It sorts the array by one digit position
   while keeping values with the same digit in their original order. */
void CountingSortByDigit(int arr[], int n, int pos) {
    int* count = new int[10](); // There are 10 possible decimal digits: 0 through 9.
    int* output = new int[n];   // Temporary array for values sorted by this digit.

    // Count how many values have each digit at this position.
    for (int i = 0; i < n; i++) {
        int digit = getDigit(arr[i], pos);
        count[digit]++;
    }

    // Turn digit counts into ending positions in the output array.
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output from right to left so the digit sort stays stable.
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], pos);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy values sorted by this digit back into the original array.
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free the temporary arrays to avoid memory leaks.
    delete[] count;
    delete[] output;
}

/* Radix Sort:
   Sorts non-negative integers one digit at a time, starting with the
   ones digit. It uses CountingSortByDigit for each digit position. */
void RadixSort(int arr[], int n) {
    if (n == 0) {
        return;
    }

    // Find the largest value so we know how many digit positions to sort.
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Count how many digits the largest value has.
    int digits = 0;
    do {
        digits++;
        max_val /= 10;
    } while (max_val > 0);

    // Sort by ones digit, then tens digit, then hundreds digit, etc.
    for (int pos = 0; pos < digits; pos++) {
        CountingSortByDigit(arr, n, pos);
    }

}
