
#include "VoxMap.h"
#include "Errors.h"

VoxMap::VoxMap(std::istream& stream) {
  // Build Temporary 3D Array
  // temp3Darray.resize(mWidth, std::vector<std::vector<bool>>(mDepth, std::vector<bool>(mHeight, false)));
  
  std::vector<std::vector<std::vector<bool>>> temp3Darray;
  stream >> mWidth >> mDepth >> mHeight;

  std::string line;

  for (int z = 0; z < mHeight; ++z) {
    for (int y = 0; y < mDepth; ++y) {
      std::getline(stream, line);
      if(line.empty()){
        continue;
      }
      for (int x = 0; x < mWidth / 4; ++x) {
        char hex = line[x];
        int value = std::stoi(std::string(1, hex), 0, 16);
        for (int i = 0; i < 4; ++i) {
          // std::cout<<((value & (8 >> i))!= 0);
          temp3Darray[x*4 + i][y][z] = (value & (8 >> i)) != 0;
        }
      }
    }
  }
  for (int z = 0; z < mHeight; ++z) {
    for (int y = 0; y < mDepth; ++y) {
      for (int x = 0; x < mWidth; ++x) {
        if (temp3Darray[x][y][z]) {
          std::cout<< "1";
        } else {
          std::cout<< "0";
        }
      }
    }
  }

  // Build mGraph from 3D ARR
  for (int z = 0; z < mHeight; ++z) {
    for (int y = 0; y < mDepth; ++y) {
      for (int x = 0; x < mWidth; ++x) {
        Point currPt(x, y, z);
        if (!isWalkable(currPt, temp3Darray)) {
          continue;
        }
        // create a set to save into map
        std::set<Point> newSet;
        // North
        Point northPt(x, y-1, z);
        if (hasPath(currPt, northPt, temp3Darray)){
          newSet.insert(northPt);
          // std::cout<< "insert North \n";
        }
        // South
        Point southPt(x, y+1, z);
        if (hasPath(currPt, southPt, temp3Darray)){
          newSet.insert(southPt);
          // std::cout<< "insert South \n";
        }
        // West
        Point westPt(x-1, y, z);
        if (hasPath(currPt, westPt, temp3Darray)){
          newSet.insert(westPt);
          // //std::cout<< "insert West \n";
        }
        // East
        Point eastPt(x+1, y, z);
        if (hasPath(currPt, eastPt, temp3Darray)){
          newSet.insert(eastPt);
          //std::cout<< "insert East \n";
        }
        //std::cout<< "trying to add set";
        mGraph[currPt] = newSet;
        for(auto itr = newSet.begin(); itr != newSet.end(); itr++) {
          //std::cout<< *itr;
        }
      }
      // std::cout<< "\n";
    }
    // std::cout<< "\n";
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
  if(!isValid(src) || !isValid(dst)) {
    std::runtime_error("An error occurred!");
  }

  std::set<Point>        vSet;
  std::queue<Point>      wQueue;
  std::map<Point, Point> pMap;

  vSet.insert(src);
  wQueue.push(src);

  while(wQueue.size() > 0) {
    //std::cout<<wQueue.size()<<"\n";

    Point currPt = wQueue.front();
    wQueue.pop();

    std::set<Point> currSet = mGraph[currPt];
    for(auto itr = currSet.begin(); itr != currSet.end(); itr++) {
      //std::cout<< *itr;
      Point currSubPt = *itr;

      // add to pMap(map)
      pMap[currSubPt] = currPt;
      
      // add to wQueue(queue)
      if(vSet.find(currSubPt) == vSet.end()) {
        wQueue.push(currSubPt);
      }
      
      // add to visited(set)
      vSet.insert(currSubPt);
    }
    //std::cout << "finished for loop\n";

    if(vSet.find(dst) != vSet.end()) {
      //std::cout <<"find destination\n";

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
  if (point.x < 0 || point.y < 0 || point.z < 0) {
    valid = false;
  }
  if (point.x > mWidth || point.y > mDepth || point.z > mHeight) {
    valid = false;
  }
  return valid;
}

bool VoxMap::isWalkable(const Point& point,  std::vector<std::vector<std::vector<bool>>> temp3Darray) {
  // current tile is not empty
  if(!isInBounds(point)) {
    return false;
  }
  if (temp3Darray[point.x][point.y][point.z]) {
    // std::cout << "Not walkable because not empty" << point << "\n";
    return false;
  }
  Point pointBelow = Point(point.x, point.y, point.z - 1);
  if (!isInBounds(pointBelow)) {
    // std::cout << "Not walkable because point below out of bound" << point << "\n";
    return false;
  }
  if (!temp3Darray[point.x][point.y][point.z - 1]) {
    // std::cout << "Walkable point found!" << point << "\n";
    return true;
  }
  // std::cout << "Not walkable because point below is empty" << point << "\n";
  return false;
}

bool VoxMap::hasPath(const Point& src, const Point& dst, std::vector<std::vector<std::vector<bool>>> temp3Darray){
  // check if src can go to dst by one step
  // std::cout << "checked path between" << src << dst;
  if (!isWalkable(src, temp3Darray) || !isWalkable(dst, temp3Darray)) {
    // std::cout<< "No path because not walkable \n";
    return false;
  }
  // if they are separated by more than 1 tile, no path
  if (abs(src.x - dst.x) > 1 || abs(src.y - dst.y) > 1) {
    // std::cout<< "No path because distance too far \n";
    return false;
  }
  // case 1 - src and dst is at same level
  if (src.z == dst.z) {
    //std::cout<< "Has Path \n";
    return true;
  }
  // case 2 - climb up by 1 level 
  Point pointAbove = Point(src.x, src.y, src.z + 1);
  if (dst.z - src.z == 1 && isInBounds(pointAbove) && !temp3Darray[src.x][src.y][src.z + 1]) {
    //std::cout<< "Has Path \n";
    return true;
  }
  // case 3 - free fall
  if (dst.z < src.z) {
    for(int i = 0; i < abs(src.z - dst.z); ++i) {
      if (temp3Darray[src.x][src.y][i]) {
        return false;
      }
    }
    //std::cout<< "Has Path \n";
    return true;
  }
  // std::cout<< "No Path \n";
  return false;
}