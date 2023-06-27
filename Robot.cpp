#include "Robot.h"

std::vector<Point> Robot::getPath() const {
    return path;
}

void Robot::setPath(const std::vector<Point>& path) {
    this->path = path;
}

void Robot::addPointToPath(const Point& point) {
    // Add the point to the current path
    path.push_back(point);
}