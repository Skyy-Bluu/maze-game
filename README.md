# maze-game

The maze is made up of walls and a path. The starting point of the maze is marked by the coordinates of the player . The exit is also marked as a dedicated coordinate.

This program takes in a text file as input where the file contains:
- Height and width of the maze
- Layout of the maze ('l' denotes a wall and '.' denotes a path)
- Row and column of the exit 
- Row and column of the player's start position
- List of player moves where 
  - 'u' is up
  - 'd' is down
  - 'l' is left
  - 'r' is right
 Maze coordinates range from (0,0) to (`height`-1, `width`-1). Coordinate (0,0) is at the top left of the maze.
 
Example input file:
```
4 6
lll.ll
ll..ll
l..lll
..llll
0 3
3 0
rururu
```
