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
