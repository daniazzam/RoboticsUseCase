#include "Rectangle.h"

Rectangle::Rectangle(const std::string& name, const Point& center, double width, double height)
    : name(name), center(center), width(width), height(height) {
}

std::string Rectangle::getName() const {
    return name;
}

void Rectangle::setName(const std::string& name) {
    this->name = name;
}

Point Rectangle::getCenter() const {
    return center;
}

void Rectangle::setCenter(const Point& center) {
    this->center = center;
}

double Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(double height) {
    this->height = height;
}

bool Rectangle::checkIfPointInZone(const Point& point) const {
    if (point.x < (center.x + width / 2) && point.x > (center.x - width / 2) &&
        point.y < (center.y + height / 2) && point.y > (center.y - height / 2)) {
        return true;
    } else {
        return false;
    }
}

bool Rectangle::checkIfPointWithinRange(const Point& point) const {
    if (point.x < (1 + center.x + width/2) && point.x > (center.x - width/2 - 1) &&
        point.y < 1 + (center.y + height/2) && point.y > (center.y - height/2 - 1)) {
        return true;
    } else {
        return false;
    }
}
