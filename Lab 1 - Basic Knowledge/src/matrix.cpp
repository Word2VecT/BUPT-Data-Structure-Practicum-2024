#include "matrix.h"
#include <iomanip>

void matrix_init(int **&matrix) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      std::cin >> matrix[i][j];
    }
  }
}

void matrix_print(int** matrix) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      std::cout << std::setw(3) << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void matrix_add(int** matrix1, int** matrix2, int **&result) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void matrix_sub(int** matrix1, int** matrix2, int **&result) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}