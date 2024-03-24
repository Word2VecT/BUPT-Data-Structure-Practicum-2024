#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

const int ROWS = 4;
const int COLS = 5;

void matrix_init(int**& matrix);
void matrix_print(int** matrix);
void matrix_add(int **matrix1, int **matrix2, int **&result);
void matrix_sub(int **matrix1, int **matrix2, int **&result);

#endif
