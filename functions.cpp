#include "vyvod.h"
#include <cmath>
#include <ctime>
#include <string>
#include "CONSTANTS.cpp"

double **newMatrix (int line, int column)
{
	double **matrix = new double *[line];
	
	for (int i = 0; i < line; ++i)
		matrix[i] = new double [column];
		
	return matrix;
}

double **mulNum (double **firstMatrix, int n, int m, double digit)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        	firstMatrix[i][j] *= digit;

    return firstMatrix;
}

double determinate (double **a, int size)
{
 	int i, j;
 	double det = 0;
 	double **matr;
 	
 	if (size == 1)
 	 	det = a[0][0];	
 	else if (size == 2)
            det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else
	{
  		matr = new double *[size-1];
  		
  		for (i = 0; i < size; ++i)
  		{
   			for (j = 0; j < size-1; ++j)
   			{
    			if (j < i)
     			   	matr[j] = a[j];
    			else
     			    matr[j] = a[j+1];
   			}
   			det += pow ((double)-1, (i+j)) * determinate (matr, size-1) * a[i][size-1];
  		}
  		
  		delete[] matr;
 	}
 	
	return det;
}

double **sum (double **firstMatrix, double **secondMatrix, int An, int Am, int Bn, int Bm)
{	
    if (An != Bn || Am != Bm) 
    {
    	cout << "Error. Try Again." << endl;
    	
		double **C = newMatrix(An, Am);
        	
        for (int i = 0; i < An; ++i)
        	for (int j = 0; j < Am; ++j)
            	C[i][j] = 0.0;
            	
    	return C;
    }
    
    double **C = newMatrix(An, Am);
        
    for (int i = 0; i < An; ++i)
        for (int j = 0; j < Am; ++j)
            C[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
            
    return C;
}

double **trans (double **firstMatrix, int n, int m)
{
    double **secondMatrix = newMatrix(m ,n);
        
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            secondMatrix[j][i] = firstMatrix[i][j];
            
    return secondMatrix;
}

double **multiplication (double **firstMatrix, double **secondMatrix, int lineA, int columnA, int lineB, int columnB)
{
	double **result = newMatrix(lineA, columnB);
		
	for (int i = 0; i < lineA; i++)
		for (int j = 0; j < columnB; j++)
			for (int k =0; k < lineB; k++)
				result[i][j] += firstMatrix[i][k]*secondMatrix[k][j];
				
	return result;
}

void Random(double **firstMatrix, int lineA, int columnA)
{
	for (int i = 0; i < lineA ; i++)
		for (int j = 0; j < columnA ; j++)
			firstMatrix[i][j] = rand()%20+1;
}

void delMatr (double **firstMatrix, int lineA)
{
    for (int i = 0; i < lineA; ++i)
    	delete[] firstMatrix[i];
    
    delete[] firstMatrix;
}

void obrMatrix (double **firstMatrix, int n) 
{
    double **matrix = newMatrix(n, 2*n);
       
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = firstMatrix[i][j];
    
    double ratio, x;
    int i, j, k;
    
    for (i = 0; i < n; ++i)
	{
        for (j = n; j < 2*n; ++j)
		{
            if (i == (j-n))
                matrix[i][j] = 1.0;
            else
                matrix[i][j] = 0.0;
        }
    }
    
    for (i = 0; i < n; ++i)
	{
        for (j = 0; j < n; ++j)
		{
            if (i != j)
			{
                ratio = matrix[j][i] / matrix[i][i];
                
                for (k = 0; k < 2 * n; ++k)
				{
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    
    for (i = 0; i < n; ++i)
	{
        x = matrix[i][i];
        for (j = 0; j < 2*n; ++j)
		{
            matrix[i][j] /= x;
        }
    }
    
    //printf("The inverse matrix is: \n");
    //show(matrix,n,2*n);
    
    delMatr (matrix, n);
}    
    
int rank (double **matrix, int i, int j)
{
    int r = 0;
    int q = 1;
    int min = i;
    
    if(j < min) 
    	min = j;
 
    while (q <= min) 
    { 
        double **secondMatrix = newMatrix (q, q); 
 
        for (int a = 0; a < (i-(q-1)); ++a) 
        {
            for (int b = 0; b < (j-(q-1)); ++b)
            {
                for (int c = 0; c < q; ++c)
                    for (int d = 0; d < q; ++d)
                        secondMatrix[c][d] = matrix[a+c][b+d];
                        
                if (!(determinate(secondMatrix,q) == 0))
                {
                    r = q;
                }
            }
        }
        
        delMatr (secondMatrix,q);
    	q++; 
    }
    
    return r;
}

void typeMatr (double **firstMatrix, int n, int m)
{
	cout << "Type of matrix:";
	
	if (n == m) 
		cout << " square";
		
	bool temp = true;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (firstMatrix[i][j] != 0) 
				temp = false;
	
	if (temp)
		cout << " zero";
		
	temp = true;
	
	if (m == 1) 
		cout << " vector-column";
	if (n == 1) 
		cout << " vector-line";
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (i != j && firstMatrix[i][j] != 0) 
				temp = false;
	
	if (temp) 
		cout << " diagonal";
	
	temp = true;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i != j && firstMatrix[i][j] != 0) 
				temp = false;
			if (i == j && firstMatrix[i][j] != 1) 
				temp = false;
		}
	}
	
	if(temp) 
		cout << " identity";
		
	temp = true;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (i < j && firstMatrix[i][j] != 0) 
				temp = false;
	
	if (temp) 
		cout << " lower diagonal";
		
	temp = true;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i > j && firstMatrix[i][j] != 0) 
				temp = false;
				
	if (temp) 
		cout << " upper diagonal";
		
	cout << endl;
}

void printCommands()
{
	cout << CHOOSE_COMMAND << endl;
    cout << EXIT << endl;
    cout << MULTIPLICATION_BY_DIGIT << endl;
    cout << MULTIPLICATION_2_MATRIX << endl;
    cout << TRANSPOSING << endl;
    cout << DETERMINANT << endl;
    cout << MATRIX_SUM << endl;
    cout << MATRIX_TYPE << endl;
    cout << INVERTIBLE_MATRIX << endl;
    cout << MATRIX_RANK << endl;
}
