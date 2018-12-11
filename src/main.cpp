#include <iostream>
#include <fstream>
#include "data.h"
#include "record.h"
#include "distanceMatrix.h"
#include "utilities.h"
#include "task4.h"
#include "vector"
#include "eigen_value/task5.h"
#include "robinsonian/ROBINSON_REORDERING.h"
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


int main(void){
    Data a;
    vector<double> ll;
    int no;
    task4 t4;
    DistanceMatrix b;
    vector<vector<double> > eigen_vectors;
    vector<vector<double> > sq_matrix;
    vector<double> eigen_values;
    // ofstream outputFile("test.csv");
    a.readInput(17,0);


    cout << "Generate Matrix" << endl;
    cout << "1 for Distance Matrix" << endl;
    cout << "2 for Covariance Matrix" << endl;
    scanf("%i",&no);
    
    if(no == 2){
        vector<vector<double> > cv_m = t4.generate_covariance_matrix(a);
        ofstream out;
        out.open("task4.csv");
        for(size_t i = 0; i < cv_m.size(); i++){
            for(size_t j = 0; j < cv_m[i].size(); j++){
                out << cv_m[i][j] << "," ;
            }
            out << endl;
        }
        out.close();
        cout << "task4.csv Generated\n";
        sq_matrix = cv_m;
    }    

    if(no == 1){
    ofstream outputFile("output.txt");
    ofstream outputFil("out.txt");
    b.computeDistances(a);
    b.sortRecords(a);
    b.populateMatrix(a);
    outputFil << b.getMatrix().size() << endl;
    outputFile << b;
    outputFil << b;
    outputFile.close();
    outputFil.close();
    cout << "out.txt Generated\n";
    sq_matrix = b.getMatrix();
    }
    
    cout << "Process the generated Matrix\n";
    cout << "1 for Robinsonian" << endl;
    cout << "2 for Calculating Eigen Values" << endl;
    cout << "3 for Calculating EMatrix Reordering" << endl;
    scanf("%i",&no);

    if(no == 1){
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
        // file_<<array[i][j]<<" ";
        cout<<array[i][j]<<" ";
      }
      cout<<endl;
    //   file_<<endl;
    }
    file.close();
  }
    }
    if(no == 2){
        //input
        int p=10;
        task5 t(sq_matrix.size(), p, sq_matrix);
        t.output(eigen_vectors, eigen_values);
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
    }
    if(no == 3){
        ll = task_6(sq_matrix);
         for(int i=0;i<ll.size();i++)
            {
                cout<<"("<<ll[i]<<","<<ll[i]<<")";
            }
    }
    return 0;
}