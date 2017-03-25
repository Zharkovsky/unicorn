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
void show(double **a, int n,int m);
void TypeMatr(double **,int,int); //TypeMatr(A,An);

int main()
{
//	srand(time(0));
	int line1, line2, column1, column2;
	double number;   					// ËœÃ‹Ã’ÃŽÃ“ â€°ÃŽË‡ Ã›ÃÃŒÃ“ÃŠÃ‚ÃŒÃ‹Ë‡ 
	int count = 0;
	
	double ** A ; 
	double ** B ; 
/*	double ** A = new double *[line1];
	double ** B = new double *[line2];
		
	for (int i = 0; i < line1 ; i++)
		A[i] = new double [column1];
		
	for (int i = 0; i < line2 ; i++)
		B[i] = new double [column2];
*/
    
    int k;
    cout<<"Enter amount of matrix (1 or 2): ";
    cin>>k;
    if (k == 1)
    {
    	cout<<"Enter size of matrix (n and m): ";
    	cin>>line1>>column1;
    	A = newmatrix(line1,column1);
    	assert(A != NULL);
    	cout<<"Enter matrix: \n";
    	for (int i=0;i<line1;i++)
    		for (int j=0;j<column1;j++)
    			cin>>A[i][j];
    }
    else
    {
    	cout<<"Enter size of first matrix (n and m): ";
    	cin>>line1>>column1;
    	A = newmatrix(line1,column1);
    	assert(A != NULL);
	
    	cout<<"Enter matrix: \n";
    	for (int i=0;i<line1;i++)
    		for (int j=0;j<column1;j++)
    			cin>>A[i][j];
    			
    	cout<<"Enter size of second matrix (n and m): ";
    	cin>>line2>>column2;
		B = newmatrix(line2,column2);
		assert(B != NULL);
    	cout<<"Enter matrix: \n";
    	for (int i=0;i<line2;i++)
    		for (int j=0;j<column2;j++)
    			cin>>B[i][j];
    	
    }
    
    while(1)
    {
        cout<<"Choose the command:"<<endl;
        cout<<"0.Exit"<<endl; //Âûõîä
        cout<<"1.Multiplication of a matrix by number"<<endl; //Óìíîæåíèå ìàòðèö íà ÷èñëî
        cout<<"2.Multiplication of matrixes"<<endl; //Óìíîæåíèå ìàòðèö
        cout<<"3.Transposing"<<endl; //Òðàíñïîíèðîâàíèå
        cout<<"4.to calculate determinant"<< endl; //Ïîñ÷èòàòü îïðåäåëèòåëü
        cout<<"5.Sum of two matrix"<<endl; //Òðàíñïîíèðîâàíèå
        cout<<"6.to define a type of a matrix"<<endl; //Îïðåäåëèòü òèï ìàòðèöû
//      cout<<"7.calculation of expressions from a matrix"<< endl; //Ïîñ÷èòàòü âûðàæåíèÿ èç ìàòðèöû
        cout<<"8.Invertible matrix"<<endl; //ïîñ÷èòàòü îáðàòíóþ ìàòðèöó
        cin>>count;
        switch (count)
        {
            case 0: 
            {
				return 0;
			}
            case 1:
            {
            	cout<<"Enter the digit: ";
            	cin>>number;
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
		//ïðîâåðêà äëÿ êàêîé ìàòðèöû èùåì A èëè B(òóò äëÿ A)
	          if(line1!=column1) cout<<"False, size very baaad(not square)"<<endl;
                    else
		cout<<"Determinant of matrix = "<<Determinate(A,line1)<<endl;
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













//          case 5:break;
        case 6:{
//          case 8:îïðåäåëèòü äëÿ êàêîé ìàòðèöû 1 èëè 2 èñêàòü, îïðåäåëèòü êâàäðàòíàÿ îíà èëè íåò, âûïîëíèòü ô-þ obr            case 6:{
            	TypeMatr(A,line1,column1);
				break;}		
          default: 
				cout<<"False"<<endl;
				return 0;
        }
        cout<<"Do you want to save matr? (y/n): ";
        char c;
        cin>>c;
        if(c!='y')
        {
        	
        	cout<<"Enter amount of matrix (1 or 2): ";
            cin>>k;
            if (k == 1)
            {
                DelMatr(A,line1);
            	cout<<"Enter size of matrix (n and m): ";
            	cin>>line1>>column1;
                
            	A = newmatrix(line1,column1);
            	assert(A != NULL);
    	        cout<<"Enter matrix: \n";
    	        for (int i=0;i<line1;i++)
    		        for (int j=0;j<column1;j++)
    		        	cin>>A[i][j];
            }
            else
            {
                DelMatr(A,line1);
    	        cout<<"Enter size of first matrix (n and m): ";
            	cin>>line1>>column1;
                
            	A = newmatrix(line1,column1);
            	assert(A != NULL);
	
            	cout<<"Enter matrix: \n";
            	for (int i=0;i<line1;i++)
    		        for (int j=0;j<column1;j++)
    		        	cin>>A[i][j];
    			DelMatr(B,line2);
            	cout<<"Enter size of second matrix (n and m): ";
            	cin>>line2>>column2;
                
	        	B = newmatrix(line2,column2);
	        	assert(B != NULL);
    	        cout<<"Enter matrix: \n";
    	        for (int i=0;i<line2;i++)
            		for (int j=0;j<column2;j++)
    	        		cin>>B[i][j];
    	
            }
		}
    }
    
    DelMatr(A,line1);
    DelMatr(B,line2);
    
    return 0;
}
