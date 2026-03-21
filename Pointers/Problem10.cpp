#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int* newArray(int*, int);

int main(){
    int size = 0;
    cout << "Enter size of array: ";
    cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++){
        cout << "Enter value for index " << i << ": ";
        cin >> *(array + i);
    }

    for (int i = 0; i < size; i++){
        cout << *(array + i) << endl;
    }
    
    int* reversedArray = newArray(array, size);
    for (int i = 0; i < size; i++){
        cout << *(reversedArray + i) << endl;
    }
    
    delete [] array;
    delete [] reversedArray;


}

int* newArray(int* array, int size){
    int* arrayCopy = new int[size];
    for (int i = 0; i < size; i++){
        *(arrayCopy + i) = *(array + (size - i - 1));
    }
    return arrayCopy;
}