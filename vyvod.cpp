#include <iostream>
#include <iomanip>
using namespace std;
void show (double **a, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        	cout << setw(15) << a[i][j];
    	cout << endl;
    }
 return;
}
