#include <iostream>
#include <iomanip>
#include <memory>
#include <algorithm>
using namespace std;


void sortArray(double [], int );
double avgScore(double[], int);
void displayResults(double, double[], int);

int main() {
    int numTestScores = 0;
    cout << "Enter number of test scores: ";
    cin >> numTestScores;

    double* dynamicArray = new double[numTestScores];

    for (int i = 0; i < numTestScores; i++){
        cout << "Enter score for test #" << i +1 << ": ";
        cin >> dynamicArray[i];
    }
    

    sortArray(dynamicArray, numTestScores);
    double avg = avgScore(dynamicArray, numTestScores);
    displayResults(avg, dynamicArray, numTestScores);
    delete [] dynamicArray;

}

void displayResults(double avg, double dynamicArray[], int numTestScores){
    
    for (int i = 0; i < numTestScores; i++){
        cout << "Score #" << i+1 << ": " << dynamicArray[i] << endl;
    }
    cout << "Average Score: " << avg << endl;
}

void sortArray(double dynamicArray[], int numTestScores){
    sort(dynamicArray, dynamicArray + numTestScores);
}

double avgScore(double dynamicArray[], int numTestScores){
    double sum = 0;
    for (int i = 0; i  < numTestScores; i++){
        sum += dynamicArray[i];
    }
    return sum/numTestScores;
}