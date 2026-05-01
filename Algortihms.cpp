#include "Algorithms.h"
#include <iostream>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

/* selectionSort function, sorts a given array by 
comparing the assumed min value with the element 
next in the array, until it finds the actual min
value. The function iterates throughout the entire
array until completely sorted. */
void SelectionSort(int arr[], int n) {

    /* For loop, which will iterate through all the elements
    at least once. */
    for(int i = 0; i < n-1; i++) {
        int min_Index = i;  // First pointer (assumed min)

        /* Second for loop, sets up the second pointer
        which is what going to be compared with the 
        first pointer. */
        for (int j = i + 1; j < n; j++){

            /* If the second element is smaller then 
            the actual min was found. */
            if (arr[j] < arr[min_Index]){
                min_Index = j;
            }
        }

        // Swaps the elements according to actual min.
        swap(arr[i], arr[min_Index]);
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

/*Checks the sorted array by making sure the following number
is greater than the previous number, therefore sorted from 
least to greatest correctly.
*/
bool validationCheck (int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

/* Generates random numbers, using the input size*/
void randomNumber(int n, int arr[]){
    for(int i = 0; i < n; i++){
                arr[i] = rand() % n;
            }
}

/* Generates reversed numbers, using the input size*/
void reversedSort(int n, int arr[]){

            for(int i = 0; i < n; i++){
                arr[i] = n - i;
            }
}

/* Generates sorted numbers, using the input size*/
void sorted(int n, int arr[]){

            for(int i = 0; i < n; i++){
                arr[i] = i + 1;
            }
}

/* Generates half-sorted numbers, using the input size*/
void halfSorted(int n, int arr[]){

        for(int i = 0; i < n / 2; i++){
            arr[i] = i + 1;
        }

        for(int i = n / 2; i < n; i++){
            arr[i] = rand() % n;
        }
}

int main(){

    srand(time(0)); // Sets time

    int n;
        cout << "Enter size of array: " << endl;
        cin >> n; // User chosen array size

        if (n <= 0) { // Validation for array size
            cout << "Invalid array size\n";
            return 0;
        }
    
    cout << endl;

    int choice; // Choice for number format

    cout << "Enter a number: \n";
    cout << "(1) Random Numbers\n";
    cout << "(2) Reversed Numbers\n";
    cout << "(3) Sorted\n";
    cout << "(4) Half-sorted\n";
    cin >> choice;
    
    switch (choice){ // Branches off to case according to number format.
        case 1: {

            cout << "Selection Sort: " << endl;

            double totalTime = 0;  // add before loop

            for(int i = 0; i < 10; i++){ /*For loop calls the sorting algorithm 10 times
            , therefore allowing for several test runs in a single execution*/
            
            int* arr = new int[n]; // Creates new array
            
            randomNumber(n, arr); // Fills array with desired format
            
            auto start = chrono::high_resolution_clock::now(); // Timer start
            SelectionSort(arr, n);  // Function call
            auto end = chrono::high_resolution_clock::now();  // Timer end
            
            chrono::duration<double> duration = end - start; /* Calculates time taken, 
            by subtracting end minus start */
            
            totalTime += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n"; // Prints time for a single run
            
            if(!validationCheck(arr, n)){ // Checks for correctness, if not sorted properly it'll state so.
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr; // Clears up space
            }

            cout << "\nAverage time: " << totalTime / 10 << " seconds\n"; // Prints average time of all ten runs

            /* For the rest of case 1 and cases 2, 3, and 4, this same template will be used to run each sorting
            algorithm 10 times. While printing important information such as time of each run and
            average time of all ten runs. Refer to selection sort run to better understand pieces of code throughout
            the rest of the cases and sorting algorithms. */

            cout << endl;

            cout << "Insertion Sort: " << endl;

            double totalTime1 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime1 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            double totalTime2 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime2 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            double totalTime3 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime3 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            double totalTime4 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime4 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            double totalTime5 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime5 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            double totalTime6 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime6 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            double totalTime7 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            randomNumber(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime7 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            break;
        }

        case 2: {

            cout << "Selection Sort: " << endl;

            double totalTime = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << endl;

            cout << "Insertion Sort: " << endl;

            double totalTime1 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime1 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            double totalTime2 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime2 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            double totalTime3 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime3 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            double totalTime4 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime4 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            double totalTime5 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime5 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            double totalTime6 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime6 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            double totalTime7 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            reversedSort(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime7 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            break;
        }
            

        case 3: {

            cout << "Selection Sort: " << endl;

            double totalTime = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << endl;

            cout << "Insertion Sort: " << endl;

            double totalTime1 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime1 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            double totalTime2 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime2 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            double totalTime3 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime3 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            double totalTime4 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime4 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            double totalTime5 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime5 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            double totalTime6 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime6 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            double totalTime7 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            sorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime7 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            break;
        }
        

        case 4: {

            cout << "Selection Sort: " << endl;

            double totalTime = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << endl;

            cout << "Insertion Sort: " << endl;

            double totalTime1 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime1 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            double totalTime2 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime2 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            double totalTime3 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime3 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            double totalTime4 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime4 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            double totalTime5 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime5 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            double totalTime6 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime6 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            double totalTime7 = 0;  // add before loop

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            totalTime7 += duration.count();  // accumulate
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            break;
        }

        default: 

            int* arr = new int[n];

            cout << "Invalid choice\n";
            delete[] arr;
            return 0;
        }

    return 0;

}
