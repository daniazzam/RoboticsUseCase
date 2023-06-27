# Robotics Use Case - Industrial Robots


## Code Structure

The code consists of the following files:

- `Rectangle.h` and `Rectangle.cpp`: These files define the `Rectangle` class, which represents a zone in the environment. It provides functions to set and get the zone's properties and check if a point is inside the zone or within a certain range of the zone.

- `Robot.h` and `Robot.cpp`: These files define the `Robot` class, which represents the industrial robot. It contains functions to set and get the robot's path and add points to the path.

- `Point.h`: This file defines the `Point` structure, which represents a 2D point with `x` and `y` coordinates.

- `main.cpp`: This file contains the main entry point of the program. It includes the necessary header files, defines the `initializeZonesAndPath` function, and implements the main algorithm of the program in the `main()` function.

## Compilation and Execution

To compile and run the program, follow these steps:

1. Make sure you have a C++ compiler (such as GCC or Clang) installed on your system.

2. Download or clone the code files to your local machine.

3. Open a terminal or command prompt and navigate to the directory containing the code files.

4. Compile the code using the following command:


   ```shell
   g++ main.cpp Robot.cpp Rectangle.cpp -o program
   
This command compiles the source files and creates an executable file named `program`.

5. Run the program by executing the generated executable:

   ```shell
   ./robot_zone_interaction
   
The program will read the input file (`input.txt` by default), process the robot's path and the zones, and log the occurrences where the robot interacts with the zones.

Note: If you want to use a different input file, update the filename variable in the `main()` function of `main.cpp` before compiling.

## Algorithm

The main algorithm of the program, implemented in the `main()` function, can be summarized as follows:

1. Read the input file and initialize the robot's path and the zones.
2. Create a vector of flags to keep track of whether the robot has entered a zone or not.
3. Iterate over each point in the robot's path.
4. For each point, iterate over the zones.
   - Check if the point is within the range (1 meter) of the current zone.
   - If it is within range:
     - Check if the point is inside the current zone.
       - If it is inside the zone:
         - Log the message "Inside [zone name]".
         - Update the flag for the current zone to indicate that the robot has entered the zone.
       - If it is not inside the zone:
         - If the flag for the current zone is set (indicating the robot was previously inside the zone):
           - Log the message "Exiting [zone name]".
         - Else:
           - Log the message "About to enter [zone name]".
   - If the point is not within range and the flag for the current zone is set:
     - Reset the flag to indicate that the robot has exited the zone.
   - Print an empty line to separate the log entries for each point.
5. The program finishes execution.


