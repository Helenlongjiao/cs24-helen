
#ifndef VOXMAP_H
#define VOXMAP_H

#include <set>
#include <map>
#include <istream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>
#include <list>
#include <cmath>

#include "Point.h"
#include "Route.h"

struct Compare {
    typedef Point value_type;

    bool operator()(const Point& a, const Point& b) const {
        return a.dis_to_dst > b.dis_to_dst;
    }
};


class VoxMap {
  int           mWidth, mDepth, mHeight;
  std::map<Point, std::set<Point> > mGraph;
  std::vector<std::vector<std::vector<bool>>> temp3Darray;
  std::vector<std::vector<std::vector<int>>> fallCache;

  bool isValid(const Point& point);
  bool isWalkable(const Point& point,  std::vector<std::vector<std::vector<bool>>>& temp3Darray);
  bool isInBounds(const Point& point);
  bool hasPath(const Point& src, const Point& dst, std::vector<std::vector<std::vector<bool>>>& temp3Darray, std::vector<std::vector<std::vector<int>>>& fallCache);

public:
  VoxMap(std::istream& stream);
  ~VoxMap();
  Route route(Point src, Point dst);
};


#endif
