#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double **MulNum(double **A,int n,int m,double digit)
{
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            A[i][j] *= digit;

    return A;
}

void show(float **a, int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<setw(3)<<a[i][j];
        cout<<endl;
    }
}

float determinant(float **a,int size)
{
 int i,j;
 double det=0;
 float**matr;
 if(size==1)
 {
  det=a[0][0];
 }
 else if(size==2)
 {
  det=a[0][0]*a[1][1]-a[0][1]*a[1][0];
 }
 else
 {
  matr=new float*[size-1];
  for(i=0;i<size;++i)
  {
   for(j=0;j<size-1;++j)
   {
    if(j<i)
     matr[j]=a[j];
    else
     matr[j]=a[j+1];
   }
   det+=pow((float)-1,(i+j))*determinant(matr, size-1)*a[i][size-1];
  }
  delete[] matr;
 }
return det;
}

