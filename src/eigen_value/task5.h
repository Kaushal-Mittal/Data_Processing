#ifndef Task5_H
#define Task5_H

#include<vector>
using namespace std;

class task5
{
  public:
    task5(int n, int p, vector <vector< double> > sqmatrix);
    void eigen_calculator(vector<vector<double> > &eigen_vectors, vector <double> &eigen_values);
  private:
    vector<vector<double> > sqmatrix;
    int n, p;
};

#endif
