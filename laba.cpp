#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int line1, line2, column1, column2;
	double number;   					// ˜ËÒÎÓ ‰Îˇ ÛÏÌÓÊÂÌËˇ 
	
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
        cout<<"0.Exit"<<endl; //�����
        cout<<"1.Multiplication of a matrix by number"<<endl; //��������� ������ �� �����
        cout<<"2.Multiplication of matrixes"<<endl; //��������� ������
        cout<<"3.Transposing"<<endl; //����������������
        cout<<"4.to calculate determinant"<< endl; //��������� ������������
        cout<<"5.to define a type of a matrix"<<endl; //���������� ��� �������
        cout<<"6.calculation of expressions from a matrix"<< endl; //��������� ��������� �� �������
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
