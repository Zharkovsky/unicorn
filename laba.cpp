#include <iostream>
#include <cstring>
#include <cassert>
#include "functions.cpp"

using namespace std;

double **newmatrix (int line, int column);
double **Sum(double **,double **,int,int,int,int); //A=Sum(B,C,Bn,Bm,Cn,Cm);
double **MulNum(double **,int,int,double); //A=MulNum(B,Bn,Bm,digit)
double **Multiplication(double **,double **,int,int,int,int); //A=Mul(B,C,Bn,Bm,Cn,Cm);
double **Trans(double **,int,int); //A=Trans(A);
//double **Calculate(string); //A=Calculate("(A+B)*C");
double Determinate(double **,int,int); //det=Determinate(A,An,Am);
void   show(double **a, int n,int m);
void   TypeMatr(double **,int,int); //TypeMatr(A,An);
void   obrmatrix(float **A,int n) 

int main()
{
//	srand(time(0));
	int line1, line2, column1, column2;
	double number;   					
	int count = 0;
	
	double ** A ; 
	double ** B ; 
    
    int k;
    cout << "Enter amount of matrix (1 or 2): ";
    cin >> k;
    if (k == 1)
    {
    	cout << "Enter size of matrix (n and m): ";
    	cin >> line1 >> column1;
    	A = newmatrix(line1,column1);
    	assert(A != NULL);
    	cout << "Enter matrix: \n";
    	for (int i = 0; i < line1; i++)
    		for (int j = 0; j < column1; j++)
    			cin >> A[i][j];
    }
    else
    {
    	cout << "Enter size of first matrix (n and m): ";
    	cin >> line1 >> column1;
    	A = newmatrix(line1,column1);
    	assert(A != NULL);
	
    	cout << "Enter matrix: \n";
    	for (int i = 0; i < line1; i++)
    		for (int j = 0; j < column1; j++)
    			cin >> A[i][j];
    			
    	cout << "Enter size of second matrix (n and m): ";
    	cin >> line2 >> column2;
		B = newmatrix(line2,column2);
		assert(B != NULL);
    	cout << "Enter matrix: \n";
    	for (int i = 0; i < line2; i++)
    		for (int j = 0; j < column2; j++)
    			cin >> B[i][j];    	
    }
    
    while(1)
    {
        cout << "Choose the command:" << endl;
        cout << "0.Exit" << endl; //Auoia
        cout << "1.Multiplication of a matrix by number" << endl; //Oiii?aiea iao?eo ia ?enei
        cout << "2.Multiplication of matrixes" << endl; //Oiii?aiea iao?eo
        cout << "3.Transposing" << endl; //O?ainiiie?iaaiea
        cout << "4.To calculate determinant" << endl; //Iin?eoaou ii?aaaeeoaeu
        cout << "5.Sum of two matrix" << endl; //O?ainiiie?iaaiea
        cout << "6.to define a type of a matrix" << endl; //Ii?aaaeeou oei iao?eou
//      cout<<"7.calculation of expressions from a matrix"<< endl; //Iin?eoaou au?a?aiey ec iao?eou
        cout << "8.Invertible matrix" << endl; //iin?eoaou ia?aoio? iao?eoo
        cin >> count;
        switch (count)
        {
            case 0: 
            {
				return 0;
	    }
            case 1:
            {
            	cout << "Enter the digit: ";
            	cin >> number;
            	int lineC1 = line1,columnC1 = column1;
            	double **C1 = newmatrix(lineC1,columnC1);
		C1 = MulNum(A,line1,column1,number);
		show(C1,lineC1,columnC1);
		DelMatr(C1, lineC1);
		break;
	    }
            case 2:
            {
		int lineC = line1,columnC = column2;
            	double **C = newmatrix(lineC,columnC);
		C = Multiplication(A,B,line1,column1,line2,column2);
		show(C,lineC,columnC);
		DelMatr(C, lineC);
		break;
	    }
            case 3:
            {
            	int lineC2 = column1,columnC2 = line1;
            	double **C2 = newmatrix(lineC2,columnC2);
		C2 = Trans(A,line1,column1);
		show(C2,lineC2,columnC2);
		DelMatr(C2, lineC2);
		break;
	    }
            case 4:
	    {
	  	//works for 'A' matrix
	        if(line1 != column1)
	   	cout << "False, size very baaad(not square)" << endl;
              	else
			cout << "Determinant of matrix = " << Determinate(A,line1) << endl;
	    	break;
	    }	  
	    case 5:
	    {
	        int lineC2 = column1,columnC2 = line1;
            	double **C2 = newmatrix(lineC2,columnC2);
		C2 = Sum(A,B,line1,column1,line2,column2);
		show(C2,lineC2,columnC2);
		DelMatr(C2, lineC2);
		break;
            }
            case 6:
            {
            	TypeMatr(A,line1,column1);
				break;
            }
            case 7:
		break;
            case 8:
            {
           	//works for 'A' matrix
          	if(line1 != column1) 
		    cout << "False, size very baaad(not square)" << endl;
          	else
          	    obrmatrix(A,line1);
              	break;	
            }         		
            default: 
            {
            	cout << "False" << endl;
		return 0;
            }				
        }
        
        cout << "Do you want to save matr? (y/n): ";
        char c;
        cin >> c;
        
        if(c != 'y')
        {
        	
            cout << "Enter amount of matrix (1 or 2): ";
            cin >> k;
            if (k == 1)
            {
                DelMatr(A,line1);
            	cout << "Enter size of matrix (n and m): ";
            	cin >> line1 >> column1;
                
            	A = newmatrix(line1,column1);
            	assert(A != NULL);
    	        cout << "Enter matrix: \n";
    	        for (int i = 0; i < line1; i++)
    		        for (int j = 0; j < column1; j++)
    		        	cin >> A[i][j];
            }
            else
            {
                DelMatr(A,line1);
    	        cout << "Enter size of first matrix (n and m): ";
            	cin >> line1 >> column1;
                
            	A = newmatrix(line1,column1);
            	assert(A != NULL);
	
            	cout << "Enter matrix: \n";
            	for (int i = 0; i < line1; i++)
    		        for (int j = 0; j < column1; j++)
    		        	cin >> A[i][j];
    		DelMatr(B,line2);
            	cout << "Enter size of second matrix (n and m): ";
            	cin >> line2 >> column2;
                
	        B = newmatrix(line2,column2);
	        assert(B != NULL);
    	        cout<<"Enter matrix: \n";
    	        for (int i = 0; i < line2; i++)
            		for (int j = 0; j < column2; j++)
    	        		cin >> B[i][j];    	
            }
	}
    }
    
    DelMatr(A,line1);
    DelMatr(B,line2);
    
    return 0;
}