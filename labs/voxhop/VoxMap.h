
#ifndef VOXMAP_H
#define VOXMAP_H

#include <set>
#include <map>
#include <istream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

#include "Point.h"
#include "Route.h"

// class 3DArray {

// };

class VoxMap {
  int           mWidth, mDepth, mHeight;
  std::map<Point, std::set<Point> > mGraph;

  bool isValid(const Point& point);
  bool isWalkable(const Point& point,  std::vector<std::vector<std::vector<bool>>>& temp3Darray);
  bool isInBounds(const Point& point);
  bool hasPath(const Point& src, const Point& dst, std::vector<std::vector<std::vector<bool>>>& temp3Darray);

public:
  VoxMap(std::istream& stream);
  ~VoxMap();
  Route route(Point src, Point dst);
};


#endif
