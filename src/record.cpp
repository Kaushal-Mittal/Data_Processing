#include <iostream>
#include <vector>
#include "record.h"
#include <sstream>
#include "utilities.h"

// #include <boost/algorithm/string.hpp>

using namespace std;

Record::Record(){}

Record::Record(string s, int NN, int nn){
    N = NN;
    n = nn;
    string s_temp;
    int count = 0;    
    istringstream ss(s);

    while(getline(ss, s_temp,',')){
        if(count < nn) stringVector.push_back(s_temp);
        else featureVector.push_back(stod(s_temp));
        count++;
    }
}

Record::Record(string s){
    istringstream ss(s);
    string temp;
    while(getline(ss, temp,',')){
        param.push_back(temp);        
    }
}

Record::Record(const Record &rec){
    featureVector = rec.featureVector;
    N = rec.N;
    n = rec.n;
    stringVector = rec.stringVector;
    param = rec.param;
    distance = rec.distance;
}

Record::~Record(){

}

vector<double> Record::getFeatureVector(){
    return featureVector;
}

std::ostream& operator<<(std::ostream& os, Record& rc) {
    cout << rc.getFeatureVector();
}
