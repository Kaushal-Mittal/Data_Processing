#include <iostream>
#include <vector>
#include "record.h"
#include <sstream>

// #include <boost/algorithm/string.hpp>

using namespace std;

Record::Record(){}

Record::Record(string s, int N, int n){
    
    vector<string> temp;
    vector<int> temp2;
    string s_temp;
    int count = 0;    
    istringstream ss(s);

    while(getline(ss, s_temp,',')){
        if(count < n) stringVector.push_back(s_temp);
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

// Record::Record(Record &rec){

// }

Record::~Record(){

}

vector<double> Record::getFeatureVector(){
    return featureVector;
}