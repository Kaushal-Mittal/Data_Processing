#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <bits/stdc++.h> 

#include "matrix.h"
#include "data.h"
#include "record.h"
#include "task4.h"

using namespace std;

task4::task4(){}

task4::~task4(){}

double  task4::generate_covariance(vector<double> v1, vector<double> v2){

    double average1 = accumulate( v1.begin(), v1.end(), 0.0)/v1.size();
    double average2 = accumulate( v2.begin(), v2.end(), 0.0)/v2.size();

    double covariance;
    
    // finding variance
        double temp = 0;
    for(int i= 0; i< v1.size(); i++) {
        temp += ((v1[i] - average1)*(v2[i] - average2));
    }
        covariance = temp/(v1.size()-1);

    return covariance;
}

bool func(pair<int, double> p1, pair<int, double> p2){
    return p1.second < p2.second ;
}

// vector<vector<double> > task4::generate_covariance_matrix(Data dataobj){
void task4::generate_covariance_matrix(Data dataobj){

    int n = dataobj.getSize();

    // typedef pair<int, double> pair<int, double>;
    vector<pair<int, double> > variances;
    
    for(size_t i = 0; i < dataobj.getFeatureSize(); i++){
        int index = i;
        double variance;
        vector<double> v = dataobj.get_column(index);
        // for(size_t j = 0; j < dataobj.getSize(); j++){   
        //     v.push_back(dataobj.getData()[j].getFeatureVector()[i]);
        // }-std=c++11
        variance = generate_covariance(v, v);
        variances.push_back(pair<int, double>(index, variance));
        v.clear();
    }



    sort(variances.begin(), variances.end(), func);
// [](pair<int, double> p1, pair<int, double> p2){return p1.second < p2.second ;}

    vector<pair<int, int> > permutation;
    for(size_t i = 0; i < variances.size(); i++){
        permutation.push_back(pair<int, int>(i, variances[i].first));
    }

    vector<vector<double> > covar_matrix;
    
    cout << permutation.size() << endl;
    
    for(int i = 0; i < permutation.size(); i++){
        // vector<double> temp1;
        cout<<endl << i<< "---" ;
        for(int j = 0; j < permutation.size(); j++){
            
            double temp2;

            // vector<double> c1 = dataobj.get_column(permutation[i].second);
            // vector<double> c2 = dataobj.get_column(permutation[j].second);

            temp2 = generate_covariance(dataobj.get_column(permutation[i].second),  dataobj.get_column(permutation[j].second));

            // c1.clear();
            // c2.clear();

            // temp1.push_back(temp2);
            cout << temp2 << " ";
        }
        // covar_matrix.push_back(temp1);
        
    }
    cout << "lol";


    

    // int a = permutation.size();
    // for(size_t i = 0; i < a; i++)
    // {
    //     cout << i << " :::"<<permutation[i] <<endl ;
    // } 



}


