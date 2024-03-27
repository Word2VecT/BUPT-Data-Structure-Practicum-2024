#include "Point.h"

Point::Point(int coord_x, int coord_y) : coord_x(coord_x), coord_y(coord_y) {}

int Point::getX() const { return coord_x; }

int Point::getY() const { return coord_y; }

Point &Point::operator++() {
  ++coord_x;
  ++coord_y;
  return *this; // 返回自身的引用
}

// 后缀自增
Point Point::operator++(int) {
  Point temp = *this; // 保存当前状态
  ++(*this);          // 调用前缀自增
  return temp;        // 返回未增加前的状态
}

// 前缀自减
Point &Point::operator--() {
  --coord_x;
  --coord_y;
  return *this; // 返回自身的引用
}

// 后缀自减
Point Point::operator--(int) {
  Point temp = *this; // 保存当前状态
  --(*this);          // 调用前缀自减
  return temp;        // 返回未减少前的状态
}