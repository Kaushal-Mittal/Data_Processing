#include <iostream>
#include <fstream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
using namespace std;

bool distanceComparator(Record &r1,Record& r2){
    double a1,a2;
    a1 = r1.getDistance();
    a2 = r2.getDistance();
    cout << r1 << " " << r2 << "lol\n";
    return a1 < a2;
}

int main(void){
    Data a;
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