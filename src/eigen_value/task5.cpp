#include <bits/stdc++.h>
#include "task5.h"

using namespace std;

task5::task5(int n, int p, vector<vector<double> > m)
{
  this->n = n;
  this->p = p;
  for(int i=0;i<n;i++)
  {
    sqmatrix.push_back(m[i]);
  }
}

void task5::output(vector <vector <double> > &eigen_vectors, vector <double> &eigen_values)
{
  //Power Iteration Algorithm
  //As given in the reference link!
  for(int loop=0;loop<p;loop++)
  {
    vector <double> x(n), y(n);
    vector<double> tempArr(n);
    double temp = 0;
    double l=0, k=0;
    for(int i=0;i<n;i++)
    {
      x[i] = 1;
      temp+=x[i]*x[i];
    }
    temp = sqrt(temp);
    for(int i=0;i<n;i++)
    {
      x[i]=x[i]/temp;
    }
    do{
      for(int i=0;i<n;i++)
      {
        y[i] = x[i];
      }
      l = k;
      k = 0;
      for(int i=0;i<loop;i++)
      {
        for(int j=0;j<n;j++)
        {
          tempArr[j] = eigen_vectors[i][j];
        }
        temp=0;
        for(int j=0;j<n;j++)
        {
          temp += y[j]*tempArr[j];
        }
        for(int j=0;j<n;j++)
        {
          tempArr[j] = tempArr[j]*temp;
          y[j] = y[j]-tempArr[j];
        }
      }
      temp = 0;
      for(int i=0;i<n;i++)
      {
          x[i]=0;
          for (int j=0;j<n;j++)
          {
            x[i]+=sqmatrix[i][j]*y[j];
          }
          temp += x[i]*x[i];
      }
      k = sqrt(temp);
      for(int i=0;i<n;i++)
      {
        x[i]=x[i]/k;
      }
    }while(fabs(k-l)>0.00001);
    if((x[0]<0 && y[0]>0) || (x[0]>0 && y[0]<0))
    {
      k = -k;
    }
    eigen_vectors.push_back(x);
    eigen_values.push_back(k);
  }
}
