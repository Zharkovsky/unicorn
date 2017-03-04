#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int line1, line2, column1, column2;
	float number;   					// число для умножения 
	
	float ** A = new float *[line1];
	float ** B = new float *[line2];
		
	for (int i = 0; i < line1 ; i++)
		A[i] = new float [column1];
		
	for (int i = 0; i < line2 ; i++)
		B[i] = new float [column2];
		
	return 0;
}
