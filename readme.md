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
   ./program
   
The program will read the input file (`input.txt` by default), process the robot's path and the zones, and log the occurrences where the robot interacts with the zones.

Note: If you want to use a different input file, update the filename variable in the `main()` function of `main.cpp` before compiling.

## Algorithm

The provided C++ code reads input from a text file, processes the data, and performs operations based on the input. Here is a step-by-step explanation of how the algorithm works:

1. File Initialization:
   - Include necessary header files and define the `initializeZonesAndPath` function.
   - Open the specified file using an `std::ifstream` object named `inputFile`. If the file fails to open, an exception is thrown.
   - Declare a string variable named `line` to store each line read from the file.

2. Lambda Function:
   - Define a lambda function named `readNextNonEmptyLine` to handle the task of reading the next non-empty line from the file.
   - Use a `while` loop with `std::getline` to read lines until a non-empty line is encountered.
   - The lambda function returns `true` if a non-empty line is found and `false` if there are no more lines to read.

3. Path Extraction:
   - Call the `readNextNonEmptyLine` function to check for a non-empty line.
   - If a non-empty line is found:
     - Process the line to extract pairs of `x` and `y` coordinates using an `std::istringstream` object named `iss`.
     - Add the extracted coordinates to the `Robot` object's path using the `addPointToPath` method.
   - If no non-empty line is found for the path information, an exception is thrown.

4. Zone Extraction:
   - Call the `readNextNonEmptyLine` function to check for a non-empty line.
   - If a non-empty line is found:
     - Process the line to extract the zone name, `x` and `y` coordinates, width, and height using the `iss` object.
     - Create `Rectangle` objects with the extracted information and add them to the `zones` vector.
   - If there is an issue with the input format (e.g., incorrect syntax or missing values), an exception is thrown.

5. File Closing:
   - Once all the lines have been processed, close the input file.

6. Main Function:
   - Create a `Robot` object named `robot`, declare a filename variable, and initialize an empty vector of `Rectangle` objects named `zones`.
   - Call the `initializeZonesAndPath` function, passing the filename, `zones` vector, and `robot` object as arguments.
   - This function reads the input file and populates the `robot` object with path information and the `zones` vector with zone information.

7. Flag Initialization:
   - Create a vector of characters named `flags` with the same size as the `zones` vector, initialized with all zeros.
   - This vector will be used to track the status of each zone.

8. Zone Tracking:
   - Initialize an integer variable named `count` to zero. It will keep track of the index of the current zone while iterating over the `zones` vector.
   - Enter a nested loop:
     - The outer loop iterates over each point in the `robot` object's path.
     - The inner loop iterates over each `Rectangle` object in the `zones` vector.
     - For each point and zone pair:
       - Check if the point is within the range of the zone by calling the `checkIfPointWithinRange` method of the `Rectangle` object.
       - If the point is within the zone's range:
         - Check if the point is inside the zone by calling the `checkIfPointInZone` method.
         - If the point is inside the zone:
           - Print a message indicating that the point is inside the current zone's name.
           - Set the corresponding flag in the `flags` vector to 1 if it is not already set.
         - If the point is outside the zone but within its range:
           - Check the corresponding flag in the `flags` vector.
           - If the flag is set, print a message indicating that the point is exiting the current zone.
           - If the flag is not set, print a message indicating that the point is about to enter the current zone.
       - If the point is outside the zone's range, reset the corresponding flag in the `flags` vector to 0.
       - Increment the `count` variable to move to the next zone.
     - After processing all zones for a given point, reset the `count` variable to zero.

9. Exception Handling:
   - Use a `try-catch` block to catch any exceptions thrown during the execution of the program.
   - If an exception occurs, print an error message indicating the exception's details.

This algorithm utilizes a lambda function, `readNextNonEmptyLine`, to handle the repetitive task of reading the next non-empty line from the input file. By encapsulating this logic in a lambda function, the code becomes more concise and readable.
