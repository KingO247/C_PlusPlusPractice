#include <iostream>
using namespace std;


/*13. Movie Statistics
Write a program that can be used to gather statistical data about the number of mov-
ies college students see in a month. The program should perform the following steps:
A) Ask the user how many students were surveyed. An array of integers with this
many elements should then be dynamically allocated.

B) Allow the user to enter the number of movies each student saw into the array.

C) Calculate and display the average, median, and mode of the values entered. 
*/

double avg(int, int);
double median();
double mode ();

int main(){
//A:
    int numSurveyed = 0;
    cout << "Enter the number of students surveyed: ";
    cin >> numSurveyed;
    while (numSurveyed < 0){
        cout << "Enter positive number: ";
        cin >> numSurveyed;
    }

    int *numMovies = new int[numSurveyed]; //dynamically allocated array
    int total = 0;

//B:
    for (int i = 0; i < numSurveyed; i++){
        cout << "Enter movies seen by student #" << i + 1 << ": ";
        cin >> *(numMovies + i); //pointer arithmetic via dereferencing a pointer
        while (*(numMovies + i) < 0){
            cout << "Enter positive value for student #" << i + 1 << ": ";
            cin >> *(numMovies + i);
        }
        total += *(numMovies + i);
    }

    cout << total << endl;
//C:
    double average = avg(total, numSurveyed);
    cout << "Average number of movies seen is " << average << endl;
    delete [] numMovies;

}
double avg(int total, int numSurveyed){
    double avg = 0;
    return avg = static_cast<double>(total)/numSurveyed;
}


