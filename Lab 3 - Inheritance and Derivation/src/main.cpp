#include "Shape.h"
#include <limits>

int main() {
  while (true) {
    std::cout
        << "What Shape do you want to create? (1 - Circle, 2 - Rectangle, "
           "3 - Square, default - EXIT)"
        << std::endl;
    int choice = 0;
    std::cin >> choice;

    switch (choice) {
    case 1: {
      double radius = NAN;
      std::cout << "Enter the radius of the circle: ";
      std::cin >> radius;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      Circle const circle(radius);
      std::cout << "The area of the circle is: " << circle.area() << std::endl;
      break;
    }
    case 2: {
      double width = NAN;
      double height = NAN;
      std::cout << "Enter the width of the rectangle: ";
      std::cin >> width;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter the height of the rectangle: ";
      std::cin >> height;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      Rectangle const rectangle(width, height);
      std::cout << "The area of the rectangle is: " << rectangle.area()
                << std::endl;
      break;
    }
    case 3: {
      double side = NAN;
      std::cout << "Enter the side of the square: ";
      std::cin >> side;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      Square const square(side);
      std::cout << "The area of the square is: " << square.area() << std::endl;
      break;
    }
    default:
      return 0;
    }
  }
}
