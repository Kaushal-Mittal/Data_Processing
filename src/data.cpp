#include "data.h"
#include "record.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "string"
#include "vector"

using namespace std;

    Data::Data(){}

    Data::~Data(){}

    void Data::readInput(int N, int n){
        ifstream dataFile("../data/AirQualityUCI_mod_2.csv");
        string line;
        string temp;
        while(getline(dataFile,line)){
            Record somerecord(line, N, n);
            data.push_back(somerecord);
        }
    }