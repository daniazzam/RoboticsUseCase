#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <optional>
#include "Robot.h"
#include "Rectangle.h"

void initializeZonesAndPath(const std::string& filename, std::vector<std::unique_ptr<Rectangle>>& zones, Robot& robot) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open the file: " + filename);
    }

    std::string line;

    // Lambda Function to check for next non-empty lines
    auto readNextNonEmptyLine = [&]() {
        while (std::getline(inputFile, line)) {
            if (!line.empty()) {
                return true;  // Found a non-empty line
            }
        }
        return false;  // No more lines to read
    };

    // Extracting the path
    if (readNextNonEmptyLine()) {
        std::istringstream iss(line);
        double x, y;

        while (iss >> x) {
            if (!(iss >> y)) {
                throw std::runtime_error("Invalid input: (Incorrect input type / missing 'y' value for final x) of respective value " + std::to_string(x));
            }
            robot.addPointToPath({x, y});
        }
    } else {
        throw std::runtime_error("Invalid input: Empty File");
    }

    // Extracting the zones
    while (readNextNonEmptyLine()) {
        std::istringstream iss(line);
        std::string zoneName;
        double x, y, width, height;

        if (iss >> zoneName >> x >> y >> width >> height) {
            if (zoneName.substr(0, 4) != "zone" && zoneName.substr(0, 4) != "Zone") {
                throw std::runtime_error("Incorrect input syntax: " + zoneName);
            }
            zones.push_back(std::make_unique<Rectangle>(zoneName, Point{x, y}, width, height));
        } else {
            throw std::runtime_error("Wrong input format: " + line);
        }
    }

    inputFile.close();
}


int main() {
    try {
        Robot robot;
        std::string filename = "input.txt";
        std::vector<std::unique_ptr<Rectangle>> zones;

        initializeZonesAndPath(filename, zones, robot);

        std::vector<std::optional<bool>> flags(zones.size());
        int count {0};

        for (Point p : robot.getPath()) {
            for (const auto& z : zones) {
                // Check if point is within the zone range
                if (z->checkIfPointWithinRange(p)) {
                    // Check if point is inside the zone
                    if (z->checkIfPointInZone(p)) {
                        // Point is inside the zone
                        std::cout << "Inside " << z->getName() << std::endl;
                        flags[count] = true;
                    } else {
                        // Point is inside range but outside zone
                        if (flags[count].has_value() && flags[count].value()) {
                            std::cout << "Exiting " << z->getName() << std::endl;
                        } else {
                            std::cout << "About to enter " << z->getName() << std::endl;
                        }
                    }
                } else {
                     flags[count] = std::nullopt;
                }
                count++;
            }
            count = 0;
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
