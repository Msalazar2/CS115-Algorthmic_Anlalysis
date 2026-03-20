#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
using namespace std;

/* selectionSort function, sorts a given array by 
comparing the assumed min value with the element 
next in the array, until it finds the actual min
value. The function iterates throughout the entire
array until completely sorted. */
void selectionSort(int arr[], int n) {

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

bool validationCheck (int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

    // printArray function, prints the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){

    srand(time(0));

    int n;
        cout << "Enter size of array: " << endl;
        cin >> n;

        if (n <= 0) {
            cout << "Invalid array size\n";
            return 0;
        }

        int* arr = new int[n];
    
    cout << endl;

    int choice;

    cout << "Enter a number: \n";
    cout << "(1) Random Numbers\n";
    cout << "(2) Reversed Numbers\n";
    cout << "(3) Sorted\n";
    cout << "(4) Half-sorted\n";
    cin >> choice;
    
    switch (choice){
        case 1: {

            for(int i = 0; i < n; i++){
                arr[i] = rand() % 100;
            }

            break;
        }

        case 2: {

            for(int i = 0; i < n; i++){
                arr[i] = n - i;
            }

            break;
        }
            

        case 3: {
            for(int i = 0; i < n; i++){
                arr[i] = i + 1;
            }

            break;
        }
        

        case 4: {
            for(int i = 0; i < n / 2; i++){
                arr[i] = i + 1;
            }

            for(int i = n / 2; i < n; i++){
                arr[i] = rand() % 100;
            }

            break;
        }

        default: 
            cout << "Invalid choice\n";
            delete[] arr;
            return 0;
        }
    
    //cout << "\nOriginal array:\n";
    //printArray(arr, n);

    auto start = chrono::high_resolution_clock::now();

    selectionSort(arr, n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    //cout << "\nSorted array:\n";
    //printArray(arr, n);

    cout << "\nTime taken: " << duration.count() << " seconds\n";
    
    
    cout << endl;
    if(validationCheck(arr, n)){
        cout << "Array is sorted correctly!\n";
    }
    else {
        cout << "Array is not sorted correctly!\n";
    }

    delete[] arr;
    return 0;
}
