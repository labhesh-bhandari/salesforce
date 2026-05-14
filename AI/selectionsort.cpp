#include<iostream>
#include<math.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        cout << "Pass " << i+1 << " : ";
        for(int k = 0; k < n; k++){ 
            cout << arr[k] << "  ";
        }
        cout << endl;
    } 
}