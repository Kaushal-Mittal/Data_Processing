#include "data.h"
#include "record.h"
#include <iostream>
#include <fstream>

using namespace std;

    Data::Data(){}

    Data::~Data(){}

    void Data::readInput(){
        ifstream dataFile("../data/AirQualityUCI.csv");
        string line;
        getline(dataFile,line);
    }