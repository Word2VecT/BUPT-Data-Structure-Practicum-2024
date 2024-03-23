#include "Circle.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

Point::Point(int coord_x, int coord_y) : coord_x(coord_x), coord_y(coord_y) {
    std::cout << "Class Point constructor" << std::endl;
}

Point::~Point() {
    std::cout << "Class Point destructor" << std::endl;
}

int Point::getX() const {
    return this->coord_x;
}

int Point::getY() const {
    return this->coord_y;
}

double Point::distance (const Point& other) const {
    return std::sqrt(static_cast<double>(std::pow((this->coord_x - other.getX()), 2)) + std::pow((this->coord_y - other.getY()), 2));
}

Circle::Circle(const CircleParams& parameter) : center(parameter.center_x, parameter.center_y), radius(parameter.radius) {
    std::cout << "Class Circle constructor" << std::endl;
}

Circle::~Circle() {
    std::cout << "Class Circle destructor" << std::endl;
}

Point Circle::getCenter() const {
    return this->center;
}

int Circle::getRadius() const {
    return this->radius;
}

void readCircleParameters(CircleParams& parameter) {
    parameter.center_x = 0;
    parameter.center_y = 0;
    parameter.radius = 0;

    std::cout << "Input the center coordinate of Circle, like \"x y\" and nothing for default 0 0" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    
    if (!input.empty()) {
        std::istringstream stream(input);
        stream >> parameter.center_x >> parameter.center_y;
    }
    std::cout << "Input the radius of Circle" << std::endl;
    std::cin >> parameter.radius;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int main() {
    CircleParams parameter{};

    readCircleParameters(parameter);
    Circle const circle1(parameter);
    readCircleParameters(parameter);
    Circle const circle2(parameter);

    double const center_distance = circle1.getCenter().distance(circle2.getCenter());
    if (center_distance > (circle1.getRadius() + circle2.getRadius()) || center_distance < std::abs(circle1.getRadius() - circle2.getRadius())) {
        std::cout << "\033[1mThe two circles do not intersect\033[0m"
                  << std::endl;
    } else {
        std::cout << "\033[1mThe two circles intersect\033[0m" << std::endl;
    }

    return 0;
}
