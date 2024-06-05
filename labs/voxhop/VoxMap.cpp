
#include "VoxMap.h"
#include "Errors.h"

VoxMap::VoxMap(std::istream& stream) {
  // Build Temporary 3D Array
  
  std::vector<std::vector<std::vector<bool>>> temp3Darray;
  stream >> mWidth >> mDepth >> mHeight;
  temp3Darray.resize(mWidth + 2, std::vector<std::vector<bool>>(mDepth + 2, std::vector<bool>(mHeight + 2, false)));

  std::string line;

  for (int z = 0; z < mHeight; ++z) {
    for (int y = 0; y < mDepth; ++y) {
      std::getline(stream, line);
      if(line.empty()){
        y --;
        continue;
      }
      for (int x = 0; x < mWidth / 4; ++x) {
        char hex = line[x];
        int value = std::stoi(std::string(1, hex), 0, 16);
        for (int i = 0; i < 4; ++i) {
          temp3Darray[x*4 + i][y][z] = (value & (8 >> i)) != 0;
        }
      }
    }
  }

  // for (int z = 0; z < mHeight; ++z) {
  //   for (int y = 0; y < mDepth; ++y) {
  //     for (int x = 0; x < mWidth; ++x) {
  //       if (temp3Darray[x][y][z]) {
  //         // std::cout << x << y << z;
  //         std::cout << "  1";
  //       } else {
  //         // std::cout << x << y << z;
  //         std::cout<< "  0";
  //       }
  //     }
  //     std::cout<<"\n";
  //   }
  // }

  // Build mGraph from 3D ARR
  for (int z = 1; z < mHeight; ++z) {
    for (int y = 0; y < mDepth; ++y) {
      // std::cout << "\n" << "\n" << "y = " << y << "\n" << "\n";
      for (int x = 0; x < mWidth; ++x) {

        Point currPt(x, y, z);

        if (!isWalkable(currPt, temp3Darray)) {       
          continue;
        }
        
        // create a set to save into map
        std::set<Point> newSet;
        // std::cout << "\n";

        // //std::cout << currPt << "\n";

        // North
        Point northPt(x, y-1, z);
        for(int i = 1; i < z +1; i++) {
          northPt.z = i;
          if(hasPath(currPt, northPt, temp3Darray)) {
            //std::cout<<"Ptr: "<<northPt<<"\n";
            newSet.insert(northPt);
            break;
          }
        }

        // South
        Point southPt(x, y+1, z);
        for(int i = 1; i < z+1; i++) {
          southPt.z = i;
          if(hasPath(currPt, southPt, temp3Darray)) {
            //std::cout<<"Ptr: "<<southPt<<"\n";
            newSet.insert(southPt);
            break;
          }
        }

        // West
        Point westPt(x-1, y, z);
        for(int i = 1; i < z+1; i++) {
          westPt.z = i;
          if(hasPath(currPt, westPt, temp3Darray)) {
            //std::cout<<"Ptr: "<<westPt<<"\n";
            newSet.insert(westPt);
            break;
          }
        }

        // East
        Point eastPt(x+1, y, z);
        for(int i = 1; i < z+1; i++) {
          eastPt.z = i;
          if(hasPath(currPt, eastPt, temp3Darray)) {
            //std::cout<<"Ptr: "<<eastPt<<"\n";
            newSet.insert(eastPt);
            break;
          }
        }

        //std::cout << "currPt at last"<<currPt << "\n" << "from set: ";

        mGraph[currPt] = newSet;
        // for(auto itr = mGraph[currPt].begin(); itr != mGraph[currPt].end(); itr++) {
        //   std::cout << *itr;
        // }
        
        //std::cout << "\n";
      }
    }
  }

  // for(auto itr = mGraph.begin(); itr != mGraph.end(); itr++) {
  //   std::cout <<"Node" << itr->first << "\n";
  //   std::set<Point> sub = itr->second;
  //   std::cout <<"Can go to\n";
  //   for(auto it = sub.begin(); it != sub.end(); it++) {
  //     std::cout << *it << "\n";
  //   }
  //   std::cout << "\n";
  // }
  
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

    Point currPt = wQueue.front();
    wQueue.pop();

    // std::cout << "\n" << "currPt is: " << currPt << "Subset is: ";

    std::set<Point> currSet = mGraph[currPt];
    
    for(auto itr = currSet.begin(); itr != currSet.end(); itr++) {
      Point currSubPt = *itr;
      
      if(vSet.find(currSubPt) == vSet.end()) {
        pMap[currSubPt] = currPt;
        wQueue.push(currSubPt);  
        // std::cout << currSubPt;
      }
      vSet.insert(currSubPt);

    }
    vSet.insert(currPt);

    if(vSet.find(dst) != vSet.end()) {

      std::vector<Point> preResult;
      Point holder = dst;

      preResult.push_back(dst);
      
      while( pMap.find(holder) != pMap.end() ) {
        Point pt = pMap.find(holder)->second;
        preResult.push_back(pt);
        holder = pt;
      }

      return Result(preResult);
    }
  }
  throw NoRoute(src,dst);
}

bool VoxMap::isValid(const Point& point) {
  bool valid = true;
  // check boundary
  if (point.x < 0 || point.y < 0 || point.z < 1) {
    valid = false;
  }
  if (point.x >= mWidth || point.y >= mDepth || point.z >= mHeight) {
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

bool VoxMap::isWalkable(const Point& point,  std::vector<std::vector<std::vector<bool>>>& temp3Darray) {
  if(!isInBounds(point)) {
    return false;
  }
  if(temp3Darray[point.x][point.y][point.z]) {
    return false;
  }
  if(point.z == 0) {
    return false;
  }
  if(temp3Darray[point.x][point.y][point.z - 1]) {
    return true;
  }
  return false;
}

bool VoxMap::hasPath(const Point& src, const Point& dst, std::vector<std::vector<std::vector<bool>>>& temp3Darray){
  // check if src can go to dst by one step
  if (!isWalkable(src, temp3Darray) || !isWalkable(dst, temp3Darray)) {
    // std::cout << "Ptr: " << dst << " is not walkable\n";
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