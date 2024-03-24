#include "Circle.h"
#include <cmath>

Point::Point(int coord_x, int coord_y) : coord_x(coord_x), coord_y(coord_y) {
  std::cout << "Class Point constructor" << std::endl;
  (void)getchar();
}

Point::~Point() {
  std::cout << "Class Point destructor" << std::endl;
  (void)getchar();
}

int Point::getX() const { return this->coord_x; }

int Point::getY() const { return this->coord_y; }

double Point::distance(const Point &other) const {
  return std::sqrt(
      static_cast<double>(std::pow((this->coord_x - other.getX()), 2)) +
      std::pow((this->coord_y - other.getY()), 2));
}

Circle::Circle(const CircleParams &parameter)
    : center(parameter.center_x, parameter.center_y), radius(parameter.radius) {
  std::cout << "Class Circle constructor" << std::endl;
  (void)getchar();
}

Circle::~Circle() {
  std::cout << "Class Circle destructor" << std::endl;
  (void)getchar();
}

Point Circle::getCenter() const { return this->center; }

int Circle::getRadius() const { return this->radius; }