#include <iostream>
using namespace std;

bool validationCheck (int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(validationCheck(arr, n)){
        cout << "Array is sorted correctly\n";
    }
    else {
        cout << "Array is not sorted correctly\n";
    }


}
