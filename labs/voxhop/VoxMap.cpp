#include "VoxMap.h"
#include "Errors.h"

VoxMap::VoxMap(std::istream& stream) {
  stream >> width >> depth >> height;
  voxels.resize(height, std::vector<std::vector<bool>>(depth, std::vector<bool>(width, false)));

  std::string line;
  for (int z = 0; z < height; ++z) {
    std::getline(stream, line);
    for (int y = 0; y < depth; ++y) {
      std::getline(stream, line);
      for (int x = 0; x < width / 4; ++x) {
        char hex = line[x];
        int value = std::stoi(std::string(1, hex), nullptr, 16);
        for (int i = 0; i < 4; ++i) {
          voxels[z][y][x * 4 + i] = (value & (8 >> i)) != 0;
        }
      }
    }
  }
}

VoxMap::~VoxMap() {
// hello world
}

Route VoxMap::route(Point src, Point dst) {
  throw NoRoute(src, dst);
}
