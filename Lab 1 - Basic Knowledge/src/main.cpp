#include "matrix.h"
#include <iomanip>
#include <algorithm>
#include <iostream>

void matrix_init(int**& matrix) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			std::cin >> matrix[i][j];
		}
	}
}

void matrix_print(int** const matrix) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void matrix_add(int** const matrix1, int** const matrix2, int**& result) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

void matrix_sub(int** const matrix1, int** const matrix2, int**& result) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}

int main() {
    int** A1 = new int*[ROWS];
	int** A2 = new int*[ROWS];
	int** A3 = new int*[ROWS];

	for (int i = 0; i < ROWS; ++i) {
		A1[i] = new int[COLS];
		A2[i] = new int[COLS];
		A3[i] = new int[COLS];
	}

	std::cout << "Enter matrix A1:" << std::endl;
	matrix_init(A1);
	std::cout << "Enter matrix A2:" << std::endl;
	matrix_init(A2);

	matrix_add(A1, A2, A3);
	std::cout << "A1 + A2:" << std::endl;
	matrix_print(A3);
	matrix_sub(A1, A2, A3);
	std::cout << "A1 - A2:" << std::endl;
	matrix_print(A3);

	for (int i = 0; i < ROWS; ++i) {
		delete[] A1[i];
		delete[] A2[i];
		delete[] A3[i];
	}
	delete[] A1;
	delete[] A2;
	delete[] A3;

	return 0;
}
