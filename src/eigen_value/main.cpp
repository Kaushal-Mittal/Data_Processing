#include <iostream>
#include <bits/stdc++.h>

#include "task5.h"
using namespace std;

int main()
{
  int n, p;

  vector<vector<double> > sqmatrix;
  vector<vector<double> > eigen_vectors;
  vector<double> eigen_values;

  ifstream fin;
  ofstream fout;
  double temp;
  fin.open("out.txt");
  fin>>n>>p; // p is number of eigenvectors we want

  for(int i=0;i<n;i++) //n is the size of square matrix
  {
    vector<double> row;
    for(int j=0;j<n;j++)
    {
      fin>>temp;
      row.push_back(temp);
    }
    sqmatrix.push_back(row);
  }
  task5 t(n, p, sqmatrix);
  t.eigen_calculator(eigen_vectors, eigen_values);
  cout<<"Eigen Vectors : "<<endl;
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<p;j++)
    {
      cout<<eigen_vectors[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Eigen Values : "<<endl;
  for(int i=0;i<p;i++)
  {
    cout<<eigen_values[i]<<" ";
  }
  cout<<endl;
  return 0;
}
