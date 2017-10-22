#include <bits/stdc++.h>

using namespace std;

int V, E;
map<int, list<int>> adjList;
map<int, bool> visited;
int *paths = NULL;
int pathIndex;
int maxLenPath;

void createAdjList(int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2;
    cin >> vertex1 >> vertex2;

    vertex1;
    vertex2;

    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
  }
}

bool canVisit(int v1, int v2) {
  return (v1 / 10 == v2 / 10 ||
      v1 / 10 == v2 % 10 ||
      v1 % 10 == v2 / 10 ||
      v1 %10 == v2 % 10);
}

void dfs_visit(int v){
  //Mark the current node as visited and
  // print it
  visited[v] = true;

  paths[pathIndex] = v;
  pathIndex++;
  
  if (pathIndex == V) {
     for (int i = 0 ; i<pathIndex ; ++i)
    cout << paths[i] << " ";
  cout << endl;
  }

  // Recur for all the vertices adjacent
  // to this vertex
  list<int>::iterator i;
  for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
    if (!visited[*i]) {
      //cout << v << " " << *i << " " << canVisit(v, *i) << '\n';
      //int a; cin >> a;
     if (canVisit(v, *i))
        dfs_visit(*i);
    }

  for (int i = 0 ; i< pathIndex ; ++i)
    cout << paths[i] << " ";
  cout << "=====>" << pathIndex;
  cout << endl;
  maxLenPath = max(maxLenPath, pathIndex);
 
  pathIndex--;
  visited[v] = false;
}

void dfs(int v){
  paths = new int[V];
  pathIndex = 0; // Initialize path[] as empty
  maxLenPath = 0;

  // Mark all the vertices as not visited
  for (auto& kv: adjList) {
    visited[kv.first] = false;
  }
  
  
  // Call the recursive helper function
  // to print DFS traversal
  dfs_visit(v);
}


int main() {
  
  cin >> V >> E;
  
  createAdjList(E);

 //int start;

  //scanf("%d", &start);
  for (auto& kv: adjList) {
    int start = kv.first;
    dfs(start);
    cout << "Max == " << maxLenPath << "\n\n";
  }

  /*for (auto& kv: adjList) {
    list<int> l = kv.second;
    cout << kv.first << ":\n";
    for (auto v: l)
      cout << "\t" << v <<" ";
    cout << '\n';
  }*/
  
  cout << maxLenPath;
  printf("\n");

  return 0;
}
