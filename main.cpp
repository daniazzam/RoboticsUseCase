#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Robot.h"
#include "Rectangle.h"

void initializeZonesAndPath(const std::string& filename, std::vector<Rectangle>& zones, Robot& robot){
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        // Extracting the path
        if (std::getline(inputFile, line)) {
            std::cout << line << std::endl;

            std::istringstream iss(line);
            double x, y;
            while (iss >> x) {
                if (!(iss >> y)) {
                    throw std::runtime_error("Invalid input: Incorrect type (missing) 'y' value for final x of respective value " + std::to_string(x));
                }
                robot.addPointToPath({x, y}); 
            }
        }

        // Extracting the zones 
        while (std::getline(inputFile, line)){
            std::cout << line << std::endl;
            std::istringstream iss(line);
            std::string zoneName;
            double x, y, width, height;
            if (iss >> zoneName >> x >> y >> width >> height){
                // Rectangle rect(zoneName, {x,y}, width, height);
                if(zoneName.substr(0, 4) != "zone" && zoneName.substr(0, 4) != "Zone"){
                    throw std::runtime_error("Incorrect input syntax: "+ zoneName);   
                }
                zones.push_back({zoneName, {x,y}, width, height});
            } else {
                throw std::runtime_error("Wrong input format: "+ line);
            } 
        }

        inputFile.close();
    } else {
        throw std::runtime_error("Failed to open the file: "+ filename);
    }
}

int main(){
    try {
        Robot robot;
        std::string filename = "input.txt";
        std::vector<Rectangle> zones;

        initializeZonesAndPath(filename, zones, robot);

        std::vector<char> flags(zones.size(), 0);
        int count = 0;

        for(Point p: robot.getPath()){
            
            for(Rectangle z: zones){
                
                //check if point in zone range
                if(z.checkIfPointWithinRange(p)){

                    //check if point is inside zone
                    if(z.checkIfPointInZone(p)){
                        // point is inside the zone
                        std::cout << "Inside " << z.getName() << std::endl;
                        if(!flags[count]) {
                            flags[count] = 1;
                        }
                    } else {
                        // point is inside range but oustide zone
                        if(flags[count]){
                            std::cout << "Exiting " << z.getName() << std::endl;
                        } else {
                            std::cout << "About to enter " << z.getName() << std::endl;
                        }
                    }
                } else {
                    if(flags[count]){
                        flags[count] = 0;
                    }
                }
                count++;     
            } 
            count = 0;
            std::cout << " "<< std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
    return 0;
}
