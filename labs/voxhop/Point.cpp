#include "Point.h"

bool Point::operator==(const Point & other) const{
  if(this->x == other.x && this->y == other.y && this->z == other.z){
    return true;
  }
  else{
    return false;
  }
}

bool Point::operator!=(const Point & other) const{
  if(this->x != other.x || this->y != other.y || this->z != other.z){
    return true;
  }
  else{
    return false;
  }
}

bool Point::operator>(const Point & other) const{
  int parsedPoint = this -> x * 100 + this -> y * 10 + this -> z;
  int otherPoint = other.x * 100 + other.y * 10 + other.z;
  return parsedPoint > otherPoint;
}

bool Point::operator<(const Point & other) const{
  int parsedPoint = this -> x * 100 + this -> y * 10 + this -> z;
  int otherPoint = other. x * 100 + other.y * 10 + other.z;
  return parsedPoint < otherPoint;
}


std::istream& operator >> (std::istream& stream, Point& point) {
  return stream >> point.x >> point.y >> point.z;
}

std::ostream& operator << (std::ostream& stream, const Point& point) {
  return stream << '(' << point.x << ", " << point.y << ", " << point.z << ')';
}