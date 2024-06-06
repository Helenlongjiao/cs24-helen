#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
  int x;
  int y;
  int z;

  int score;

  Point() {}
  Point(int x, int y, int z): x(x), y(y), z(z) {score = 0;}

public:
  bool operator==(const Point & other) const;
  bool operator!=(const Point & other) const;
  bool operator> (const Point & other) const;
  bool operator< (const Point & other) const;
};

std::istream& operator >> (std::istream& stream, Point& point);
std::ostream& operator << (std::ostream& stream, const Point& point);

#endif
