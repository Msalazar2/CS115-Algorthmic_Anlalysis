#ifndef TEST_INPUTS_H
#define TEST_INPUTS_H

/* Holds the information needed to run one sorting algorithm.
The function pointer is what lets the test code call the algorithm. */
struct Algorithm {
    const char* name;
    void (*sortFunction)(int[], int);
    long long (*countFunction)(int[], int);
    bool isSlow;
};

/* Holds the name of an input type and the function that creates it.
For example, this can point to sorted, random, or reversed input. */
struct InputType {
    const char* name;
    void (*generateFunction)(int, int[]);
};

double medianTime(double times[], int size);
double runOneExperiment(const Algorithm& algorithm, const InputType& inputType, int n);
void runExperimentSet(Algorithm algorithms[], int algorithmCount,
                      InputType inputTypes[], int inputTypeCount,
                      int sizes[], int sizeCount);
int chooseInputType();
InputType getInputTypeFromChoice(int inputChoice);
void runManualTest(Algorithm algorithms[], int algorithmCount);

#endif
