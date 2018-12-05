#include "distanceMatrix.h"
#include "record.h"
#include "data.h"
#include "vector"
#include "math.h"
#include "utilities.h"
#include "algorithm"

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
    for(int i =0;i<size;i++){
        double dist = DistanceMatrix::euclideanDistance(dataObj.getRecord(i).getFeatureVector(),a);
        dataObj.getRecord(i).setDistance(dist);
    }
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
    double max,min;
    max = v1[0];
    min = v1[0];
    for(int i =0;i<size;i++){
        if(v1[i] > max){
            max = v1[i];
        }
        if(v1[i] < min){
            min = v1[i];
        }
    }
    for(int i =0;i<size;i++){
        out[i] = (v1[i]-min)/(max-min);
    }
    return out;
}

// bool DistanceMatrix::distanceComparator(const Record &r1,const Record& r2){
//     double a1,a2;
//     a1 = r1.getDistance();
//     a2 = r2.getDistance();
//     return a1 < a2;
// }

void DistanceMatrix::sortRecords(Data& obj){
    // cout << "lol";
    // vector<Record> vec = obj.getData();
    sort(obj.getData().begin(), obj.getData().end(),
          [](const Record& a,const Record& b) {
    return a.getDistance() < b.getDistance();
});
    // cout << "distance in compute distance " << obj.getRecord(0).getDistance() << endl;
    // sort(obj.getData().begin(),obj.getData().end(), DistanceMatrix::distanceComparator);
}

void DistanceMatrix::computeDistances(Data& obj){
    vector<double> avg = averageRecord(obj);
    int size = obj.getSize();
    for(int i =0;i<size;i++){
        obj.getRecord(i).setDistance(DistanceMatrix::euclideanDistance(obj.getRecord(i).getFeatureVector(),avg));
    }
}


void DistanceMatrix::populateMatrix(Data& data){
    // int sz = data.getSize();
    int sz = 100;
    matrix.resize(sz);
    for(int i =0;i<sz;i++){
        matrix[i].resize(sz);
        for(int j=0;j<i;j++){
            double m = DistanceMatrix::euclideanDistance(data.getRecord(i).getFeatureVector(),data.getRecord(j).getFeatureVector());
            matrix[i][j] = m;
            matrix[j][i] = m;
            cout << m << " i " << i << " j " << j << endl;
            // if(i==0)
            // cout << matrix[0][1] << " ";
        }
    }
}


std::ostream& operator<<(std::ostream& os, DistanceMatrix& mat) {
    for(int i =0;i<mat.matrix.size();i++){
        for(int j=0;j<mat.matrix.size();j++){
            os << mat.matrix[i][j] << " ";
        }
        os << "\n";
    }
    os << "\n";
}


