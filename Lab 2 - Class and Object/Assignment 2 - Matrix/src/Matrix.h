#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
	int lines;
	int rows;
    int **data;

public:
	Matrix(int lines, int rows);
	~Matrix();
	Matrix(const Matrix &other);

    void input();
    void output() const;
    [[nodiscard]] int getLines() const;
    [[nodiscard]] int getRows() const;

    Matrix& operator=(const Matrix &other);
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
};

#endif 