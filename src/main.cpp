#include <iostream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
using namespace std;


int main(void){
    Data a;
    // vector<double> l(2);
    // vector<double> m(10);
    // l = {0,0,0};
    // m = {6,8,10,4,5,6,7,8,9,1};
    a.readInput(17,0);
    DistanceMatrix b;
    cout << a.getRecord(0).getFeatureVector() << endl;;
    b.sortRecords(a);
    cout << a.getRecord(0).getFeatureVector() << endl;
    // cout << DistanceMatrix::normalize(m) << endl;
    // cout << l << endl;
    // l[0] = 100;
    // cout << l << endl;

    // DistanceMatrix b;
    // cout << b.averageRecord(a);
    return 0;
}