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

double **Trans(double **A,int n,int m)
{
    double **B = new double*[n];
    for(int i=0;i<m;i++)
        B[i] = new double [m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            B[j][i]=A[i][j];
    return B;
}

double ** multiplication(double **A, double **B, int lineA, int columnA, int lineB, int columnB)
{
	double **result = new double *[lineA];
	for (int i = 0; i < lineA; i++)
		result[i] = new double [columnB];
		
	if (columnA != lineB)
		{
			cout << "Dimension error. Try again." << endl;
			return 0;
		}
		
	for (int i = 0; i < lineA; i++)
		for (int j = 0; j < columnB; j++)
			for (int k =0; k < lineB; k++)
				result[i][j] += A[i][k]*B[k][j];
				
	return result;
}
