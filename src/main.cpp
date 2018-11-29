#include <iostream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
using namespace std;


int main(void){
    Data a;
    vector<double> l(2);
    vector<double> m(2);
    l = {0,0,0};
    m = {6,8,10};
    a.readInput(17,0);
    // cout << DistanceMatrix::euclideanDistance(l,m) << endl;
    cout << l << endl;
    l[0] = 100;
    cout << l << endl;

    // DistanceMatrix b;
    // cout << b.averageRecord(a);
    return 0;
}