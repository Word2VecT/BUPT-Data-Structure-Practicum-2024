#ifndef MATRIX_H

#define MATRIX_H

const int ROWS = 4;
const int COLS = 5;

void matrix_init(int**& matrix);
void matrix_print(const int** matrix);
void matrix_add(const int **matrix1, const int **matrix2, int **&result);
void matrix_sub(const int **matrix1, const int **matrix2, int **&result);

#endif