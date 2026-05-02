#include <iostream>
#include <chrono>
#include "Test-Inputs.h"
#include "Number-Generator.h"
#include "../src/Validate.h"

using namespace std;

// Each algorithm is run 10 times so the timing is less based on one run.
const int RUNS = 10;

// If a run gets too slow, the larger sizes for that same test are skipped.
const double SKIP_TIME_SECONDS = 60.0;

/* Finds the median time.
The median is the middle value after the run times are sorted. */
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

// Runs one sorting algorithm with one input type and one array size.
double runOneExperiment(const Algorithm& algorithm, const InputType& inputType, int n) {
    cout << algorithm.name << ": " << endl;
    cout << inputType.name << ", n = " << n << endl;

    int* originalArr = new int[n]; // One original array used for fair testing.
    double runTimes[RUNS];         // Stores the time for each run.
    bool valid = true;             // Tracks if every sorted array is correct.

    // commented out average time and replaced with median time
    // double totalTime = 0;  // add before loop

    // Creates the starting input, such as sorted, random, or reversed.
    inputType.generateFunction(n, originalArr);

    for(int i = 0; i < RUNS; i++){ /* This runs the same algorithm 10 times
    so we can use the median time instead of just one timing result. */

        int* arr = new int[n]; // Creates a fresh array for this run.

        // Copies the original values because sorting changes the array.
        copyArray(originalArr, arr, n);

        auto start = chrono::high_resolution_clock::now(); // Timer start.
        algorithm.sortFunction(arr, n);                    // Function call.
        auto end = chrono::high_resolution_clock::now();   // Timer end.

        chrono::duration<double> duration = end - start; // Finds elapsed time.

        // totalTime += duration.count();  // Old average calculation commented out.

        runTimes[i] = duration.count(); // Saves this run for the median.

        cout << "\nTime taken: " << duration.count() << " seconds\n"; // Prints time for a single run.

        // Checks that the algorithm actually sorted the array.
        if(!validationCheck(arr, n)){
            valid = false;
            cout << "Array is not sorted correctly!\n";
        }

        delete[] arr; // Clears up space.
    }

    double median = medianTime(runTimes, RUNS);

    // commented out average time and replaced with median time
    // cout << "\nAverage time: " << totalTime / RUNS << " seconds\n";

    cout << "\nMedian time: " << median << " seconds\n";

    if(algorithm.countFunction != 0){
        int* comparisonArr = new int[n];
        copyArray(originalArr, comparisonArr, n);

        long long comparisons = algorithm.countFunction(comparisonArr, n);

        cout << "Comparisons: " << comparisons << endl;

        if(comparisons > 0){
            cout << "Time / comparison: " << median / comparisons << " seconds\n";
        }

        delete[] comparisonArr;
    }
    else {
        cout << "Comparisons: not used because this is not a comparison-based sort\n";
    }

    delete[] originalArr;

    cout << "---------------------------------------------------\n";
    cout << endl;
    return median;
}

/* Runs several algorithms, input types, and array sizes.
If one test takes too long, the bigger sizes for that same test are skipped. */
void runExperimentSet(Algorithm algorithms[], int algorithmCount,
                      InputType inputTypes[], int inputTypeCount,
                      int sizes[], int sizeCount) {
    for(int inputIndex = 0; inputIndex < inputTypeCount; inputIndex++){
        for(int algorithmIndex = 0; algorithmIndex < algorithmCount; algorithmIndex++){
            bool skipLargerSizes = false;

            for(int sizeIndex = 0; sizeIndex < sizeCount; sizeIndex++){
                int n = sizes[sizeIndex];

                if(skipLargerSizes){
                    cout << inputTypes[inputIndex].name << ", n = " << n << ", "
                         << algorithms[algorithmIndex].name
                         << " skipped because the previous size took too long\n";
                    continue;
                }

                double median = runOneExperiment(algorithms[algorithmIndex],
                                                 inputTypes[inputIndex], n);

                // Skips bigger sizes after this if the current size was too slow.
                if(median > SKIP_TIME_SECONDS){
                    skipLargerSizes = true;
                }
            }

            cout << endl;
        }
    }
}

// Menu to select input type.
int chooseInputType() {
    int inputChoice;

    cout << "Choose input type:\n";
    cout << "1. Sorted\n";
    cout << "2. Random\n";
    cout << "3. Reversed\n";
    cout << "4. Half-sorted\n";
    cout << "\nEnter a number: ";
    cin >> inputChoice;

    return inputChoice;
}

// Turns the user's number choice into the correct input generator.
InputType getInputTypeFromChoice(int inputChoice) {
    switch(inputChoice){
        case 1:
            return {"sorted", sorted};
        case 2:
            return {"random", randomNumber};
        case 3:
            return {"reversed", reversedSort};
        case 4:
            return {"half-sorted", halfSorted};
        default:
            return {"random", randomNumber};
    }
}

/* Manual mode lets the user choose the array size and input type.
Then all sorting algorithms are tested with those choices. */
void runManualTest(Algorithm algorithms[], int algorithmCount) {
    int n;

    cout << "Enter size of array: " << endl;
    cin >> n;

    if(n <= 0){
        cout << "Invalid array size\n";
        return;
    }

    int inputChoice = chooseInputType();

    if(inputChoice < 1 || inputChoice > 4){
        cout << "Invalid input type\n";
        return;
    }

    InputType inputType = getInputTypeFromChoice(inputChoice);

    for(int i = 0; i < algorithmCount; i++){
        runOneExperiment(algorithms[i], inputType, n);
    }
}
