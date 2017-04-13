#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include "functions.cpp"
#include "CONSTANTS.cpp"

using namespace std;

double **newMatrix (int line, int column);
double **sum (double **, double **, int, int, int, int); //A=Sum(B,C,Bn,Bm,Cn,Cm);
double **mulNum (double **, int, int, double); //A=MulNum(B,Bn,Bm,digit)
double **multiplication (double **, double **, int, int, int, int); //A=Mul(B,C,Bn,Bm,Cn,Cm);
double **trans (double **, int, int); //A=Trans(A);
double determinate (double **, int, int); //det=Determinate(A,An,Am);
void show (double **, int, int);
void typeMatr (double **, int, int); //TypeMatr(A,An);
void obrMatrix (float **, int); 
int rank (double **, int, int); 

int main()
{
//	srand(time(0));
	int line1 = 0, line2 = 0, column1 = 0, column2 = 0;
	double number;
	int count = 0;
	double **firstMatrix; 
	double **secondMatrix; 
	cout << ENTER_COMMAND << endl; 
	cout << YOUR_MATRIX << endl << RANDOM_MATRIX << endl;
	int i=0;  //i is command
	cin >> i;
    
    if (i == 2)
    {
        cout << ENTER_SIZE << FIRST_MATRIX <<endl;
	    cin >> line1;
	    cin >> column1;
	    cout << ENTER_SIZE << SECOND_MATRIX <<endl;
	    cin >> line2;
	    cin >> column2;
	    
		double **firstMatrix = newMatrix(line1,column1);
		double **secondMatrix = newMatrix(line2,column2);	
		
		Random(firstMatrix,line1,column1);
		Random(secondMatrix,line2,column2);
		cout << FIRST_MATRIX << endl;
		show(firstMatrix,line1,column1);
		cout << SECOND_MATRIX << endl;
		show(secondMatrix,line2,column2);
	}

    string stringForInput; //for input
    int k = 1;
    cout << ENTER_AMOUNT;
    cin >> stringForInput;
    stoi (stringForInput, k);
    
    if (k == 1)
    {
    	cout << ENTER_SIZE;
    	cin >> stringForInput; 
		stoi (stringForInput, line1);
    	cin >> stringForInput; 
		stoi (stringForInput, column1);
		
    	firstMatrix = newMatrix (line1, column1);
    	assert (firstMatrix != NULL);
    	
    	cout << ENTER_MATRIX;
    	for (int i = 0; i < line1; ++i)
    		for (int j = 0; j < column1; ++j)
    		{
    			cin >> stringForInput;
    			stod (stringForInput, firstMatrix[i][j]);
    		}
    }
    else
    {
    	if (k > 2) 
			cout << FALSE_AMOUNT_OF_MATRIX << endl;
    	cout << ENTER_SIZE;
    	cin >> stringForInput; 
		stoi (stringForInput, line1);
    	cin >> stringForInput; 
		stoi (stringForInput, column1);
		
    	firstMatrix = newMatrix (line1, column1);
    	assert (firstMatrix != NULL);
	
    	cout << ENTER_MATRIX;
    	for (int i = 0;i < line1; ++i)
    		for (int j = 0;j < column1; ++j)
    		{
    			cin >> stringForInput;
    			stod (stringForInput, firstMatrix[i][j]);
    		}
    			
    	cout << ENTER_SIZE << SECOND_MATRIX;
    	cin >> stringForInput; 
		stoi (stringForInput, line2);
    	cin >> stringForInput; 
		stoi (stringForInput, column2);
		
		secondMatrix = newMatrix (line2, column2);
		assert (secondMatrix != NULL);
    	cout << ENTER_MATRIX;
    	for (int i = 0;i < line2; ++i)
    		for (int j = 0; j < column2; ++j)
    		{
    			cin >> stringForInput;
    			stod (stringForInput, secondMatrix[i][j]);
    		}
    	
    }
    
    while (1)
    {
        //assert(check_matr(firstMatrix,line1,column1,secondMatrix,line2,column2));
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
        
        cin >> stringForInput; 
		stoi (stringForInput, count);
		
        switch (count)
        {
            case 0: 
            {
				return 0;
			}
			
            case 1:
            {
            	cout << ENTER_DIGIT;
            	cin >> stringForInput; 
				stod (stringForInput, number);
				
            	int lineC1 = line1, columnC1 = column1;
            	double **C1 = newMatrix (lineC1, columnC1);
            	
				C1 = mulNum (firstMatrix, line1, column1, number);
				show (C1, lineC1, columnC1);
				delMatr (C1, lineC1);
				
				break;
			}
			
            case 2:
            {
				if (column1 != line2)
					cout << endl << FALSE_DEMENSION << endl; 
				else
				{
					double **C;
					int lineC = line1, columnC = column2;
					
					C = multiplication (firstMatrix, secondMatrix, line1, column1, line2, column2);
					show (C, lineC, columnC);
					delMatr (C, lineC);
				}
				
				break;
			}
			
            case 3:
            {
            	int lineC2 = column1, columnC2 = line1;
            	double **C2 = newMatrix (lineC2, columnC2);
            	
				C2 = trans (firstMatrix, line1, column1);
				show (C2, lineC2, columnC2);
				delMatr (C2, lineC2);
				
				break;
			}
			
            case 4:
	        {
	  	    //works for 'firstMatrix' matrix
	            if(line1!=column1) 
				    cout << FALSE_SIZE << endl;
                else
		            cout << DETERMINANT_IS << determinate (firstMatrix, line1) << endl;
		            
	            break;
	        }
	        
	        case 5:
	        {
	            int lineC2 = column1, columnC2 = line1;
            	double **C2 = newMatrix (lineC2, columnC2);
            	
		        C2 = sum (firstMatrix, secondMatrix, line1, column1, line2, column2);
		        show (C2, lineC2, columnC2);
		        delMatr (C2, lineC2);
		        
				break;
			}


            case 6:
            {
            	typeMatr (firstMatrix, line1, column1);
				break;
            }
            
            case 7: break;
            
            case 8:
            {
          	    if ( line1 != column1) 
				    cout << FALSE_SIZE << endl;
          	    else
          	        obrMatrix(firstMatrix,line1);
          	        
                break;	
            }
			  
			case 9:
			{
				cout << RANK_IS << rank(firstMatrix, line1, column1) << endl;
				break;
			}				   
					       		
            default: 
	            cout << FALSE_COMMAND << endl;
				
        }
        cout << SAVE_OR_NOT;
        char c;
        cin >> c;
        if (c != 'y')
        {
        	cout << ENTER_AMOUNT;
            cin >> k;
            
            if (k == 1)
            {
                delMatr (firstMatrix, line1);
            	cout << ENTER_SIZE;
            	cin >> stringForInput; 
				stoi (stringForInput, line1);
    	        cin >> stringForInput; 
				stoi (stringForInput, column1);
                
            	firstMatrix = newMatrix (line1, column1);
            	assert (firstMatrix != NULL);
            	
    	        cout << ENTER_MATRIX;
    	        for (int i = 0; i < line1; ++i)
    		        for (int j = 0; j < column1; ++j)
    		        {
    			        cin >> stringForInput;
    			        stod (stringForInput, firstMatrix[i][j]);
    		        }
            }
            else
            {
                delMatr (firstMatrix, line1);
    	        cout << ENTER_SIZE << FIRST_MATRIX;
            	cin >> stringForInput; 
				stoi (stringForInput, line1);
    	        cin >> stringForInput; 
				stoi (stringForInput, column1);
				
            	firstMatrix = newMatrix (line1, column1);
            	assert (firstMatrix != NULL);
	
            	cout << ENTER_MATRIX;
            	for (int i = 0; i < line1; ++i)
    		        for (int j = 0; j < column1; ++j)
    		        {
    			        cin >> stringForInput;
    			        stod (stringForInput, firstMatrix[i][j]);
    		        }
    		        
    			delMatr (secondMatrix, line2);
            	cout << ENTER_SIZE << SECOND_MATRIX;
            	cin >> stringForInput; 
				stoi(stringForInput, line2);
    	        cin >> stringForInput; 
				stoi (stringForInput, column2);
                
	        	secondMatrix = newMatrix (line2, column2);
	        	assert (secondMatrix != NULL);
	        	
    	        cout << ENTER_MATRIX;
    	        for (int i = 0; i < line2; ++i)
            		for (int j = 0; j < column2; ++j)
    	        	{
    			        cin >> stringForInput;
    			        stod (stringForInput, secondMatrix[i][j]);
    		        }
            }
		}
    }
    
    delMatr (firstMatrix, line1);
    delMatr (secondMatrix, line2); 
    
    system("pause");
	 
    return 0;
}
