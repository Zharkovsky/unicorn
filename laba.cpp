#include <iostream>
#include <cstring>

using namespace std;

double **Sum(double **,double **,int,int,int,int); //A=Sum(B,C,Bn,Bm,Cn,Cm);
double **MulNum(double **,int,int,double); //A=MulNum(B,Bn,Bm,digit)
double **Mul(double **,double **,int,int,int,int); //A=Mul(B,C,Bn,Bm,Cn,Cm);
double **Trans(double **,int,int); //A=Trans(A);
double **Calculate(string); //A=Calculate("(A+B)*C");
double Determinate(double **,int,int); //det=Determinate(A,An,Am);
void TypeMatr(double **,int,int); //TypeMatr(A,An);

int main()
{
	srand(time(0));
	int line1, line2, column1, column2;
	double number;   					// ЛњГ‹Г’ГЋГ“ вЂ°ГЋЛ‡ Г›ГЏГЊГ“ГЉГ‚ГЊГ‹Л‡ 
	
	double ** A = new double *[line1];
	double ** B = new double *[line2];
		
	for (int i = 0; i < line1 ; i++)
		A[i] = new double [column1];
		
	for (int i = 0; i < line2 ; i++)
		B[i] = new double [column2];
    
    int count=1;
    while(count)
    {
        cout<<"Choose the command:"<<endl;
        cout<<"0.Exit"<<endl; //Выход
        cout<<"1.Multiplication of a matrix by number"<<endl; //Умножение матриц на число
        cout<<"2.Multiplication of matrixes"<<endl; //Умножение матриц
        cout<<"3.Transposing"<<endl; //Транспонирование
        cout<<"4.to calculate determinant"<< endl; //Посчитать определитель
        cout<<"5.to define a type of a matrix"<<endl; //Определить тип матрицы
        cout<<"6.calculation of expressions from a matrix"<< endl; //Посчитать выражения из матрицы
        cin>>count;
        switch (count)
        {
            case 0:break;
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:break;
            case 5:break;
            case 6:break;
            default: cout<<"False"<<endl;count=0; break;
        }
    }
    
    return 0;
}
