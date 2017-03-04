double **MulNum(double **A,int n,int m,double digit)
{
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            A[i][j] *= digit;

    return A;
}
