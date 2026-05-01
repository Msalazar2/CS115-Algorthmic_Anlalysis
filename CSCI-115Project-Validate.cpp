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

/*  commented out so Test.cpp can link
with these functions without having two main functions
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(validationCheck(arr, n)){
        cout << "Array is sorted correctly\n";
    }
    else {
        cout << "Array is not sorted correctly\n";
    }


}*/
