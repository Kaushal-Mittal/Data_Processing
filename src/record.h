#ifndef RECORD_H_
#define RECORD_H_

#include <vector>
#include <iostream>

using namespace std;

class Record{
    private:
        vector <int> feature;
        vector <string> param;
    public:
        Record();
        Record(string s, int n);
        Record(Record &rec);
        ~Record();
        
};

#endif
