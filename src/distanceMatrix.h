#ifndef DISTANCEMATRIX_H_
#define DISTANCEMATRIX_H_

#include <vector>
#include "matrix.h"
#include "record.h"
#include "data.h"

using namespace std;
class DistanceMatrix : public Matrix{

    private:
        vector<int> feature;
        vector<vector<double>> matrix;
        
    public:
        DistanceMatrix();
        ~DistanceMatrix();
        vector<double> averageRecord(Data);


};

#endif
