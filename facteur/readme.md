# Solving of the "factor" problem with a DFS on a K12 graph

![K12-graph](images/k12.png)

For each vertex _v_ in V, check all reachable vertices _i_, such _i_ has at leaést one digit of _v_.

For example, {11, 61, 36, 83} is a path.

![K12-graph](images/k12-p1.png)

First I create a [Python script](edges.py) to generate the input for our program.
  
  This script will generate the file 'input' which will contains the input in this format:
  
  line #1: two space seperated integers _12_ and _66_. _12_ is the number of vertices and _66_ the number of edges.
  
  for the 66th next lines, we have two space seperated intgers in each line, which indicates the edge.
