#include <iostream>
#include <fstream>
#include "data.h"
#include "record.h"
// #include "distanceMatrix.h"
// #include "utilities.h"
#include "task4.h"
using namespace std;

int main(void){
    Data a;
    ofstream outputFile("output.txt");
    a.readInput(17,0);
    
    task4 t4;
    t4.generate_covariance_matrix(a);

    return 0;
}