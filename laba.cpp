#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int line1, line2, column1, column2;
	float number;   					// ˜ËÒÎÓ ‰Îˇ ÛÏÌÓÊÂÌËˇ 
	
	float ** A = new float *[line1];
	float ** B = new float *[line2];
		
	for (int i = 0; i < line1 ; i++)
		A[i] = new float [column1];
		
	for (int i = 0; i < line2 ; i++)
		B[i] = new float [column2];
    
    int count=1;
    while(count)
    {
        cout<<"Choose the command:"<<endl;
        cout<<"0.Exit"<<endl //выход
        cout<<"1.Multiplication of a matrix by number"<<endl; //умножение матрицы на число
        cout<<"2.Multiplication of matrixes"<<endl; //перемножение матриц
        cout<<"3.Transposing"<<endl; //транспонирование
        cout<<"4.to calculate determinant" //вычисление определителя
        cout<<"5.to define a type of a matrix"<<endl; //определить вил матрицы
        cout<<"6.calculation of expressions from a matrix" //подсчет выражений из матрицы
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
