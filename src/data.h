#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include "record.h"

using namespace std;

class Data{

    private:
        vector<double> feature;
        vector<Record> data;
        Record params;
        int N,n,size;

    public:
        Data();                     //empty constructor
        ~Data();                    //destructor
        Record getRecord(int);      //returns a record at given index in the vector
        vector<Record> getData();   //returns a vector containing all the records
        void readInput(int N, int n);           //a method to read input from file

        //returns total number of records in data
        int getSize(){
            return size;
        }

        int getRecordSize(){
            return N;
        }

        int getFeatureSize(){
            return N-n;
        }
};

#endif
