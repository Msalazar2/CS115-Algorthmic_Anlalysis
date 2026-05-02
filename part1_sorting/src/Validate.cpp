#include "Validate.h"
#include <iostream>
using namespace std;

/*Checks the sorted array by making sure the following number
is greater than the previous number, therefore sorted from 
least to greatest correctly.
*/
bool validationCheck (int arr[], int n) {

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
