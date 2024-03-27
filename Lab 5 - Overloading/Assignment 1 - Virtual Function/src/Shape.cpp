#include "Shape.h"
#include <cmath>

Shape::Shape() {
  std::cout << "Class Shape constructor" << std::endl;
  (void)getchar();
}

Shape::~Shape() {
  std::cout << "Class Shape destructor" << std::endl;
  (void)getchar();
}

Circle::Circle(double radius) : radius(radius) {
  std::cout << "Class Circle constructor" << std::endl;
  (void)getchar();
}

Circle::~Circle() {
  std::cout << "Class Circle destructor" << std::endl;
  (void)getchar();
}

double Circle::area() const { return M_PI * radius * radius; }

Rectangle::Rectangle(double width, double height)
    : width(width), height(height) {
  std::cout << "Class Rectangle constructor" << std::endl;
  (void)getchar();
}

Rectangle::~Rectangle() {
  std::cout << "Class Rectangle destructor" << std::endl;
  (void)getchar();
}

double Rectangle::area() const { return width * height; }

Square::Square(double side) : Rectangle(side, side) {
  std::cout << "Class Square constructor" << std::endl;
  (void)getchar();
}

Square::~Square() {
  std::cout << "Class Square destructor" << std::endl;
  (void)getchar();
}
