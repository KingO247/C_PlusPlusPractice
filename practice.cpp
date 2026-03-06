#include <iostream>
#include <iomanip>
using namespace std;

void showValues(int [], const int);

int main(){

const int SIZE = 5;
int numbers[SIZE] = { 1, 2, 3, 4, 5 };
showValues(numbers, SIZE);

}

void showValues(int values[], int size){
    for (int count = 0; count < size; count++){
        cout << values[count] << endl;
    }
}

