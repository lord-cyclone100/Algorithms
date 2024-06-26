# Greedy Algorithms

## Introduction

Greedy algorithms follow a problem-solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum. They are simple, intuitive, and often efficient, but they do not always produce the best solution for complex problems.

## Examples of Greedy Algorithms

1. **Dijkstra's Algorithm**: Used for finding the shortest path in a graph from a starting node to all other nodes.
2. **Kruskal's Algorithm**: Used for finding the minimum spanning tree of a graph.
3. **Fractional Knapsack**: This problem can be solved by greedy strategy by taking items with the highest $\frac{value}{weight}$ ratio first.
4. **Prim's Algorithm**: A greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. It starts from a random vertex and greedily grows the tree by adding the minimum weight edge from the tree to the graph.
5. **Job Scheduling Problem**: Jobs are scheduled based on their deadlines and durations to maximize profit or minimize penalty.

<h2 align="left"><img src="https://i.gifer.com/QFLl.gif" align="center"
                width="28" /> &nbsp; Prim's Algorithm</h3>
                <br>
<p align="left"> 
Prim's Algorithm is a greedy approach to find the minimal spanning tree for a given graph.

**Initialization:**
Three sets namely key, parent and mstSet are taken each with length = no of vertices of the graph. Each of the elements of the sets are initialized as follows:
key[] with 999 and parent[] and mstSet[] with 0.

**Procedure:**
All vertices are assigned a key and parent value. Any of the vertex of the graph is selected as the starting vertex and its key value is assigned 0. Then check for the unvisited adjacent vertices and if their key values are greter than the weight of the edge joining it and the chosen vertex, then update its key value equivalent to the weight value. Continue this procedure until all the vertices are visited.

Finally, the cost set would contain the minimum path weights and adding it's elements would give the minimum cost of the spanning tree and the mstSet contains the parent value of each vertex which finaaly gives the edge sets of the MST.

**Algorithm:**
```c
Algorithm Prim(G,w,r){
    for each vertex u ∈ G(V ){
        key[u] := ∞; // Initialization
        parent[u] := nil;
        mstSet[u] := false;
    }
    key[r] := 0; // Start from root
    //Make a min priority Queue Q; // min-heap is used 
    //for min priority Queue
    while Q is not empty{
        // Until all vertices in MST
        u := ExtractM in(Q); // Delete a minimum valued 
        //vertex from heap
        mstSet[u] := true;
        for each v adjacent from u{
            if mstSet[v] = false and w[u, v] < key[v]{
                DecreaseKey(v, w[u][v]); // Update heap
                parent[v] := u;
            }
        }
    }
}
```

**Working:**
The following graph is used to demonstrate Prim's Algorithm.

<div style="display: flex; margin: 0 auto;">
    <img src="../pics/prim1.png" height=300 width=400>
    <img src="../pics/primadj.png" height=300 width=400>
</div>

Here we select A as the starting vertex. Make its key 0. It's adjacents are B and D. Since they are ∞, update the cost values with respective edge weights and parent values as A. Mark vertex A as visited

<p align="center">
  <img src="../pics/prim2.png" height=300 width=400>
</p>

Now minimum key is 7 hence vertex B is selected and same process is applied.

<p align="center">
  <img src="../pics/prim3.png" height=300 width=400>
</p>

Now minimum key is 3 hence vertex D is selected and same process is applied.

<p align="center">
  <img src="../pics/prim4.png" height=300 width=400>
</p>

Now minimum key is 3 hence vertex E is selected and same process is applied.

<p align="center">
  <img src="../pics/prim5.png" height=300 width=400>
</p>

Now minimum key is 2 hence vertex C or vertex F anyone can be selected. Let,s select C and apply the same process.

<p align="center">
  <img src="../pics/prim6.png" height=300 width=400>
</p>

Now as 5 > 2, key of F won't be updated and the previous value will remain.

<p align="center">
  <img src="../pics/prim7.png" height=300 width=400>
</p>

The final MST obtained is shown with minimum cost 17

<div style="display: flex; margin: 0 auto;">
    <img src="../pics/primfinal.png" height=300 width=400>
    <img src="../pics/primop.png" height=300 width=400>
</div>

**Time Complexity:**
O(|V|log V + |E|log V)



<h2 align="left"><img src="https://i.gifer.com/QFLl.gif" align="center"
                width="28" /> &nbsp; Kruskal's Algorithm</h3>
                <br>
<p align="left"> 
Kruskal's Algorithm is a greedy approach to find the minimal spanning tree for a given graph.

**Initialization:**
This algorithm utilizes the operations of disjoint set data structure namely makeSet(), findSet() and unionSet(). The main aim of using these functions is to detect the presence of cycles. Initially, every vertex in the graph is made an independent set with only one node by using the makeSet() function.

**Procedure:**
The edges are sorted in non decreasing order of their weights. Then each edge is chosen and findSet() operation is performed on both the vertices of the edge, if they are unequal, then unionSet() is performed on them and the edge is selected for the MST.

If the findSet() operation for the both the vertices becomes equal, it indicates, adding the edge would create a cycle and hence it gets rejected.

A variable is maintained which keeps track of the costs of the edges of the MST.

**Algorithm:**
```c
void Kruskal(G,w){
    A := Φ;
    for each vertex v ∈ G(V){
        Make-set(V );
    }
    //Sort the edges of E in non-decreasing order by weight w;
    for each edge (u, v) ∈ E, taken in non-decreasing order by weight{
        if Find-set(u)6= Find-set(v){
            A := A ∪ {u, v};
            Union(u, v);
        }
    }
}
```

**Working:**
The following graph is used to demonstrate Kruskal's Algorithm. The edges are sorted in non decreasing order

<div style="display: flex; margin: 0 auto;">
    <img src="../pics/kruskal1.png" height=300 width=400>
    <img src="../pics/primadj.png" height=300 width=400>
</div>

Select 2. Corresponding vertices are F and E. Include them and findSet() will yield different results for both.

<p align="center">
  <img src="../pics/kruskal2.png" height=300 width=400>
</p>

Select 2. Corresponding vertices are C and E. Include them and findSet() will yield different results for both.

<p align="center">
  <img src="../pics/kruskal3.png" height=300 width=400>
</p>

Select 3. Corresponding vertices are B and D. Include them and findSet() will yield different results for both.

<p align="center">
  <img src="../pics/kruskal4.png" height=300 width=400>
</p>

Select 3. Corresponding vertices are D and E. Include them and findSet() will yield different results for both.

<p align="center">
  <img src="../pics/kruskal5.png" height=300 width=400>
</p>

Exclude 4 as the corresponding vertices C and D have findSet() values same and hence adding the edge would create a cycle.

<p align="center">
  <img src="../pics/kruskal6.png" height=300 width=400>
</p>

Exclude 5 as the corresponding vertices C and F have findSet() values same and hence adding the edge would create a cycle.

<p align="center">
  <img src="../pics/kruskal7.png" height=300 width=400>
</p>

Exclude 6 as the corresponding vertices C and B have findSet() values same and hence adding the edge would create a cycle.

<p align="center">
  <img src="../pics/kruskal8.png" height=300 width=400>
</p>

Select 7. Corresponding vertices are A and B. Include them and findSet() will yield different results for both.

<p align="center">
  <img src="../pics/kruskal9.png" height=300 width=400>
</p>

Exclude 8 as the corresponding vertices A and D have findSet() values same and hence adding the edge would create a cycle.

<p align="center">
  <img src="../pics/kruskal10.png" height=300 width=400>
</p>

The final MST obtained is shown with minimum cost 17

<div style="display: flex; margin: 0 auto;">
    <img src="../pics/kruskalfinal.png" height=300 width=400>
    <img src="../pics/kruskalop.png" height=300 width=400>
</div>

**Time Complexity:**
O(|E|log E + |E|log V)



<h2 align="left"><img src="https://i.gifer.com/QFLl.gif" align="center"
                width="28" /> &nbsp; Dijkstra's Algorithm</h3>
                <br>
<p align="left"> 
Dijkstra's Algorithm is a greedy approach to find the single source shortest path between a source vertex and all other vertices(destination) for a given graph.

**Initialization:**
Two sets namely distance and sptSet are taken each with length = no of vertices of the graph. Each of the elements of the sets are initialized as follows:
distance[] with 999 and parent[] with false.

**Procedure:**
All vertices are assigned a distance and parent value. Any of the vertex of the graph is selected as the starting vertex and its distance value is assigned 0. Then check for the unvisited adjacent vertices and if their key values are greater than the sum of the weight of the edge joining it and the chosen vertex and weight of the distance of the vertex, then update its distance value equivalent to the sum of the  weight of the edge joining it and the chosen vertex and weight of the distance of the vertex. Continue this procedure until all the vertices are visited.

Finally, the distane set would contain the shortest path distances from the source node to the destination nodes.

**Algorithm:**
```c
Algorithm Dijkstra(G,w,s){
    for each vertex u ∈ G(V){
        dist[u] := ∞; // Initialization
        pred[u] := nil;
        sptSet[u] := false;
    }
    dist[s] := 0; // Start from root
    //Make a min priority Queue Q;
    // Make a min priority Queue
    while Q is not empty{
        // Until all vertices in MST
        u := extractM in(Q); // Delete a minimum valued vertex from heap
        sptSet[u] := true;
        for each v adjacent from u{
            if sptSet[v] = false and dist[u] + cost[u, v] < dist[v]{
                decreaseKey(v, dist[u] + cost[u][v]); // Update heap accordingly
                pred[v] := u;
            }
        }
    }
}
```

**Working:**
The following graph is used to demonstrate Prim's Algorithm.

<div style="display: flex; margin: 0 auto;">
    <img src="../pics/dj1.png" height=300 width=400>
    <img src="../pics/djmat.png" height=300 width=400>
</div>

Here we select A as the starting vertex. Make its key 0. It's adjacents are B, F and E. Since they are ∞, update the cost values with respective edge weights and parent values as A. Mark vertex A as visited.

<p align="center">
  <img src="../pics/dj2.png" height=300 width=400>
</p>

Now minimum key is 7 hence vertex B is selected and it's adjacent unvisited vertices' distances are updated as per the sum discussed above.

<p align="center">
  <img src="../pics/dj3.png" height=300 width=400>
</p>

Now minimum key is 9 hence vertex F is selected and it's adjacent unvisited vertices' distances are updated as per the sum discussed above.

<p align="center">
  <img src="../pics/dj4.png" height=300 width=400>
</p>

Now minimum key is 11 hence vertex E is selected and it's adjacent unvisited vertices' distances are updated as per the sum discussed above.

<p align="center">
  <img src="../pics/dj5.png" height=300 width=400>
</p>

Now minimum key is 15 hence vertex C is selected and it's adjacent unvisited vertices' distances are updated as per the sum discussed above.

<p align="center">
  <img src="../pics/dj6.png" height=300 width=400>
</p>

Only one key is remaining. Update it value and now the distance array contains the shortest paths from A to all the other vertices.

<div style="display: flex; margin: 0 auto;">
    <img src="../pics/dj7.png" height=300 width=400>
    <img src="../pics/djop.png" height=300 width=400>
</div>

**Time Complexity:**
O(|V|log V + |E|log V)

## Advantages of Greedy Algorithms

- They are easy to understand and implement.
- They often have lower computational complexity than other algorithms.

## Disadvantages of Greedy Algorithms

- They do not always provide the most optimal solution.
- They can be easily misled by problems where the obvious choice isn't always the best.

## Conclusion

While greedy algorithms may not always provide the most optimal solution, they are a valuable tool in the programmer's toolkit due to their simplicity and efficiency. Understanding when to use a greedy approach is key to being able to effectively solve problems.

## References

- [GeeksforGeeks - Greedy Algorithms](https://www.geeksforgeeks.org/greedy-algorithms/)
- [Wikipedia - Greedy Algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm)

## License

This project is licensed under the terms of the MIT license.