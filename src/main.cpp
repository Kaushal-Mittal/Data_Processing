#include <iostream>
#include <fstream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
#include "task4.h"
using namespace std;

int main(void){
    Data a;
    ofstream outputFile("output.txt");
    a.readInput(17,0);
    
    task4 t4;
    t4.generate_covariance_matrix(a);

    ofstream outputFile("out.txt");
    a.readInput(17,0);
    DistanceMatrix b;
    b.computeDistances(a);
    cout << a.getRecord(0).getFeatureVector() << endl;
    b.sortRecords(a);
    cout << a.getRecord(0).getFeatureVector() << endl;
    b.populateMatrix(a);
    outputFile << b;
    outputFile.close(); 
    return 0;
}