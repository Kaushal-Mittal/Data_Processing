#include <iostream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
using namespace std;


int main(void){
    Data a;
    vector<double> l(2);
    l = {2,3};
    a.readInput(17,0);
    DistanceMatrix b;
    cout << b.averageRecord(a);
    return 0;
}