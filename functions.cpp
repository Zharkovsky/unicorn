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

void show(double **a, int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<setw(15)<<a[i][j];
        cout<<endl;
    }
}


double Determinate(double **a,int size)
{
 int i,j;
 double det=0;
 double**matr;
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
  matr=new double*[size-1];
  for(i=0;i<size;++i)
  {
   for(j=0;j<size-1;++j)
   {
    if(j<i)
     matr[j]=a[j];
    else
     matr[j]=a[j+1];
   }
   det+=pow((double)-1,(i+j))*Determinate(matr, size-1)*a[i][size-1];
  }
  delete[] matr;
 }
return det;
}

double **Sum(double **A,double **B,int An,int Am,int Bn,int Bm)
{	
    if(An!=Bn || Am!=Bm) 
    {
    	cout<<"Error. Try Again."<<endl;
		double **C = new double*[An];
		for(int i=0;i<An;i++)
        	C[i] = new double[Am];
        for(int i=0;i<An;i++)
        	for(int j=0;j<Am;j++)
            	C[i][j]=0.0;
    	return C;
    }
    double **C = new double *[An];
    for(int i=0;i<An;i++)
        C[i] = new double [Am];
    for(int i=0;i<An;i++)
        for(int j=0;j<Am;j++)
            C[i][j]=A[i][j]+B[i][j];
    return C;
}

double **Trans(double **A,int n,int m)
{
    double **B = new double*[m];
    for(int i=0;i<m;i++)
        B[i] = new double [n];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            B[j][i]=A[i][j];
    return B;
}

double ** Multiplication(double **A, double **B, int lineA, int columnA, int lineB, int columnB)
{
	double **result = newmatrix(lineA, columnB);
		
	if (columnA != lineB)
		{
			cout << "Dimension error. Try again." << endl;
			double **C = new double*[lineA];
			for(int i=0;i<lineA;i++)
        		C[i] = new double[columnA];
        	for(int i=0;i<lineA;i++)
        		for(int j=0;j<columnA;j++)
            		C[i][j]=0.0;
    		return C;
		}
		
	for (int i = 0; i < lineA; i++)
		for (int j = 0; j < columnB; j++)
			for (int k =0; k < lineB; k++)
				result[i][j] += A[i][k]*B[k][j];
				
	return result;
}

/*double ** Random(double **A, int lineA, int columnA)
{
	for (int i = 0; i < lineA ; i++)
		for (int j = 0; j < columnA ; j++)
			A[i][j] = rand()%20+1;
	return A;
}*/

void DelMatr(double **A, int lineA)
{
     for (int i = 0; i < lineA; ++i)
      delete[] A[i];
     delete [] A;
}

void obrmatrix(float **A,int n) 
{
  
    float **matrix=new float*[n];
    for(int i=0;i<n;i++)
     matrix[i]=new float [2*n];
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
      matrix[i][j]=A[i][j];
    
    float ratio,x;
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = n; j < 2*n; j++){
            if(i==(j-n))
                matrix[i][j] = 1.0;
            else
                matrix[i][j] = 0.0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i!=j){
                ratio = matrix[j][i]/matrix[i][i];
                for(k = 0; k < 2*n; k++){
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    for(i = 0; i < n; i++){
        x = matrix[i][i];
        for(j = 0; j < 2*n; j++){
            matrix[i][j] /= x;
        }
    }
    printf("The inverse matrix is: \n");
    show(matrix,n,2*n)
    DelMatr(matrix,n)
    return;
int rank(double ** matrix, int i, int j)
{
    int r = 0;
    int q = 1;
    int min = i;
    
    if(j < min) 
    	min = j;
 
    while (q <= min) 
    { 
        double **B = newmatrix(q,q); 
 
        for (int a = 0; a < (i-(q-1)); a++) 
        {
            for (int b = 0; b < (j-(q-1)); b++)
            {
                for (int c = 0; c < q; c++)
                    for (int d = 0; d < q; d++)
                        B[c][d] = matrix[a+c][b+d];
 
                if(!(Determinate(B,q)==0)) 
                { 
                    r = q; 
                }
            }
        }
        DelMatr(B,q);
    q++; 
    }
    return r;
}

void TypeMatr(double **A,int n,int m)
{
	cout<<"Type of matrix:";
	if(n==m) cout<<" square";
	bool temp=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j]!=0) temp=false;
		}
	}
	if(temp) cout<<" zero";
	temp=true;
	if(m==1) cout<<" vector-column";
	if(n==1) cout<<" vector-line";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i!=j && A[i][j]!=0) temp=false;
		}
	}
	if(temp) cout<<" diagonal";
	temp=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i!=j && A[i][j]!=0) temp=false;
			if(i==j && A[i][j]!=1) temp=false;
		}
	}
	if(temp) cout<<" identity";
	temp=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i<j && A[i][j]!=0) temp=false;
		}
	}
	if(temp) cout<<" lower diagonal";
	temp=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i>j && A[i][j]!=0) temp=false;
		}
	}
	if(temp) cout<<" upper diagonal";
	temp=true;
	cout<<endl;
}
