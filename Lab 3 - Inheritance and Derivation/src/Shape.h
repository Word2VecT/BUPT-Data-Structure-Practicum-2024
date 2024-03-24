#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
  Shape();
  virtual ~Shape();
  virtual double area() const = 0;
};

class Circle : public Shape {
private:
  double radius;

public:
  explicit Circle(double radius);
  ~Circle() override;
  double area() const override;
};

class Rectangle : public Shape {
private:
  double width;
  double height;

public:
  Rectangle(double width, double height);
  ~Rectangle() override;
  double area() const override;
};

class Square : public Rectangle {
public:
  explicit Square(double side);
  ~Square() override;
};

#endif
