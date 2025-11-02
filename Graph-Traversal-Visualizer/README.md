# Graph Traversal Visualizer

## Overview
This project implements a **Graph Traversal Visualizer** that demonstrates the working of **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** algorithms.  
It allows users to build a custom graph (directed or undirected), input edges, and visualize traversal sequences across all connected or disconnected components.

---

## Features
- Supports both **Directed** and **Undirected** graphs.  
- Handles **Disconnected Components** automatically.  
- Implements **BFS** using a queue and **DFS** using recursion.  
- Prints a clear **Adjacency List** representation of the graph.  
- Validates user inputs to prevent invalid nodes or edges.  
- Easy to extend for weighted or visual graph versions.

---

## Technologies Used
- **Language:** C++  
- **Concepts:** Graphs, BFS, DFS, Queues, Recursion, Adjacency List  

---

## Input Format
1. Number of vertices  
2. Graph type – Directed (`y`) or Undirected (`n`)  
3. Number of edges  
4. List of edges (`u v`)  
5. Starting node for traversal  

---

## Sample Input / Output

**Input:**
```
Enter number of vertices: 5
Is the graph directed? (y/n): n
Enter number of edges: 5
Enter edges (u v):
0 1
0 2
1 3
2 4
3 4
Enter starting node for traversal: 0
```
**Output:**
```
Adjacency List Representation:
Node 0 -> 1 2
Node 1 -> 0 3
Node 2 -> 0 4
Node 3 -> 1 4
Node 4 -> 2 3

BFS Traversal (from node 0): 0 1 2 3 4
DFS Traversal (from node 0): 0 1 3 4 2

Traversal complete.
```

## How to Run

### Using a local compiler (VS Code, Code::Blocks, etc.)
1. Save the file as `graph_traversal_visualizer.cpp`.
2. Compile the program:
   ```bash
   ``
    g++ graph_traversal_visualizer.cpp -o visualizer
   ``
3. Run
    ``
   ./visualizer
   ``


   --->> This project is licensed under the MIT License. <<---
You are free to use, modify, and distribute it for educational or personal purposes.
