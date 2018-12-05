#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include "ROBINSON_REORDERING.h"

using namespace std;

Robinson::Robinson(int n)
{
  this->n = n;
}

double** Robinson::transpose(double **array,int n)
{
  double temp[n][n];

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      temp[i][j] = array[i][j];
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      array[i][j] = temp[j][i];
    }
  }
  return array;
}


double** Robinson::setRow(double **array,int n,int x,int y)
{
  double *temp;
  temp = (double*)malloc(n*sizeof(double));
  temp = array[x];
  array[x] = array[y];
  array[y] = temp;
  return array;
}

double** Robinson::setColumn(double **array,int n,int x,int y)
{
  double *temp;
  temp = (double*)malloc(n*sizeof(double));
  array = transpose(array,n);
  temp = array[x];
  array[x] = array[y];
  array[y] = temp;
  array = transpose(array,n);
  return array;
}

double** Robinson::sortRowAndColumn(double **array,int n,int h,int w)
{
  double *temp;
  temp = (double*)malloc(n*sizeof(double));
  for(int i=w; i<h; i++)
  {
    for(int j=i+1; j<h; j++)
    {
      if(array[i][w] > array[j][w])
      {
        setRow(array,n,i,j);
        setColumn(array,n,j,i);
      }
      else continue;
    }
  }
  for(int i=w; i<h; i++)
  {
    for(int j=i+1; j<h; j++)
    {
      if(array[h-1][i] < array[h-1][j])
      {
        setRow(array,n,i,j);
        setColumn(array,n,j,i);
      }
      else continue;
    }
  }
  return array;
}

double** Robinson::compute(double **array,int n,int h,int w)
{
  int max = 0,i,j,x,y;
  double *temp;
  temp = (double*)malloc(n*sizeof(double));
  for(i=0;i<h;i++)
  {
    for(j=w;j<h;j++)
    {
      if(i>=j)
      {
        if(array[i][j] > max)
        {
          max = array[i][j];
          x = i;
          y = j;
        }
      }
    }
  }

  if(x!=h-1)
  {
    setRow(array,n,x,h-1);
    setColumn(array,n,h-1,x);
  }

  if(y!=w)
  {
    setColumn(array,n,y,w);
    setRow(array,n,w,y);
  }

  sortRowAndColumn(array,n,h,w);
  return array;
}
// 
// int main()
// {
//   int n,i,j;
//   Robinson r=new Robinson(n);
//   ifstream file("input.txt");
//   ofstream file_("output.txt");
//   if(file.is_open())
//   {
//     file>>n;
//     double **array;
//     array = (double**)malloc(n*sizeof(double*));
//     for(i=0;i<n;i++) array[i] = (double*)malloc(n*sizeof(double));
//
//     for(i=0;i<n;i++)
//       for(j=0;j<n;j++) file>>array[i][j];
//
//     // cout<<endl;
//     for(int k=0;k<n/2;k++) array =r.compute(array,n,n-k,k);
//
//     for(int i=0;i<n;i++)
//     {
//       for(int j=0;j<n;j++)
//       {
//         file_<<array[i][j]<<" ";
//       }
//       file_<<endl;
//     }
//     file.close();
//   }
//   return 0;
// }
