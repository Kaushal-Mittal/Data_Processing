#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <bits/stdc++.h> 
#include "distanceMatrix.h"
#include "matrix.h"
#include "data.h"
#include "record.h"
#include "task4.h"
#include "utilities.h"
#include <math.h> 


using namespace std;

task4::task4(){}
////////////////////////////////////////////////////////////////////////////////////////
task4::~task4(){}
////////////////////////////////////////////////////////////////////////////////////////
bool func(pair<int, double> p1, pair<int, double> p2){ // Custom Comparator to sort variances
    return p1.second > p2.second ;
}
////////////////////////////////////////////////////////////////////////////////////////
double  task4::generate_covariance(vector<double> v1, vector<double> v2){

    double average1 = 0;
    double average2 = 0;

    average1 = accumulate( v1.begin(), v1.end(), 0.0)/v1.size();
    average2 = accumulate( v2.begin(), v2.end(), 0.0)/v2.size();

    double covariance;
    
    // finding variance
    double temp = 0;
    for(int i= 0; i< v1.size(); i++) {
        temp += ((v1[i] - average1)*(v2[i] - average2));
    }
    covariance = temp/(v1.size()-1);

    return covariance;
}
////////////////////////////////////////////////////////////////////////////////////////
vector<vector<double> > task4::generate_covariance_matrix(Data dataobj){

    int n = dataobj.getSize();
    vector<pair<int, double> > variances;
    
//Finding Variance for each column 
    for(size_t i = 0; i < dataobj.getFeatureSize(); i++){
        int index = i;
        double variance;
        vector<double> v = dataobj.get_column(index);
        variance = generate_covariance(v, v);
        variances.push_back(pair<int, double>(index, variance));
        v.clear();
    }



// Normalisation

int max = variances[0].second;
int min = variances[0].second;

for(int i =0;i<variances.size();i++){
    if(variances[i].second > max){
        max = variances[i].second;
    }
    if(variances[i].second < min){
        min = variances[i].second;
    }
}
for(int i =0;i<variances.size();i++){
    variances[i].second = (variances[i].second-min)/(max-min);
}

//Sort using custom comparator func
    sort(variances.begin(), variances.end(), func);


//Permutation [(old index, new index),()]
    vector<pair<int, int> > permutation;
    for(size_t i = 0; i < variances.size(); i++){
        permutation.push_back(pair<int, int>(i, variances[i].first));
    }

    n = permutation.size();
    vector<double> t(n, 0);
    vector<vector<double> > covar_matrix(n, t);
    
//Generating Covariance Matrix
    for(int i = 0; i < permutation.size(); i++){
        for(int j = 0; j < permutation.size(); j++){

            double covar_xy, var_x, var_y;
            double temp2;

            int p_i = permutation[i].second;
            int p_j = permutation[j].second;
            
            vector<double> c1 = dataobj.get_column(p_i);
            vector<double> c2 = dataobj.get_column(p_j);

            // temp2 = generate_covariance(dataobj.get_column(permutation[i].second),  dataobj.get_column(permutation[j].second));
            covar_xy = generate_covariance(c1, c2);
            var_x = generate_covariance(c1, c1);
            var_y = generate_covariance(c2, c2);

            temp2 = covar_xy / sqrt(var_x * var_y);

            covar_matrix[i][j] = (temp2);
            if(i==j){
                covar_matrix[i][j] = variances[i].second;
            }

        }
    }

    return covar_matrix;
}


