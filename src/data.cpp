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

    void Data::readInput(){
        ifstream dataFile("../data/AirQualityUCI_mod_2.csv");
        string line;
        string temp;
        // getline(dataFile,line);
        // istringstream ss(line);
        while(getline(dataFile,line)){
            Record somerecord(line);
            data.push_back(somerecord);
        }
    }