#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

int doSomething(int* x, int* y); 


int main() {
    int num1 = 10;
    int num2 = 20;
    int num3 = doSomething(&num1,&num2);
    cout << num3 << endl;

}

int doSomething(int *x, int *y){

int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
return *x + *y;
}