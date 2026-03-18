#include <iostream>
using namespace std;

bool validationCheck (int Array[], int n){

    for(int i = 0; i < n - 1; i++){
        if(Array[i] > Array[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int Array[] = {1, 2, 3, 4, 5};
    int n = sizeof(Array) / sizeof(Array[0]);

    if(validationCheck(Array, n)){
        cout << "Array is sorted correctly\n";
    }
    else {
        cout << "Array is not sorted correctly\n";
    }


}