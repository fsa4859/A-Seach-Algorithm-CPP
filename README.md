# A*-Search-Algorithm-in-C++
This project implements the A* search algorithm used to find the shortest distance between two points on a grid. The project is developed in C++

**Explanation**

- The A* algorithm is used to find the shortest distance between two points in a grid. 
- The algorithm finds the optimal path by minimizing a cost function which can be shown below
- The algorithm was initially used as a graph traversal problem. 

![image](https://user-images.githubusercontent.com/69100847/178153244-fcc9db49-c9e4-4f70-8186-58ba29f44e3e.png)


**Cost Function**
1- The algorithm tries to minimize the cost function f=g+h
2- h is the heuristic function which is the most optimistic considering there are no obstacles between start and end points
3- The g function considers the actual path with the obstacles that are along the path



