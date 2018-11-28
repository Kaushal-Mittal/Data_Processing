#ifndef DISTANCEMATRIX_H_
#define DISTANCEMATRIX_H_

#include <vector>
#include "matrix.h"

using namespace std;
class DistanceMatrix : public Matrix{

    private:
        vector<int> feature;
    public:
        DistanceMatrix();
        ~DistanceMatrix();

};

#endif
