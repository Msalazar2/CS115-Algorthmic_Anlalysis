#include "Algorithms.h"
#include <iostream>
#include <utility>

using namespace std;

// SELECTION SORT

void SelectionSort(int* numbers, int size) {
    for (int i = 0; i < size - 1; i++) {
        int indexSmallest = i;

        for (int j = i; j < size; j++) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }

        int temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}

// INSERTION SORT

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// BUBBLE SORT

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// QUICK SORT

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void QuickSortMain(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

// MERGE SORT

void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast - leftFirst + 1;
    int* mergedNumbers = new int[mergedSize];

    int mergePos = 0;
    int leftPos = leftFirst;
    int rightPos = leftLast + 1;

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

    while (leftPos <= leftLast) {
        mergedNumbers[mergePos] = numbers[leftPos];
        leftPos++;
        mergePos++;
    }

    while (rightPos <= rightLast) {
        mergedNumbers[mergePos] = numbers[rightPos];
        rightPos++;
        mergePos++;
    }

    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
        numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    delete[] mergedNumbers;
}

void MergeSort(int* numbers, int leftFirst, int rightLast) {
    if (leftFirst < rightLast) {
        int mid = (leftFirst + rightLast) / 2;

        MergeSort(numbers, leftFirst, mid);
        MergeSort(numbers, mid + 1, rightLast);
        Merge(numbers, leftFirst, mid, rightLast);
    }
}

void MergeSortMain(int arr[], int n) {
    if (n > 0) {
        MergeSort(arr, 0, n - 1);
    }
}


// HEAP SORT

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}


// COUNTING SORT

void CountingSort(int arr[], int n) {
    if (n == 0) {
        return;
    }

    int max_key = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_key) {
            max_key = arr[i];
        }
    }

    int* count = new int[max_key + 1]();
    int* output = new int[n];

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max_key; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}


// RADIX SORT

int getDigit(int value, int pos) {
    for (int i = 0; i < pos; i++) {
        value /= 10;
    }
    return value % 10;
}

void CountingSortByDigit(int arr[], int n, int pos) {
    int* count = new int[10]();
    int* output = new int[n];

    for (int i = 0; i < n; i++) {
        int digit = getDigit(arr[i], pos);
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], pos);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}


// RADIX SORT

void RadixSort(int arr[], int n) {
    if (n == 0) {
        return;
    }

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int digits = 0;
    do {
        digits++;
        max_val /= 10;
    } while (max_val > 0);

    for (int pos = 0; pos < digits; pos++) {
        CountingSortByDigit(arr, n, pos);
    }
}