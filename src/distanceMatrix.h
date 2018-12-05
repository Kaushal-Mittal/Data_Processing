#ifndef DISTANCEMATRIX_H_
#define DISTANCEMATRIX_H_

#include <vector>
#include "matrix.h"
#include "record.h"
#include "data.h"

using namespace std;
class DistanceMatrix{

    private:
        vector<double> averageFeature;
        vector<vector<double>> matrix;
        
    public:
        DistanceMatrix();
        ~DistanceMatrix();
        void populateMatrix(Data&);
        static double euclideanDistance(vector<double>,vector<double>);
        static vector<double> normalize(vector<double>);
        vector<double> averageRecord(Data);
        void computeDistances(Data&);
        static bool distanceComparator(const Record &,const Record&);
        void sortRecords(Data&);
        friend std::ostream& operator<< (std::ostream &, DistanceMatrix &);


};

#endif
