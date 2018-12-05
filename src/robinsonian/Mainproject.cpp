#include<iostream>
#include<fstream>
#include "ROBINSON_REORDERING.h"
#include<bits/stdc++.h>

int main()
{
  int n,i,j;
  ifstream file("out.txt");
  ofstream file_("t.txt");
  if(file.is_open())
  {
    file>>n;
    Robinson r = Robinson(n);
    double **array;
    array = (double**)malloc(n*sizeof(double*));
    for(i=0;i<n;i++) array[i] = (double*)malloc(n*sizeof(double));

    for(i=0;i<n;i++)
      for(j=0;j<n;j++) file>>array[i][j];

//      cout<<array[i][j];
    for(int k=0;k<n/2;k++) array = r.compute(array,n,n-k,k);

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        //cout<<endl;
        file_<<array[i][j]<<" ";
      }
      file_<<endl;
    }
    file.close();
  }
  return 0;
}
