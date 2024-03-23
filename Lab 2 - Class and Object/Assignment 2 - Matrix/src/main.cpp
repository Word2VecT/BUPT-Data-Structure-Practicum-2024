#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int lines, int rows) : lines(lines), rows(rows), data(new int*[lines]) {
	for (int i = 0; i < lines; ++i) {
		this->data[i] = new int[rows];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < lines; ++i) {
		delete[] this->data[i];
	}
	delete[] this->data;
}

Matrix::Matrix(const Matrix& other) : lines(other.lines), rows(other.rows), data(new int*[other.lines]) {
	for (int i = 0; i < other.lines; ++i) {
		this->data[i] = new int[other.rows];
		for (int j = 0; j < other.rows; ++j) {
			this->data[i][j] = other.data[i][j];
		}
	}
}

void Matrix::input() {
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < rows; ++j) {
			std::cin >> this->data[i][j];
		}
	}
}

void Matrix::output() const {
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < rows; ++j) {
			std::cout << this->data[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int Matrix::getLines() const {
    return this->lines;
}

int Matrix::getRows() const {
    return this->rows;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < lines; ++i) {
        delete[] this->data[i];
    }
    delete[] this->data;

    this->lines = other.lines;
    this->rows = other.rows;
    this->data = new int*[other.lines];
    for (int i = 0; i < other.lines; ++i) {
        this->data[i] = new int[other.rows];
        for (int j = 0; j < other.rows; ++j) {
            this->data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(this->lines, this->rows);
    for (int i = 0; i < this->lines; ++i) {
        for (int j = 0; j < this->rows; ++j) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(this->lines, this->rows);
    for (int i = 0; i < this->lines; ++i) {
        for (int j = 0; j < this->rows; ++j) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }

    return result;
}

void getMatrixParameters(int& lines, int& rows) {
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
