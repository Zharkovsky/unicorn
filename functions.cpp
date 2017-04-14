#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>
#include "CONSTANTS.cpp"

using namespace std;

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

void show (double **a, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        	cout << setw(15) << a[i][j];
        
    	cout << endl;
    }
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

void stoi (string inputString, int &k)
{
	k = 0;
	bool flag = 1;
	
	for (int i = inputString.size() - 1; i >= 0 && flag; --i)
	{
		if (inputString[i] >= '0' && inputString[i] <= '9') 
			k = k * 10 + (inputString[i]-'0');
		else 
			flag = 0;
	}
	
	if (!flag)
	{
		cout << "Incorrect input (int), try again: ";
		cin >> inputString;
		stoi (inputString, k);
	}
}

void stod (string inputString, double &k)
{
	k = 0;
	bool flag = 1;
	int i = 0, count = 0;
	
	while (i < inputString.size() && inputString[i] != '.')
	{
		if (inputString[i] >= '0' && inputString[i] <= '9') 
			k = k * 10 + (inputString[i] - '0');
		else 
			flag=0;
		++i;
	}
	
	++i;
	
	while (i < inputString.size())
	{
		++count;
		if (inputString[i] >= '0' && inputString[i] <= '9') 
			k = k * 10 + (inputString[i] - '0');
		else 
			flag = 0;
		++i;
	}
	
	if (count != 0)
	{
		double ten = 1;
		for (i = 0; i < count; ++i) 
			ten *= 10;
		k /= ten;
	}
	
	if (!flag)
	{
		cout << "Incorrect input (double), try again: ";
		cin >> inputString;
		stod (inputString, k);
	}
}

void enterMatr(double ***firstMatrix, int &line1, int &column1, double ***secondMatrix, int &line2, int &column2)
{
	cout << ENTER_COMMAND << endl; 
	cout << YOUR_MATRIX << endl << RANDOM_MATRIX << endl;
	
	int command = 0;  //i is command
	
	string stringForInput; //for input
    cin >> stringForInput;
    stoi (stringForInput, command);
	
	switch(command)
	{
		case YOUR_MATRIX_FILL: {
			
			cout << ENTER_AMOUNT;
			cin >> stringForInput;
            stoi (stringForInput, command);
            
            switch(command)
            {
            	case oneMatr: {
           		 	cout << ENTER_SIZE;
            		cin >> stringForInput; 
					stoi (stringForInput, line1);
    	        	cin >> stringForInput; 
					stoi (stringForInput, column1);
                
            		*firstMatrix = newMatrix (line1, column1);
            		assert (*firstMatrix != NULL);
            	
    	    	    cout << ENTER_MATRIX;
    	        	for (int i = 0; i < line1; ++i)
    		        	for (int j = 0; j < column1; ++j)
    		        	{
    			        	cin >> stringForInput;
    			        	stod (stringForInput, (*firstMatrix)[i][j]);
    			        	cout<<  stringForInput;
    		        	}
            		
					break;
				}
				case twoMatr: {
    	            cout << ENTER_SIZE << FIRST_MATRIX;
            	    cin >> stringForInput; 
				    stoi (stringForInput, line1);
    	        	cin >> stringForInput; 
					stoi (stringForInput, column1);
				
            		*firstMatrix = newMatrix (line1, column1);
            		assert (*firstMatrix != NULL);
	
            		cout << ENTER_MATRIX;
            		for (int i = 0; i < line1; ++i)
    		    	    for (int j = 0; j < column1; ++j)
    		        	{
    			    	    cin >> stringForInput;
    			    	    stod (stringForInput, (*firstMatrix)[i][j]);
    		        	}
    		        
            		cout << ENTER_SIZE << SECOND_MATRIX;
            		cin >> stringForInput; 
					stoi(stringForInput, line2);
    	        	cin >> stringForInput; 
					stoi (stringForInput, column2);
                
	        		*secondMatrix = newMatrix (line2, column2);
	        		assert (*secondMatrix != NULL);
	        	
    	        	cout << ENTER_MATRIX;
    	        	for (int i = 0; i < line2; ++i)
            			for (int j = 0; j < column2; ++j)
    	        		{
    			        	cin >> stringForInput;
    			        	stod (stringForInput, (*secondMatrix)[i][j]);
    		        	}
					
					break;
				}
			}
            
			break;
		}
		
		case RANDOM_MATRIX_FILL: {
			
		    cout << ENTER_SIZE << FIRST_MATRIX <<endl;
		    cin >> stringForInput;
            stoi (stringForInput, line1);
            cin >> stringForInput;
            stoi (stringForInput, column1);
	        cout << ENTER_SIZE << SECOND_MATRIX <<endl;
	        cin >> stringForInput;
            stoi (stringForInput, line2);
            cin >> stringForInput;
            stoi (stringForInput, column2);
	    
		    *firstMatrix = newMatrix(line1,column1);
		    *secondMatrix = newMatrix(line2,column2);	
		
		    Random(*firstMatrix,line1,column1);
		    Random(*secondMatrix,line2,column2);
		    cout << FIRST_MATRIX << endl;
	    	show(*firstMatrix,line1,column1);
		    cout << SECOND_MATRIX << endl;
		    show(*secondMatrix,line2,column2);
		    
			break;
		}
		default: {
			cout << FALSE_COMMAND;
			enterMatr(firstMatrix, line1, column1, secondMatrix, line2, column2);
			break;
		}
	}
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
