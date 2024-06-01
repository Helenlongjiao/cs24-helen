#include "VoxMap.h"
#include "Errors.h"

VoxMap::VoxMap(std::istream& stream) {

  // Build Temporary 3D Array
  std::vector<std::vector<std::vector<bool>>> temp3Darray;
  
  stream >> mWidth >> mDepth >> mHeight;
  temp3Darray.resize(mWidth, std::vector<std::vector<bool>>(mDepth, std::vector<bool>(mHeight, false)));

  std::string line = "";

  for (int z = 0; z < mHeight; ++z) {
    std::getline(stream, line);
    if(line.empty()){
      continue;
    }
    for (int y = 0; y < mDepth; ++y) {
      std::getline(stream, line);
      if(line.empty()){
        continue;
      }
      for (int x = 0; x < mWidth / 4; ++x) {
        char hex = line[x];
        // int value = std::stoi(std::string(1, hex), 0, 16);
        int value = 0;
        if (hex >= '0' && hex <= '9') {
            value = hex - '0';  // Convert '0' to '9' to integer 0 to 9
        } else if (hex >= 'A' && hex <= 'F') {
            value = hex - 'A' + 10;  // Convert 'A' to 'F' to integer 10 to 15
        } else if (hex >= 'a' && hex <= 'f') {
            value = hex - 'a' + 10;  // Convert 'a' to 'f' to integer 10 to 15 (for lowercase hex digits)
        } else {
            // Handle error: hex is not a valid hex digit
        }
        for (int i = 0; i < 4; ++i) {
          temp3Darray[x*4 + i][y][z] = (value & (8 >> i)) != 0;
        }
      }
    }
  }

  // Build mGraph from 3D ARR
  for (int x = 0; x < mWidth; ++x) {
    for (int y = 0; y < mDepth; ++y) {
      for (int z = 1; z < mHeight; ++z) {
        Point currPt(x, y, z);
        if (!isWalkable(currPt, temp3Darray)) {
          break;
        }
        // create a set to save into map
        std::set<Point> newSet;
        // North
        Point northPt(x, y-1, z);
        if (hasPath(currPt, northPt, temp3Darray)){
          newSet.insert(northPt);
        }
        // South
        Point southPt(x, y+1, z);
        if (hasPath(currPt, southPt, temp3Darray)){
          newSet.insert(southPt);
        }
        // West
        Point westPt(x-1, y, z);
        if (hasPath(currPt, westPt, temp3Darray)){
          newSet.insert(westPt);
        }
        // East
        Point eastPt(x+1, y, z);
        if (hasPath(currPt, eastPt, temp3Darray)){
          newSet.insert(eastPt);
        }
        mGraph[currPt] = newSet;
      }
    }
  }

}

VoxMap::~VoxMap() {
// hello?
}

Route Result(std::vector<Point> vector) {
  Route route;
  for(int i = vector.size() - 1; i > 0; --i){
    if(vector[i - 1].x < vector[i].x){
      route.push_back(Move::WEST);
    }
    else if(vector[i - 1].x > vector[i].x){
      route.push_back(Move::EAST);
    }
    else if(vector[i - 1].y > vector[i].y){
      route.push_back(Move::NORTH);
    }
    else if(vector[i - 1].y < vector[i].y){
      route.push_back(Move::SOUTH);
    }
  }
  return route;
}

Route VoxMap::route(Point src, Point dst) {

  if(isValid(src) && isValid(dst)) {
    std::runtime_error("An error occurred!");
  }

  std::set<Point>        vSet;
  std::queue<Point>      wQueue;
  std::map<Point, Point> pMap;

  return Route();
  vSet.insert(src);
  wQueue.push(src);

  while(wQueue.size() > 0) {
    Point currPt = wQueue.front();
    wQueue.pop();

    std::set<Point> currSet = mGraph[currPt];

    for(auto itr = currSet.begin(); itr != currSet.end(); itr++) {
      Point currSubPt = *itr;

      // add to pMap(map)
      pMap[currSubPt] = currPt;
      
      // add to wQueue(queue)
      if(vSet.find(currSubPt) != vSet.end()) {
        wQueue.push(currSubPt);
      }
      
      // add to visited(set)
      vSet.insert(currSubPt);
    }

    if(vSet.find(dst) != vSet.end()) {

      std::vector<Point> preResult;
      Point holder = dst;
      
      while( pMap.find(holder) != pMap.end() ) {
        Point pt = pMap.find(holder)->second;
        preResult.push_back(pt);
      }

      return Result(preResult);
    }
  }
  throw std::runtime_error("An error occurred!");
}

bool VoxMap::isValid(const Point& point) {
  bool valid = true;
  // check boundary
  if (point.x < 0 || point.y < 0 || point.z < 1) {
    valid = false;
  }
  if (point.x > mWidth || point.y > mDepth || point.z > mHeight) {
    valid = false;
  }
  // check if point is in graph
  if (mGraph.find(point) == mGraph.end()) {
    valid = false;
  }
  return valid;
}

bool VoxMap::isInBounds(const Point& point) {
  bool valid = true;
  // check boundary
  if (point.x < 0 || point.y < 0 || point.z < 1) {
    valid = false;
  }
  if (point.x > mWidth || point.y > mDepth || point.z > mHeight) {
    valid = false;
  }
  return valid;
}

bool VoxMap::isWalkable(const Point& point,  std::vector<std::vector<std::vector<bool>>> temp3Darray) {
  // current tile is not empty
  if (!temp3Darray[point.x][point.y][point.z]) {
    return false;
  }
  Point pointBelow = Point(point.x, point.y, point.z - 1);
  if (!isInBounds(pointBelow)) {
    return false;
  }
  if (temp3Darray[point.x][point.y][point.z - 1]) {
    return true;
  }
  return false;
}

bool VoxMap::hasPath(const Point& src, const Point& dst, std::vector<std::vector<std::vector<bool>>> temp3Darray){
  // check if src can go to dst by one step
  if (!isWalkable(src, temp3Darray) || !isWalkable(dst, temp3Darray)) {
    return false;
  }
  // if they are separated by more than 1 tile, no path
  if (abs(src.x - dst.x) > 1 || abs(src.y - dst.y) > 1) {
    return false;
  }
  // case 1 - src and dst is at same level
  if (src.z == dst.z) {
    return true;
  }
  // case 2 - climb up by 1 level 
  Point pointAbove = Point(src.x, src.y, src.z + 1);
  if (dst.z - src.z == 1 && isInBounds(pointAbove) && !temp3Darray[src.x][src.y][src.z + 1]) {
    return true;
  }
  // case 3 - free fall
  if (dst.z < src.z) {
    for(int i = 0; i < abs(src.z - dst.z); ++i) {
      if (temp3Darray[src.x][src.y][i]) {
        return false;
      }
    }
    return true;
  }

  return false;
}