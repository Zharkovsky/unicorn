#ifndef CONSTANTS
#define CONSTANTS

#include <string>

using namespace std;

const string ENTER_COMMAND = "Enter command: ";
const string FIRST_MATRIX = "A (first):\n";
const string SECOND_MATRIX = "B (second):\n";
const string YOUR_MATRIX = "1.To enter your matrixes\n";
const string RANDOM_MATRIX = "2.Automatic generation of a matrix:\n";

const string ENTER_SIZE = "Enter size (n and m) for matrix ";
const string ENTER_AMOUNT = "Enter amount of matrix (1 or 2): ";
const string ENTER_MATRIX = "Enter matrix: \n";
const string ENTER_DIGIT = "Enter the digit: ";

const string CHOOSE_COMMAND = "Choose the command:";
const string SAVE_OR_NOT = "Do you want to save matr? (y/n): ";

const string EXIT = "0.Exit";
const string MULTIPLICATION_BY_DIGIT = "1.Multiplication of a matrix by number";
const string MULTIPLICATION_2_MATRIX = "2.Multiplication of matrixes";
const string TRANSPOSING = "3.Transposing";
const string DETERMINANT = "4.To calculate determinant";
const string MATRIX_SUM = "5.Sum of two matrix";
const string MATRIX_TYPE = "6.to define a type of a matrix";
const string INVERTIBLE_MATRIX = "7.Invertible matrix";
const string MATRIX_RANK = "8.The rank of the matrix";

const string DETERMINANT_IS = "Determinant of matrix = ";
const string RANK_IS = "Rank of matrix = ";

const string FALSE_SIZE = "False, size very baaad(not square)";
const string FALSE_COMMAND = "False command. Try again";
const string FALSE_DEMENSION = "Error in dimension.(column of first matrix != line of second matrix)";
const string FALSE_AMOUNT_OF_MATRIX = "Max number of matrix = 2. Let's work with 2 matrix!";

enum chooseCommand {
	EXIT_COMMAND = 0,
	MULTIPLICATION_BY_DIGIT_COMMAND = 1,
	MULTIPLICATION_2_MATRIX_COMMAND = 2,
	TRANSPOSING_COMMAND = 3,
	DETERMINANT_COMMAND = 4,
	MATRIX_SUM_COMMAND = 5,
	MATRIX_TYPE_COMMAND = 6,
	INVERTIBLE_MATRIX_COMMAND = 7,
	MATRIX_RANK_COMMAND = 8
};

enum typeFill{
	YOUR_MATRIX_FILL = 1,
	RANDOM_MATRIX_FILL = 2
};

enum amountMatr{
    oneMatr = 1,
	twoMatr = 2
};

#endif 

