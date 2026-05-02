#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Algorithms.h"
#include "../tests/Number-Generator.h"
#include "../tests/Test-Inputs.h"

using namespace std;

int main() {
    srand(1); // Fixed seed makes random input reproducible across runs.

    // Sizes for the fast algorithms and full experiment.
    int allSizes[] = {1000, 10000, 25000, 50000, 75000, 100000};

    // Smaller size list for slower O(n^2) algorithms.
    int slowSizes[] = {1000, 10000, 25000};

    // Main experiment input types.
    InputType mainInputTypes[] = {
        {"sorted", sorted},
        {"random", randomNumber},
        {"reversed", reversedSort}
    };

    // All algorithms used by manual mode and full experiment.
    Algorithm allAlgorithms[] = {
        {"Selection Sort", SelectionSort, SelectionSortCount, true},
        {"Insertion Sort", InsertionSort, InsertionSortCount, true},
        {"Bubble Sort", BubbleSort, BubbleSortCount, true},
        {"Quick Sort", QuickSortMain, QuickSortCountMain, false},
        {"Merge Sort", MergeSortMain, MergeSortCountMain, false},
        {"Heap Sort", HeapSort, HeapSortCount, false},
        {"Counting Sort", CountingSort, 0, false},
        {"Radix Sort", RadixSort, 0, false}
    };

    // Algorithms that are practical for larger input sizes.
    Algorithm fastAlgorithms[] = {
        {"Quick Sort", QuickSortMain, QuickSortCountMain, false},
        {"Merge Sort", MergeSortMain, MergeSortCountMain, false},
        {"Heap Sort", HeapSort, HeapSortCount, false},
        {"Counting Sort", CountingSort, 0, false},
        {"Radix Sort", RadixSort, 0, false}
    };

    // Slower O(n^2) algorithms are kept to smaller input sizes.
    Algorithm slowAlgorithms[] = {
        {"Selection Sort", SelectionSort, SelectionSortCount, true},
        {"Insertion Sort", InsertionSort, InsertionSortCount, true},
        {"Bubble Sort", BubbleSort, BubbleSortCount, true}
    };

    int choice;

    // Main menu for choosing how much of the experiment to run.
    cout << "Menu:\n";
    cout << "\n1. Manual test\n";
    cout << "2. Fast algorithms only\n";
    cout << "3. Slow algorithms only\n";
    cout << "4. Full experiment\n";
    cout << "\nEnter a number: ";
    cin >> choice;

    switch(choice){
        case 1:
            runManualTest(allAlgorithms, 8);
            break;

        case 2:
            runExperimentSet(fastAlgorithms, 5, mainInputTypes, 3, allSizes, 6);
            break;

        case 3:
            runExperimentSet(slowAlgorithms, 3, mainInputTypes, 3, slowSizes, 3);
            break;

        case 4: {
            char confirm;

            cout << "Warning: full experiment may take a long time.\n";
            cout << "Continue? (y/n): ";
            cin >> confirm;

            if(confirm == 'y' || confirm == 'Y'){
                runExperimentSet(allAlgorithms, 8, mainInputTypes, 3, allSizes, 6);
            }
            else {
                cout << "Full experiment cancelled.\n";
            }
            break;
        }

        default:
            cout << "Invalid choice\n";
            return 0;
    }

    return 0;
}
