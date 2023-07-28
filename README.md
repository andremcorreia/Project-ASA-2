# Project-ASA-2
This repository contains the implementation of the second project for the "Análise e Síntese de Algoritmos" course at Instituto Superior Técnico during the academic year 2022/2023.
## Problem Description
The goal of this project is to solve a comercial trade system by railroad problem, which involves in finding the highest value of comercial trades while minimizing the infrastructure cost to decide how the railroad should be built. Using Delaunay's triangulation, the railroad system can be represented as an undirected planar graph G = (V,E), such as, V represents the set of regions and E represents the links between the train stations in each region.
In this project it is assumed that each link has the same infrastructure cost and some comercial trade value (in M€). Thus, given a graph G = (V,E), as previously referred, the task is to calculate the maximum comercial trade value while minimizing the infrastucture cost so that all regions are accessed.
## Input and Output
The input file for the program should follow the following format:

```
<V>      // Number of vertices, V >= 1
<E>      // Number of edges (links), E >= 0
// Followed by E lines of the following format:
<u v w>  // Edge, u and v are some vertices and w the weight of the edge
// The identifier of a vertice is an integer between 1 and V
```

The program reads this input and writes the output to the standard output. The output consists of a single integer representing the maximum comercial trade value of the given input graph (with the optimal infrastructure cost).
## Implementation
There was a preference to implement the project in C++ or C. Submissions in Java/Python were also allowed but not recommended due to potential performance issues.
