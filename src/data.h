#ifndef DATA_H_
#define DATA_H_

#include <vector>

using namespace std;
class Data{

    private:
        vector<int> feature;
    public:
        Data();
        ~Data();
        void readInput();   
}

#endif
