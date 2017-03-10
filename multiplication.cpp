double ** multiplication(double **A, double **B, int lineA, int columnA, int lineB, int columnB)
{
	double **result = new double *[lineA];
	for (int i = 0; i < lineA; i++)
		result[i] = new double [columnB];
		
	if (columnA != lineB)
		{
			cout << "Dimension error. Try again." << endl;
			return 0;
		}
		
	for (int i = 0; i < lineA; i++)
		for (int j = 0; j < columnB; j++)
			for (int k =0; k < lineB; k++)
				result[i][j] += A[i][k]*B[k][j];
				
	return result;
}

double ** multiplication(double **A, int lineA, int columnA, double k)
{
	double **result = new double *[lineA];
	for (int i = 0; i < lineA; i++)
		result[i] = new double [columnA];
		
	for (int i = 0; i < lineA; i++)
		for (int j = 0; j < columnA; j++)
				result[i][j] = k* A[i][j];
		
	return result;
}
