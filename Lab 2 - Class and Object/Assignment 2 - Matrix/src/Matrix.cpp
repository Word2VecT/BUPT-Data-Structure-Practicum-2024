#include "Matrix.h"

Matrix::Matrix(int lines, int rows)
    : lines(lines), rows(rows), data(new int *[lines]) {
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

Matrix::Matrix(const Matrix &other)
    : lines(other.lines), rows(other.rows), data(new int *[other.lines]) {
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

int Matrix::getLines() const { return this->lines; }

int Matrix::getRows() const { return this->rows; }

Matrix &Matrix::operator=(const Matrix &other) {
  if (this == &other) {
    return *this;
  }

  for (int i = 0; i < lines; ++i) {
    delete[] this->data[i];
  }
  delete[] this->data;

  this->lines = other.lines;
  this->rows = other.rows;
  this->data = new int *[other.lines];
  for (int i = 0; i < other.lines; ++i) {
    this->data[i] = new int[other.rows];
    for (int j = 0; j < other.rows; ++j) {
      this->data[i][j] = other.data[i][j];
    }
  }

  return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
  Matrix result(this->lines, this->rows);
  for (int i = 0; i < this->lines; ++i) {
    for (int j = 0; j < this->rows; ++j) {
      result.data[i][j] = this->data[i][j] + other.data[i][j];
    }
  }

  return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
  Matrix result(this->lines, this->rows);
  for (int i = 0; i < this->lines; ++i) {
    for (int j = 0; j < this->rows; ++j) {
      result.data[i][j] = this->data[i][j] - other.data[i][j];
    }
  }

  return result;
}