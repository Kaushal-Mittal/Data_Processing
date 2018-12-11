#ifndef Task5_H_
#define Task5_H_

#include<vector>
using namespace std;

class task5
{
  private:
    int n, p;
    vector<vector<double> > sqmatrix;

  public:
    task5(int n, int p, vector <vector< double> > sqmatrix);
    void output(vector<vector<double> > &eigen_vectors, vector <double> &eigen_values);
};

#endif
