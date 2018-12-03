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
    // vector<double> l(2);
    // vector<double> m(10);
    // l = {0,0,0};
    // m = {6,8,10,4,5,6,7,8,9,1};
    ofstream outputFile("output.txt");
    a.readInput(17,0);
    // cout << "lol";
    // cout << a.getRecord(0).getFeatureVector();
    DistanceMatrix b;
    // cout << a.getRecord(0).getFeatureVector() << endl;;
    // b.sortRecords(a);
    // sort(a.getData().begin(),a.getData().end(),distanceComparator);
    b.populateMatrix(a);
    // cout << b;
    // cout << "lol";
    outputFile << b;
    outputFile.close(); 
    // cout << DistanceMatrix::normalize(m) << endl;
    // cout << l << endl;
    // l[0] = 100;
    // cout << l << endl;

    // DistanceMatrix b;
    // cout << b.averageRecord(a);
    return 0;
}