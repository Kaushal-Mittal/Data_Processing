#include "distanceMatrix.h"
#include "record.h"
#include "data.h"
#include "vector"
#include "math.h"

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

double DistanceMatrix::euclideanDistance(vector<double>v1,vector<double>v2){
    if(v1.size() == v2.size()){
        double len = v1.size();
        double sum = 0.0;
        for(int i=0;i<len;i++){
            sum = sum + pow((v1[i]-v2[i]),2);
        }
        return pow(sum,0.5);
    }
}

vector<double> DistanceMatrix::normalize(vector<double> v1){
    int size = v1.size();
    vector<double> out(size);
    

}

void DistanceMatrix::populateMatrix(){
        cout << "shit !!" << endl;
}

std::ostream& operator<<(std::ostream& os, DistanceMatrix& mat) {
    os << "LOLOLOL";
    os << "\n";
}


