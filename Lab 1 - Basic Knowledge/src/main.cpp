#include "matrix.h"

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
