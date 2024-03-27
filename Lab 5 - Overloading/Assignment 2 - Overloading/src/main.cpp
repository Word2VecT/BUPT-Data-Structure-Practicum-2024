#include "Point.h"
#include <iostream>

int main() {
  int coord_x = 0;
  int coord_y = 0;

  std::cout << "Input a point (x y): ";
  std::cin >> coord_x >> coord_y;

  Point point(coord_x, coord_y);

  std::cout << "Point: (" << point.getX() << ", " << point.getY() << ")" << std::endl;
  std::cout << "Point++: "
            << "(" << point.getX() << ", " << point.getY()
            << ") -> Point++.X:" << (point++).getX()
            << ", Point++.Y:" << (point++).getY() << std::endl;
  std::cout << "++Point: "
            << "(" << point.getX() << ", " << point.getY()
            << ") -> ++Point.X:" << (++point).getX()
            << ", ++Point.Y:" << (++point).getY() << std::endl;
  std::cout << "Point--: "
            << "(" << point.getX() << ", " << point.getY()
            << ") -> Point--.X:" << (point--).getX()
            << ", Point--.Y:" << (point--).getY() << std::endl;
  std::cout << "--Point: "
            << "(" << point.getX() << ", " << point.getY()
            << ") -> --Point.X:" << (--point).getX()
            << ", --Point.Y:" << (--point).getY() << std::endl;

  return 0;
}