#include <iostream>
#include <vector>

#include "matrix.h"
#include "data.h"
#include "record.h"

#ifndef TASK_4_
#define TASK_4_

using namespace std;

class task4{
    private:
        
    public:
        task4();
        ~task4();

        vector<vector<double> > generate_covariance_matrix(Data dataobj);
        // void generate_covariance_matrix(Data dataobj);
        double generate_covariance(vector<double> v1, vector<double> v2);

};

#endif