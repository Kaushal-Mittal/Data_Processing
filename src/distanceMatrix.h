#ifndef DISTANCEMATRIX_H_
#define DISTANCEMATRIX_H_

#include <vector>
#include "matrix.h"
#include "record.h"
#include "data.h"

using namespace std;
class DistanceMatrix{

    private:
        vector<int> feature;
        vector<vector<double>> matrix;
        
    public:
        DistanceMatrix();
        ~DistanceMatrix();
        void populateMatrix();
        vector<double> averageRecord(Data);
        friend std::ostream& operator<< (std::ostream &, DistanceMatrix &);


};

#endif
