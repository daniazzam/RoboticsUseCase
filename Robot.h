#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "Point.h"

class Robot {
private:
    std::vector<Point> path;

public:
    std::vector<Point> getPath() const;
    void setPath(const std::vector<Point>& path);
    void addPointToPath(const Point& point);
};

#endif  // ROBOT_H
