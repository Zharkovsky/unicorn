#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include "functions.cpp"

using namespace std;

double **newMatrix (int line, int column);
double **sum (double **, double **, int, int, int, int); //A=Sum(B,C,Bn,Bm,Cn,Cm);
double **mulNum (double **, int, int, double); //A=MulNum(B,Bn,Bm,digit)
double **multiplication (double **, double **, int, int, int, int); //A=Mul(B,C,Bn,Bm,Cn,Cm);
double **trans (double **, int, int); //A=Trans(A);
//double **Calculate (string); //A=Calculate("(A+B)*C");
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
	double **A; 
	double **B; 
	cout<<"1.To enter 2 the matrixes 2.Automatic generation of a matrix:"<<endl;
	int i=0;
	cin>>i;
	cout<<"line 1,column 1 for first matrix A"<<endl;
	cin>>line1;
	cin>>column1;
	cout<<"line 1,column 1 for second matrix B"<<endl;
	cin>>line2;
	cin>>column2;
	switch(i)
	{
	 case 1:
	{ 		
	double **A = new double *[line1];
	double **B = new double *[line2];
		
	for (int i = 0; i < line1 ; ++i)
		A[i] = new double [column1];
		
	for (int i = 0; i < line2 ; ++i)
		B[i] = new double [column2];
          cout<<"Enter first matrix A:"<<endl;
          for(int i=0; i<line1;++i)
           for(int j=0;j<column1;j++)
            cin>>A[i][j];
          cout<<"Enter second matrix B:"<<endl;
          for(int i=0; i<line2;++i)
           for(int j=0;j<column2;j++)
            cin>>B[i][j]; 	 	
         	break;
	}
	 case 2:
	{
	  double **A=newMatrix(line1,column1);
	  double **B=newMatrix(line2,column2);	
	  Random(A,line1,column1);
	  Random(B,line2,column2);
	  cout<<"first matrix A:"<<endl;
	  show (A,line1,column1);
	  cout<<"second matrix B:"<<endl;
	  show (B,line2,column2);
	break;
	 }
	default: return 0;
	}

    string s; //for input
    int k = 1;
    cout << "Enter amount of matrix (1 or 2): ";
    cin >> s;
    stoi (s, k);
    
    if (k == 1)
    {
    	cout << "Enter size of matrix (n and m): ";
    	cin >> s; 
		stoi (s, line1);
    	cin >> s; 
		stoi (s, column1);
		
    	A = newMatrix (line1, column1);
    	assert (A != NULL);
    	
    	cout << "Enter matrix: \n";
    	for (int i = 0; i < line1; ++i)
    		for (int j = 0; j < column1; ++j)
    		{
    			cin >> s;
    			stod (s, A[i][j]);
    		}
    }
    else
    {
    	if (k > 2) 
			cout << "Max number of matrix = 2. Let's work with 2 matrix!" << endl;
    	cout << "Enter size of first matrix (n and m): ";
    	cin >> s; 
		stoi (s, line1);
    	cin >> s; 
		stoi (s, column1);
		
    	A = newMatrix (line1, column1);
    	assert (A != NULL);
	
    	cout << "Enter matrix: \n";
    	for (int i = 0;i < line1; ++i)
    		for (int j = 0;j < column1; ++j)
    		{
    			cin >> s;
    			stod (s, A[i][j]);
    		}
    			
    	cout << "Enter size of second matrix (n and m): ";
    	cin >> s; 
		stoi (s, line2);
    	cin >> s; 
		stoi (s, column2);
		
		B = newMatrix (line2, column2);
		assert (B != NULL);
    	cout << "Enter matrix: \n";
    	for (int i = 0;i < line2; ++i)
    		for (int j = 0; j < column2; ++j)
    		{
    			cin >> s;
    			stod (s, B[i][j]);
    		}
    	
    }
    
    while (1)
    {
        //assert(check_matr(A,line1,column1,B,line2,column2));
        cout << "Choose the command:" << endl;
        cout << "0.Exit" << endl;
        cout << "1.Multiplication of a matrix by number" << endl;
        cout << "2.Multiplication of matrixes" << endl;
        cout << "3.Transposing" << endl;
        cout << "4.To calculate determinant" << endl;
        cout << "5.Sum of two matrix" << endl;
        cout << "6.to define a type of a matrix" << endl;
//      cout<<"7.calculation of expressions from a matrix"<< endl;
        cout << "8.Invertible matrix" << endl;
        cout << "9.The rank of the matrix " << endl;
        
        cin >> s; 
		stoi (s, count);
		
        switch (count)
        {
            case 0: 
            {
				return 0;
			}
			
            case 1:
            {
            	cout << "Enter the digit: ";
            	cin >> s; 
				stod (s, number);
				
            	int lineC1 = line1, columnC1 = column1;
            	double **C1 = newMatrix (lineC1, columnC1);
            	
				C1 = mulNum (A, line1, column1, number);
				show (C1, lineC1, columnC1);
				delMatr (C1, lineC1);
				
				break;
			}
			
            case 2:
            {
				if (column1 != line2)
					cout << endl << " Error in dimension. Try entering other matrices." << endl; 
				else
				{
					double **C;
					int lineC = line1, columnC = column2;
					
					C = multiplication (A, B, line1, column1, line2, column2);
					show (C, lineC, columnC);
					delMatr (C, lineC);
				}
				
				break;
			}
			
            case 3:
            {
            	int lineC2 = column1, columnC2 = line1;
            	double **C2 = newMatrix (lineC2, columnC2);
            	
				C2 = trans (A, line1, column1);
				show (C2, lineC2, columnC2);
				delMatr (C2, lineC2);
				
				break;
			}
			
            case 4:
	        {
	  	    //works for 'A' matrix
	            if(line1!=column1) 
				    cout << "False, size very baaad(not square)" << endl;
                else
		            cout << "Determinant of matrix = " << determinate (A, line1) << endl;
		            
	            break;
	        }
	        
	        case 5:
	        {
	            int lineC2 = column1, columnC2 = line1;
            	double **C2 = newMatrix (lineC2, columnC2);
            	
		        C2 = sum (A, B, line1, column1, line2, column2);
		        show (C2, lineC2, columnC2);
		        delMatr (C2, lineC2);
		        
				break;
			}


            case 6:
            {
            	typeMatr (A, line1, column1);
				break;
            }
            
            case 7: break;
            
            case 8:
            {
          	    if ( line1 != column1) 
				    cout << "False, size very baaad(not square)" << endl;
          	    else
          	        obrMatrix(A,line1);
          	        
                break;	
            }
			  
			case 9:
			{
				cout << "Rank = " << rank(A, line1, column1) << endl;
				break;
			}				   
					       		
            default: 
	            cout << "False" << endl;
				return 0;
				
        }
        cout << "Do you want to save matr? (y/n): ";
        char c;
        cin >> c;
        if (c != 'y')
        {
        	cout << "Enter amount of matrix (1 or 2): ";
            cin >> k;
            
            if (k == 1)
            {
                delMatr (A, line1);
            	cout << "Enter size of matrix (n and m): ";
            	cin >> s; 
				stoi (s, line1);
    	        cin>>s; 
				stoi (s, column1);
                
            	A = newMatrix (line1, column1);
            	assert (A != NULL);
            	
    	        cout << "Enter matrix: \n";
    	        for (int i = 0; i < line1; ++i)
    		        for (int j = 0; j < column1; ++j)
    		        {
    			        cin >> s;
    			        stod (s, A[i][j]);
    		        }
            }
            else
            {
                delMatr (A, line1);
    	        cout << "Enter size of first matrix (n and m): ";
            	cin >> s; 
				stoi (s, line1);
    	        cin >> s; 
				stoi (s, column1);
				
            	A = newMatrix (line1, column1);
            	assert (A != NULL);
	
            	cout<<"Enter matrix: \n";
            	for (int i = 0; i < line1; ++i)
    		        for (int j = 0; j < column1; ++j)
    		        {
    			        cin >> s;
    			        stod (s, A[i][j]);
    		        }
    		        
    			delMatr (B, line2);
            	cout << "Enter size of second matrix (n and m): ";
            	cin >> s; 
				stoi(s, line2);
    	        cin >> s; 
				stoi (s, column2);
                
	        	B = newMatrix (line2, column2);
	        	assert (B != NULL);
	        	
    	        cout << "Enter matrix: \n";
    	        for (int i = 0;i < line2; ++i)
            		for (int j = 0; j < column2; ++j)
    	        	{
    			        cin >> s;
    			        stod (s, B[i][j]);
    		        }
            }
		}
    }
    
    delMatr (A, line1);
    delMatr (B, line2); 
	 
    return 0;
}
