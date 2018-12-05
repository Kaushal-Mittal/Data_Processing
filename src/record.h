#ifndef RECORD_H_
#define RECORD_H_

#include <vector>
#include <iostream>

using namespace std;

class Record{
    private:
        vector <double> featureVector;      //contains all integral values in a row
        vector <string> param;           //contains all headings of tables
        vector <string> stringVector;    //contains all string values in a row
        int N,n;
        double distance;

    public:
        Record(); //empty constructor
        Record(string s);                       
        Record(string s, int N, int n);  //constructor1
        Record(const Record &rec);        //copy constructor
        ~Record();                  //destructor

        vector<double> getFeatureVector();     //a method to return the feature vector of a record

        //returns size of the record
        int getSize(){
            return N;
        }
        //returns size of the feature vector
        int getFeatureSize(){
            return N-n;
        }

        void setDistance(double d){
            distance = d;
        }

        double getDistance() const{
            return distance;
        }

        friend std::ostream& operator<< (std::ostream &, Record &);
        
};

#endif
