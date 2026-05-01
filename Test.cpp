#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <chrono>
#include "Algorithms.h"
#include "Number-Generator.h"
#include "Validate.h"

using namespace std;

/* Finds the median time from all runs.
The median is the middle value after the times are sorted. */
double medianTime(double times[], int size) {
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(times[j] > times[j + 1]){
                swap(times[j], times[j + 1]);
            }
        }
    }

    int middle = size / 2;

    if(size % 2 == 0){
        return (times[middle - 1] + times[middle]) / 2;
    }

    return times[middle];
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

            int* originalArr = new int[n]; // One fixed random array used for every algorithm.
            randomNumber(n, originalArr);

            cout << "Selection Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime = 0;  // add before loop


            double runTimes[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){ /*For loop calls the sorting algorithm 10 times
            , therefore allowing for several test runs in a single execution*/
            
            int* arr = new int[n]; // Creates new array
            
            copyArray(originalArr, arr, n); // Gives this run the same fixed random values.
            
            auto start = chrono::high_resolution_clock::now(); // Timer start
            SelectionSort(arr, n);  // Function call
            auto end = chrono::high_resolution_clock::now();  // Timer end
            
            chrono::duration<double> duration = end - start; /* Calculates time taken, 
            by subtracting end minus start */
            
            // totalTime += duration.count();  // Old average calculation commented out.

            
            runTimes[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n"; // Prints time for a single run
            
            if(!validationCheck(arr, n)){ // Checks for correctness, if not sorted properly it'll state so.
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr; // Clears up space
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes, 10) << " seconds\n"; // Prints median time of all ten runs

            /* For the rest of case 1 and cases 2, 3, and 4, this same template will be used to run each sorting
            algorithm 10 times. While printing important information such as time of each run and
            median time of all ten runs. Refer to selection sort run to better understand pieces of code throughout
            the rest of the cases and sorting algorithms. */

            cout << endl;

            cout << "Insertion Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime1 = 0;  // add before loop


            double runTimes1[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime1 += duration.count();  // Old average calculation commented out.

            
            runTimes1[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes1, 10) << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime2 = 0;  // add before loop


            double runTimes2[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime2 += duration.count();  // Old average calculation commented out.

            
            runTimes2[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes2, 10) << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime3 = 0;  // add before loop


            double runTimes3[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime3 += duration.count();  // Old average calculation commented out.

            
            runTimes3[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes3, 10) << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime4 = 0;  // add before loop


            double runTimes4[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime4 += duration.count();  // Old average calculation commented out.

            
            runTimes4[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes4, 10) << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime5 = 0;  // add before loop


            double runTimes5[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime5 += duration.count();  // Old average calculation commented out.

            
            runTimes5[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes5, 10) << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime6 = 0;  // add before loop


            double runTimes6[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime6 += duration.count();  // Old average calculation commented out.

            
            runTimes6[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes6, 10) << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime7 = 0;  // add before loop


            double runTimes7[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime7 += duration.count();  // Old average calculation commented out.

            
            runTimes7[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes7, 10) << " seconds\n";

            delete[] originalArr;

            break;
        }

        case 2: {

            int* originalArr = new int[n]; // One fixed reversed array used for every algorithm.
            reversedSort(n, originalArr);

            cout << "Selection Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime = 0;  // add before loop


            double runTimes[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime += duration.count();  // Old average calculation commented out.

            
            runTimes[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes, 10) << " seconds\n";

            cout << endl;

            cout << "Insertion Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime1 = 0;  // add before loop


            double runTimes1[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime1 += duration.count();  // Old average calculation commented out.

            
            runTimes1[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes1, 10) << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime2 = 0;  // add before loop


            double runTimes2[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime2 += duration.count();  // Old average calculation commented out.

            
            runTimes2[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes2, 10) << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime3 = 0;  // add before loop


            double runTimes3[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime3 += duration.count();  // Old average calculation commented out.

            
            runTimes3[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes3, 10) << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime4 = 0;  // add before loop


            double runTimes4[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime4 += duration.count();  // Old average calculation commented out.

            
            runTimes4[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes4, 10) << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime5 = 0;  // add before loop


            double runTimes5[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime5 += duration.count();  // Old average calculation commented out.

            
            runTimes5[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes5, 10) << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime6 = 0;  // add before loop


            double runTimes6[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime6 += duration.count();  // Old average calculation commented out.

            
            runTimes6[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes6, 10) << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime7 = 0;  // add before loop


            double runTimes7[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime7 += duration.count();  // Old average calculation commented out.

            
            runTimes7[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes7, 10) << " seconds\n";

            delete[] originalArr;

            break;
        }
            

        case 3: {

            int* originalArr = new int[n]; // One fixed sorted array used for every algorithm.
            sorted(n, originalArr);

            cout << "Selection Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime = 0;  // add before loop


            double runTimes[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime += duration.count();  // Old average calculation commented out.

            
            runTimes[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes, 10) << " seconds\n";

            cout << endl;

            cout << "Insertion Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime1 = 0;  // add before loop


            double runTimes1[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime1 += duration.count();  // Old average calculation commented out.

            
            runTimes1[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes1, 10) << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime2 = 0;  // add before loop


            double runTimes2[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime2 += duration.count();  // Old average calculation commented out.

            
            runTimes2[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes2, 10) << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime3 = 0;  // add before loop


            double runTimes3[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime3 += duration.count();  // Old average calculation commented out.

            
            runTimes3[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes3, 10) << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime4 = 0;  // add before loop


            double runTimes4[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime4 += duration.count();  // Old average calculation commented out.

            
            runTimes4[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes4, 10) << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime5 = 0;  // add before loop


            double runTimes5[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime5 += duration.count();  // Old average calculation commented out.

            
            runTimes5[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes5, 10) << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime6 = 0;  // add before loop


            double runTimes6[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime6 += duration.count();  // Old average calculation commented out.

            
            runTimes6[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes6, 10) << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime7 = 0;  // add before loop


            double runTimes7[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            copyArray(originalArr, arr, n);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime7 += duration.count();  // Old average calculation commented out.

            
            runTimes7[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes7, 10) << " seconds\n";

            delete[] originalArr;

            break;
        }
        

        case 4: {

            cout << "Selection Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime = 0;  // add before loop


            double runTimes[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime += duration.count();  // Old average calculation commented out.

            
            runTimes[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes, 10) << " seconds\n";

            cout << endl;

            cout << "Insertion Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime1 = 0;  // add before loop


            double runTimes1[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime1 += duration.count();  // Old average calculation commented out.

            
            runTimes1[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime1 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes1, 10) << " seconds\n";

            cout << endl;

            cout << "Bubble Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime2 = 0;  // add before loop


            double runTimes2[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime2 += duration.count();  // Old average calculation commented out.

            
            runTimes2[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime2 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes2, 10) << " seconds\n";

            cout << endl;

            cout << "Quick Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime3 = 0;  // add before loop


            double runTimes3[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            QuickSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime3 += duration.count();  // Old average calculation commented out.

            
            runTimes3[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime3 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes3, 10) << " seconds\n";

            cout << endl;

            cout << "Merge Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime4 = 0;  // add before loop


            double runTimes4[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            MergeSortMain(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime4 += duration.count();  // Old average calculation commented out.

            
            runTimes4[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime4 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes4, 10) << " seconds\n";

            cout << endl;

            cout << "Heap Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime5 = 0;  // add before loop


            double runTimes5[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            HeapSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime5 += duration.count();  // Old average calculation commented out.

            
            runTimes5[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime5 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes5, 10) << " seconds\n";

            cout << endl;

            cout << "Counting Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime6 = 0;  // add before loop


            double runTimes6[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            CountingSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime6 += duration.count();  // Old average calculation commented out.

            
            runTimes6[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime6 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes6, 10) << " seconds\n";

            cout << endl;

            cout << "Radix Sort: " << endl;

            // commented out average time and replaced with median time

            // double totalTime7 = 0;  // add before loop


            double runTimes7[10];  // Stores each run time so the median can be calculated.

            for(int i = 0; i < 10; i++){
            
            int* arr = new int[n];
            
            halfSorted(n, arr);
            
            auto start = chrono::high_resolution_clock::now();
            RadixSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            
            chrono::duration<double> duration = end - start;
            
            // totalTime7 += duration.count();  // Old average calculation commented out.

            
            runTimes7[i] = duration.count();  // Save this run for the median.
            
            cout << "\nTime taken: " << duration.count() << " seconds\n";
            
            if(!validationCheck(arr, n)){
                cout << "Array is not sorted correctly!\n";
            }
        
            delete[] arr;
            }

            // commented out average time and replaced with median time

            // cout << "\nAverage time: " << totalTime7 / 10 << " seconds\n";

            cout << "\nMedian time: " << medianTime(runTimes7, 10) << " seconds\n";

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
