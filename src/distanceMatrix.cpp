#include "distanceMatrix.h"
#include "record.h"
#include "data.h"
#include "vector"

//empty constructor
DistanceMatrix::DistanceMatrix(){}

//destructor
DistanceMatrix::~DistanceMatrix(){}

//method to calculate average of all the feature vectors in the data object
vector<double> DistanceMatrix::averageRecord(Data dataObj){
    int n = dataObj.getFeatureSize();
    int size = dataObj.getSize();
    double arr[n] = {};
    for(int i =0;i<size;i++){
        for(int j =0;j<n;j++){
            arr[j] = arr[j] + dataObj.getRecord(i).getFeatureVector()[j];
        }
    }
    vector<double> a(arr,arr+n);
    return a;
}