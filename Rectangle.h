#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <iostream>
#include "Point.h"

class Rectangle {
private:
    std::string name;
    Point center;
    double width, height;

public:
    Rectangle(const std::string& name, const Point& center, double width, double height);
    std::string getName() const;
    void setName(const std::string& name);
    Point getCenter() const;
    void setCenter(const Point& center);
    double getWidth() const;
    void setWidth(double width);
    double getHeight() const;
    void setHeight(double height);
    bool checkIfPointInZone(const Point& point) const;
    bool checkIfPointWithinRange(const Point& point) const;
};

#endif  // RECTANGLE_H
