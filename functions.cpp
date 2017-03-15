#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

double **newmatrix (int line, int column)
{
	double **matrix = new double *[line];
	for (int i = 0; i < line; i++)
		matrix[i] = new double [column];
	return matrix;
}

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
	double **result = newmatrix(lineA, columnB);
		
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

double ** Random(double **A, int lineA, int columnA)
{
	for (int i = 0; i < lineA ; i++)
		for (int j = 0; j < columnA ; j++)
			A[i][j] = rand()%20+1;
	return A;
}

