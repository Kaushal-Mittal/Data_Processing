#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include "record.h"
using namespace std;
class Data{

    private:
        vector<int> feature;
        vector<Record> data;
    public:
        Data();
        ~Data();
        Record getRecord(int);
        vector<Record> getData();   
        void readInput();   
};

#endif
