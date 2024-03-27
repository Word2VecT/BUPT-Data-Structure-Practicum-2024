#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
  int coord_x, coord_y;

public:
  Point(int coord_x, int coord_y);

  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;

  // 前缀自增
  Point &operator++();
  // 后缀自增
  Point operator++(int);
  // 前缀自减
  Point &operator--();
  // 后缀自减
  Point operator--(int);
};

#endif