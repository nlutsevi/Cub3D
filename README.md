# Cub3D

This project is inspired by the world-renowned eponymous game Wolfenstein 3D, considered to be the first FPS. The goal is to make a dynamic view inside a maze from a first-person perspective using Ray-Casting principles.

What is inside:

![Screenshot 2022-02-07 at 03 57 `30](https://user-images.githubusercontent.com/60663416/152720564-aaf7acb2-610e-4ae2-8969-6107af2b4b8d.png)
![Screenshot 2022-02-07 at 03 56 36](https://user-images.githubusercontent.com/60663416/152720561-b39f4fa3-debe-450a-9891-67739330cb56.png)


## To play around

Clone the repository and change directory to it, then
```bash
make
````
Call the executable with a valid map
```bash
./cub3D ./map.cub
```
To clean *.o and *.a
```bash
make fclean
````

## The specific constrains of the project

• The left and right arrow keys of the keyboard must allow you to look left and right in the maze.

• The W, A, S, and D keys must allow you to move the point of view through the maze.

• Pressing ESC must close the window and quit the program cleanly.

• Clicking on the red cross on the window’s frame must close the window and quit the program cleanly, without leaks!

• The use of images of the minilibX is strongly recommended.

### Map

• The map must be composed of only 6 possible characters: 0 for an empty space, for a wall, and N,S,E or W for the player’s start position and spawning orientation.

• The map must be surrounded by walls, if not the program must return an error.

• The map must be parsed as it looks in the file. You must be able to parse any kind of map, as long as it respects the rules of the map.

#### Map elements




