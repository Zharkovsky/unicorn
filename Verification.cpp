#include <iostream>
#include <string>
#include "CONSTANTS.cpp"

bool test_sum (int An, int Am, int Bn, int Bm)
{
	if (An != Bn || Am != Bm) 
    {
    	cout << endl << FALSE_DEMENSION  << endl;
    	return 0;
	}
	
	return 1;
}

bool test_multiplication (int lineA, int columnA, int lineB, int columnB)
{
	if (columnA != lineB)
		{
			cout << endl << FALSE_DEMENSION << endl;
			return 0;
		}
	return 1;
}

