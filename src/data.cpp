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
                stringstream streamer(line);
                for(int q=0;q<y;q++){
                    char n;
                    char sta;
                    streamer >> n;
                    if(n == 'o'){
                        sta = '0';
                    }
                    if(n == '+'){
                        if(q == y-1 || q == 0 || p == x-1 || p ==0){
                            throw 10;
                        } else{
                        sta = '1';
                        }
                    }
                    gameOfLife->setCell(p,q,sta);
                }
    }