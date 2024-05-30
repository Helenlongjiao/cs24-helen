#ifndef VOXMAP_H
#define VOXMAP_H


#include <istream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

#include "Point.h"
#include "Route.h"

class VoxMap {
  int width, depth, height;
  std::vector<std::vector<std::vector<bool>>> voxels;

  bool isValid(const Point& point);
  bool isWalkable(const Point& point);
  bool isInBounds(const Point& point);

public:
  VoxMap(std::istream& stream);
  ~VoxMap();
  Route route(Point src, Point dst);
};


#endif
