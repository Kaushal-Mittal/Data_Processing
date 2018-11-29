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
    // vector<double> vec;
    for(int i =0;i<size;i++){
        for(int j =0;j<n;j++){
            arr[j] = arr[j] + (dataObj.getRecord(i).getFeatureVector()[j])/size;
        }
    }
    vector<double> a(arr,arr + sizeof(arr)/sizeof(arr[0]));
    // cout << "yoloy" << a << "yolo" << endl; 
    return a;
}

void DistanceMatrix::populateMatrix(){
        cout << "shit !!" << endl;
}

std::ostream& operator<<(std::ostream& os, DistanceMatrix& mat) {
    os << "LOLOLOL";
    os << "\n";
}

