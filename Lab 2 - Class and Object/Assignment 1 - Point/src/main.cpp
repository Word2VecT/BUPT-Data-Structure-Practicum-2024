#include "Circle.h"
#include <limits>
#include <sstream>
#include <string>

void readCircleParameters(CircleParams &parameter) {
  parameter.center_x = 0;
  parameter.center_y = 0;
  parameter.radius = 0;

  std::cout << "Input the center coordinate of Circle, like \"x y\" and "
               "nothing for default 0 0"
            << std::endl;
  std::string input;
  std::getline(std::cin, input);

  if (!input.empty()) {
    std::istringstream stream(input);
    stream >> parameter.center_x >> parameter.center_y;
  }
  std::cout << "Input the radius of Circle" << std::endl;
  std::cin >> parameter.radius;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
