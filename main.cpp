#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <string>
#include <iostream>
#include "IO/vyvod.h"
#include "IO/vvod.h"
#include "functions.h"
#include "CONSTANTS.cpp"
#include "Verification.cpp"
using namespace std;

int main()
{

    int line1 = 0, line2 = 0, column1 = 0, column2 = 0;
    double number;
    int command = 0;
    double **firstMatrix;
    double **secondMatrix;

    enterMatr(&firstMatrix, line1, column1, &secondMatrix, line2, column2);

    string stringForInput;

    while (1)
    {
        //assert(check_matr(firstMatrix,line1,column1,secondMatrix,line2,column2));
        system("cls");
        cout << "____________________________________\n";
        cout << FIRST_MATRIX << endl;
        show(firstMatrix, line1, column1);
        cout << "____________________________________\n";
        cout << SECOND_MATRIX << endl;
        show(secondMatrix, line2, column2);
        cout << "____________________________________\n";
		printCommands();
        cout << "____________________________________\n";
        
        cin >> stringForInput;
        stoi (stringForInput, command);
        
        switch (command)
        {
            case EXIT_COMMAND:
            {
                return 0;
            }

            case MULTIPLICATION_BY_DIGIT_COMMAND:
            {
                cout << ENTER_DIGIT;
                cin >> stringForInput;
                stod (stringForInput, number);

                int lineC1 = line1, columnC1 = column1;
                double **C1 = mulNum (firstMatrix, line1, column1, number);
                cout<<RESULT;
                show (C1, lineC1, columnC1);
                delMatr (C1, lineC1);

                break;
            }

            case MULTIPLICATION_2_MATRIX_COMMAND:
            {
                if (!test_multiplication(line1, column1, line2, column2))
                    break;

                double **C;
                int lineC = line1, columnC = column2;

                C = multiplication (firstMatrix, secondMatrix, line1, column1, line2, column2);
                cout<<RESULT;
                show (C, lineC, columnC);
                delMatr (C, lineC);

                break;
            }

            case TRANSPOSING_COMMAND:
            {
                int lineC2 = column1, columnC2 = line1;
                double **C2 = newMatrix (lineC2, columnC2);
                C2 = trans (firstMatrix, line1, column1);
                cout<<RESULT;
                show (C2, lineC2, columnC2);
                delMatr (C2, lineC2);

                break;
            }

            case DETERMINANT_COMMAND:
            {
                //works for 'firstMatrix' matrix
                if (!test_determinant(line1,column1))
                    break;

                cout << DETERMINANT_IS << determinate (firstMatrix, line1) << endl;

                break;
            }

            case MATRIX_SUM_COMMAND:
            {
                if (!test_sum(line1,column1,line2,column2))
                    break;

                int lineC2 = column1, columnC2 = line1;
                double **C2 = newMatrix (lineC2, columnC2);

                C2 = sum (firstMatrix, secondMatrix, line1, column1, line2, column2);
                cout<<RESULT;
                show (C2, lineC2, columnC2);
                delMatr (C2, lineC2);

                break;
            }


            case MATRIX_TYPE_COMMAND:
            {
                typeMatr (firstMatrix, line1, column1);
                break;
            }


            case INVERTIBLE_MATRIX_COMMAND:
            {
                if ( line1 != column1)
                    cout << FALSE_SIZE << endl;
                else
                {
                	cout<<RESULT;
                	obrMatrix(firstMatrix,line1);
				}

                break;
            }

            case MATRIX_RANK_COMMAND:
            {
                cout << RANK_IS << rank(firstMatrix, line1, column1) << endl;
                break;
            }
            
            case ENTER_NEW_MATRIX_COMMAND:
            {
            	enterMatr(&firstMatrix, line1, column1, &secondMatrix, line2, column2);
            	
            	cout << "____________________________________\n";
        		cout << FIRST_MATRIX << endl;
        		show(firstMatrix, line1, column1);
        		cout << "____________________________________\n";
        		cout << SECOND_MATRIX << endl;
        		show(secondMatrix, line2, column2);
        		cout << "____________________________________\n";
        		
        		break;
			}

            default:
                cout << FALSE_COMMAND << endl;

        }

        char c;
        do
        {
            cout << endl << SAVE_OR_NOT << endl;
            cin >> c;
            if (c != 'y' && c!= 'n')
                cout << FALSE_COMMAND << endl;
            else
                break;
        }while (1);

        if (c == 'n')
            enterMatr(&firstMatrix, line1, column1, &secondMatrix, line2, column2);
    }

    delMatr (firstMatrix, line1);
    delMatr (secondMatrix, line2);

    system("pause");

    return 0;
}
