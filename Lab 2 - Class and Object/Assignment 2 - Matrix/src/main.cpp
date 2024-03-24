#include "Matrix.h"

void getMatrixParameters(int &lines, int &rows) {
  std::cout << "Input the size of Matrix (lines rows)." << std::endl;
  std::cin >> lines >> rows;
  while (lines <= 0 || rows <= 0) {
    std::cout << "Invalid size. Please input again." << std::endl;
    std::cin >> lines >> rows;
  }
}

int main() {
    int lines = 0;
    int rows = 0;
    
    getMatrixParameters(lines, rows);
    Matrix matrix1(lines, rows);
    std::cout << "Input the matrix A1" << std::endl;
    matrix1.input();
    getMatrixParameters(lines, rows);
    Matrix matrix2(lines, rows);
    std::cout << "Input the matrix A2" << std::endl;
    matrix2.input();

    if (matrix1.getLines() != matrix2.getLines() || matrix1.getRows() != matrix2.getRows()) {
        std::cout << "The matrices have different sizes." << std::endl;
    } else {
        Matrix matrix3 = matrix1 + matrix2;
        std::cout << "The sum of the matrices is:" << std::endl;
        matrix3.output();
        matrix3 = matrix1 - matrix2;
        std::cout << "The difference of the matrices is:" << std::endl;
        matrix3.output();
    }

    getMatrixParameters(lines, rows);
    auto* p_matrix1 = new Matrix(lines, rows);
    std::cout << "Input the matrix pA1" << std::endl;
    p_matrix1->input();
    getMatrixParameters(lines, rows);
    auto *p_matrix2 = new Matrix(lines, rows);
    std::cout << "Input the matrix pA2" << std::endl;
    p_matrix2->input();

    if (p_matrix1->getLines() != p_matrix2->getLines() || p_matrix1->getRows() != p_matrix2->getRows()) {
        std::cout << "The matrices have different sizes." << std::endl;
    } else {
        Matrix* p_matrix3 = new Matrix(*p_matrix1 + *p_matrix2);
        std::cout << "The sum of the matrices is:" << std::endl;
        p_matrix3->output();
        *p_matrix3 = *p_matrix1 - *p_matrix2;
        std::cout << "The difference of the matrices is:" << std::endl;
        p_matrix3->output();
        delete p_matrix3;
    }

    delete p_matrix1;
    delete p_matrix2;

    return 0;
}
