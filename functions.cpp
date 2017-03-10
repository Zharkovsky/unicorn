#include <iostream>
#include <iomanip>
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

double **Sum(double **A,double **B,int An,int Am,int Bn,int Bm)
{
    if(An!=Bn || Am!=Bm) return NULL;
    double **C = new double *[An];
    for(int i=0;i<Am;i++)
        C[i] = new double [Am];
    for(int i=0;i<An;i++)
        for(int j=0;j<Am;j++)
            C[i][j]=A[i][j]+B[i][j];
    return C;
}
