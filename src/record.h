#ifndef RECORD_H_
#define RECORD_H_

#include <vector>
#include <iostream>

using namespace std;

class Record{

    private:
        vector <int> featureVector;      //contains all integral values in a row
        vector <string> param;           //contains all headings of tables
        vector <string> stringVector;    //contains all string values in a row
        int N,n;

    public:
        Record();                   //empty constructor
        Record(string s, int n);    //default constructor
        Record(Record &rec);        //copy constructor
        ~Record();                  //destructor

        vector<int> getFeatureVector();     //a method to return the feature vector of a record

        //returns size of the record
        int getSize(){
            return N;
        }
        //returns size of the feature vector
        int getFeatureSize(){
            return N-n;
        }
        
};

#endif
