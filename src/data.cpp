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

    void Data::readInput(int NN, int nn){
        n = nn;
        N = NN;
        ifstream dataFile("../data/AirQualityUCI_mod_2.csv");
        string line;
        string temp;
        // getline(dataFile,line);
        // istringstream ss(line);
        getline(dataFile,line);
        Record some(line);
        params = some;
        int counter = 0;
        while(getline(dataFile,line)){
            Record somerecord(line, NN, nn);
            data.push_back(somerecord);
            counter++;
        }
        size = counter;
    }

    vector<double> Data::get_column(int i){
        vector<double> v;
        for(size_t j = 0; j < size; j++){   
            v.push_back(data[j].getFeatureVector()[i]);
        }
        return v;
    }