# A*-Search-Algorithm-in-C++
This project implements the A* search algorithm used to find the shortest distance between two points on a grid. The project is developed in C++

**Explanation**

- The A* algorithm is used to find the shortest distance between two points in a grid. 
- The algorithm finds the optimal path by minimizing a cost function which can be shown below
- The algorithm was initially used as a graph traversal problem. 

![image](https://user-images.githubusercontent.com/69100847/178153457-c22e3f48-295c-45a8-bd7d-dd856b513b3a.png)

**Cost Function**

1- The algorithm tries to minimize the cost function f=g+h

2- h is the heuristic function which is the most optimistic considering there are no obstacles between start and end points

3- The g function considers the actual path with the obstacles that are along the path


**Pseudo Code**

search( grid, initial_point, goal_point ) :

Initialize an empty list of open nodes.

Initialize a starting node with the following:

- x and y values given by initial_point.
- g = 0, where g is the cost for each move.
- h given by the heuristic function (a function of the current coordinates and the goal).
- Add the new node to the list of open nodes.

while the list of open nodes is nonempty:

Sort the open list by f-value
Pop the optimal cell (called the current cell).
Mark the cell's coordinates in the grid as part of the path.
if the current cell is the goal cell:

return the grid.
else, expand the search to the current node's neighbors. This includes the following steps:

Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
Mark the cell as closed.
If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
