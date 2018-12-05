#include<iostream>

using namespace std;

class Robinson
{
  private:
    int n;
  public:
    Robinson();
    Robinson(int);
    double** transpose(double **array,int n);
    double** setRow(double **array,int n,int x,int y);
    double** setColumn(double **array,int n,int x,int y);
    double** sortRowAndColumn(double **array,int n,int h,int w);
    double** compute(double **array,int n,int h,int w);
};
