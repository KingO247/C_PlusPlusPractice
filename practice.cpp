#include <iostream>
#include <iomanip>
#include <memory>
#include <algorithm>
using namespace std;


void sortArray(double*, int );
double avgScore(double*, int);
void displayResults(double, double*, int);

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

void displayResults(double avg, double* scores, int numTestScores){
    
    for (int i = 0; i < numTestScores; i++){
        cout << "Score #" << i+1 << ": " << *(scores + i) << endl;
    }
    cout << "Average Score: " << avg << endl;
}

void sortArray(double* scores, int numTestScores){
    sort(scores, scores + numTestScores);

}

double avgScore(double* scores, int numTestScores){
    double sum = 0;
    for (int i = 0; i  < numTestScores; i++){
        sum += *(scores + i);
}
return sum/numTestScores;
}