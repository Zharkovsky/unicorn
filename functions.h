#ifndef functions
#define functions
#include "functions.cpp"
double **newMatrix (int line, int column);
double **mulNum (double **firstMatrix, int n, int m, double digit);
double determinate (double **a, int size);
double **sum (double **firstMatrix, double **secondMatrix, int An, int Am, int Bn, int Bm);
double **trans (double **firstMatrix, int n, int m);
double **multiplication (double **firstMatrix, double **secondMatrix, int lineA, int columnA, int lineB, int columnB);
void Random (double **firstMatrix, int lineA, int columnA);
void delMatr (double **firstMatrix, int lineA);
void obrMatrix (double **firstMatrix, int n);
int rank (double **matrix, int i, int j);
void typeMatr (double **firstMatrix, int n, int m);
#endif
