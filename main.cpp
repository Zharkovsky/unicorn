#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <string>
#include <iostream>
#include "vyvod.h"
#include "functions.cpp"
#include "CONSTANTS.cpp"
using namespace std;

double **newMatrix (int line, int column);
double **sum (double **, double **, int, int, int, int); //A=Sum(B,C,Bn,Bm,Cn,Cm);
double **mulNum (double **, int, int, double); //A=MulNum(B,Bn,Bm,digit)
double **multiplication (double **, double **, int, int, int, int); //A=Mul(B,C,Bn,Bm,Cn,Cm);
double **trans (double **, int, int); //A=Trans(A);
double determinate (double **, int, int); //det=Determinate(A,An,Am);
void typeMatr (double **, int, int); //TypeMatr(A,An);
void obrMatrix (float **, int); 
int rank (double **, int, int); 
void stoi (string inputString, int &k); //input String to int
void stod (string inputString, double &k); //input String to double
//void enterMatr(double ***, int &, int &, double **, int &, int &);
void printCommands();

int main()
{
//	srand(time(0));
	int line1 = 0, line2 = 0, column1 = 0, column2 = 0;
	double number;
	int command = 0;
	double **firstMatrix; 
	double **secondMatrix; 
	
	enterMatr(&firstMatrix, line1, column1, &secondMatrix, line2, column2);

    string stringForInput; //for input
    
    while (1)
    {
        //assert(check_matr(firstMatrix,line1,column1,secondMatrix,line2,column2));
        printCommands();
        
        cin >> stringForInput; 
		stoi (stringForInput, command);
		
        switch (command)
        {
            case EXIT_COMMAND: 
            {
				return 0;
			}
			
            case MULTIPLICATION_BY_DIGIT_COMMAND:
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
			
            case MULTIPLICATION_2_MATRIX_COMMAND:
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
			
            case TRANSPOSING_COMMAND:
            {
            	int lineC2 = column1, columnC2 = line1;
            	double **C2 = newMatrix (lineC2, columnC2);
				C2 = trans (firstMatrix, line1, column1);
				show (C2, lineC2, columnC2);
				delMatr (C2, lineC2);
				
				break;
			}
			
            case DETERMINANT_COMMAND:
	        {
	  	    //works for 'firstMatrix' matrix
	            if(line1!=column1) 
				    cout << FALSE_SIZE << endl;
                else
		            cout << DETERMINANT_IS << determinate (firstMatrix, line1) << endl;
		            
	            break;
	        }
	        
	        case MATRIX_SUM_COMMAND:
	        {
	            int lineC2 = column1, columnC2 = line1;
            	double **C2 = newMatrix (lineC2, columnC2);
            	
		        C2 = sum (firstMatrix, secondMatrix, line1, column1, line2, column2);
		        show (C2, lineC2, columnC2);
		        delMatr (C2, lineC2);
		        
				break;
			}


            case MATRIX_TYPE_COMMAND:
            {
            	typeMatr (firstMatrix, line1, column1);
				break;
            }
            
            
            case INVERTIBLE_MATRIX_COMMAND:
            {
          	    if ( line1 != column1) 
				    cout << FALSE_SIZE << endl;
          	    else
          	        obrMatrix(firstMatrix,line1);
          	        
                break;	
            }
			  
			case MATRIX_RANK_COMMAND:
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
            enterMatr(&firstMatrix, line1, column1, &secondMatrix, line2, column2);
    }
    
    delMatr (firstMatrix, line1);
    delMatr (secondMatrix, line2); 
    
    system("pause");
	 
    return 0;
}
