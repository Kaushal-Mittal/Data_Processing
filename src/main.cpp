#include <iostream>
#include <fstream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
#include "vector"
using namespace std;

vector<double> task_6(vector<vector<double>> matrix)
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
     sum[index]=10000000;
     //cout<<sum[index]<<"#";
     //cout<<index<<"@";
     index_list.push_back(index);
    }
    return index_list;
   }

bool distanceComparator(Record &r1,Record& r2){
    double a1,a2;
    a1 = r1.getDistance();
    a2 = r2.getDistance();
    cout << r1 << " " << r2 << "lol\n";
    return a1 < a2;
}

int main(void){
    Data a;
    vector<double> ll;
    ofstream outputFile("out.txt");
    a.readInput(17,0);
    DistanceMatrix b;
    b.computeDistances(a);
    cout << a.getRecord(0).getFeatureVector() << endl;
    b.sortRecords(a);
    cout << a.getRecord(0).getFeatureVector() << endl;
    b.populateMatrix(a);
    // cout << b;
    // cout << b.getMatrix().size() << "size !!\n";


    // ll = task_6(b.getMatrix());
    
    
    // for(int i=0;i<ll.size();i++)
    //     {
    //         cout<<"("<<ll[i]<<","<<ll[i]<<")";
    //     }
    outputFile << b;
    outputFile.close(); 
    return 0;
}