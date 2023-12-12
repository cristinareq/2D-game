# 2D-game

This is the first draft of a simple 2D game using the SFML library.

## Dependencies

This project depends on the [SFML library](https://www.sfml-dev.org/index.php). SFML can be installed via apt on Linux, brew on MacOS

## Compile and run

Once dependencies are set, you can compile the project with `cmake` in CLion and run it directly. Via command line you can ask `cmake` to generate the `Makefile` and then run `make all`

## import files

Download the font called [arial.ttf](https://www.freefontspro.com/14454/arial.ttf) and drag it in your workspace.

# Requirements

### Task 1 - build dependencies and run

- Install dependencies https://www.sfml-dev.org/
- Build and run the project.

### Task 2 - Understand code, look at SFML documentation

- Understand the code that is currently there.

### Task 3 - Apply minor changes

- Change some simple things in the project.
- Rebuild and run the project

### Task 4 - Move forward!

- Make the player icon move
- Create a separate module with a function to move the player, so it is easier to test it!

### Task 5 - Design the move function

- Design it so that it is possible to easily control x and y coordinates at the same time
- Update the position of the player according to a parameterized speed

### Task 6 - Test case with Google Test

- Write the first test case of the module to update the position of the player.
- Use the Google Test framework for this.

### Task 7 - Deal with keyboard events

- Make the player controllable by keyboard events

GOOGLE TESTING:
We changed the game.h file to make the variables public

COMMAND TO COMPILE TEST:
g++ -o test_executable googletest.cpp game.cpp -lgtest -lpthread -lsfml-graphics
-lsfml-window -lsfml-system -std=c++14

1. g++: Invokes the GNU C++ Compiler to compile C++ code.
2. -o test_executable: Specifies the output file name as test_executable.
3. googletest.cpp game.cpp: Specifies the source files googletest.cpp and game.cpp to
   compile.
4. -lgtest: Links the Google Test library for unit testing.
5. -lpthread: Links the POSIX thread library for multithreading support.
6. -lsfml-graphics -lsfml-window -lsfml-system: Links SFML libraries for graphics,
   windowing, and system operations.
7. -std=c++14: Specifies the use of the C++14 standard for compilation.

COMMAND TO EXECUTE TEST:
./test_executable
