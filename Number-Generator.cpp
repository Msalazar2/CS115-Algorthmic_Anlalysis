#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include "Number-Generator.h"
using namespace std;

/* Generates random numbers, using the input size*/
void randomNumber(int n, int arr[]){
    for(int i = 0; i < n; i++){
                arr[i] = rand() % n;
            }
}

/* Generates reversed numbers, using the input size*/
void reversedSort(int n, int arr[]){

            for(int i = 0; i < n; i++){
                arr[i] = n - 1 - i;
            }
}

/* Generates sorted numbers, using the input size*/
void sorted(int n, int arr[]){

            for(int i = 0; i < n; i++){
                arr[i] = i;
            }
}

/* Generates half-sorted numbers, using the input size*/
void halfSorted(int n, int arr[]){

        for(int i = 0; i < n / 2; i++){
            arr[i] = i;
        }

        for(int i = n / 2; i < n; i++){
            arr[i] = rand() % n;
        }
}

/* Copies the original generated array into another array.
This lets each algorithm sort the same starting values. */
void copyArray(int originalArr[], int arr[], int n) {
    for(int i = 0; i < n; i++){
        arr[i] = originalArr[i];
    }
}

/*  commented out so Test.cpp can link
with these generator functions without having two main functions.
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
}
*/
