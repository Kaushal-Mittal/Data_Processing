#include"iostream"
#include"vector"
#include"algorithm"
#include"iterator"
using namespace std;

vector<double> task_6(vector<vector<double>> &matrix)
 {
   int i,j,R,C,l=0;
   vector<double> index_list;
   R=matrix.size();
  
   double sum[R];
   double least_degree;
   int p=0;
   C=R;
   for (int i=0; i<R;i++)
    {
      for (int j=0; j<C;j++)
        {
          if(i!=j)
            sum[i]=sum[i]+matrix[i][j];
        }
    }

   for(int i=0;i<R;i++)
    {
      int index=0;
     double temp=sum[0];
     for(int k=1;k<R;k++)
      {
        if(temp>sum[k])
         {
          temp=sum[k];
          index=k;
         }
      }
     for(int k=0;k<R;k++)
      {
       sum[k]-=matrix[k][index];
      }
     sum[index]=10000;
     //cout<<sum[index]<<"#";
     //cout<<index<<"@";
     index_list.push_back(index);
    }
    return index_list;
   }
// int main()
// {
// vector<vector<double>>matrix;
// vector<double>index_list;
// double value;
// for(int i=0;i<3;i++)
//  {
//   vector<double>myvector;
//   for (int j=0;j<3;j++)
//    {
//     cin>>value;
//     myvector.push_back(value);
//    }
//    matrix.push_back(myvector);
//  }
//  index_list=task_6(matrix);
//  for(int i=0;i<3;i++)
//   {
//     cout<<"("<<index_list[i]<<","<<index_list[i]<<")";
//   }
// }
