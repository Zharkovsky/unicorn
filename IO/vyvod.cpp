#include <iostream>
#include <iomanip>
#include "../CONSTANTS.cpp"

using namespace std;
void show (double **a, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        	//cout << setw(15) << a[i][j];
        	cout << a[i][j] << " ";
    	cout << endl;
    }
    return;
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
    cout << ENTER_NEW_MATRIX << endl;
}
