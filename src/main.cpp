#include "iostream"
#include "data.h"
#include "record.h"

// using namespace std;

int main(void){
    Data a;
    a.readInput(17,0);
    cout << a.getRecord(0).getFeatureVector()[4] << endl;
    // cout << a << endl;
    return 0;
}