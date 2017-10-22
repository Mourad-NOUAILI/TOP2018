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
  visited[v] = true;

  paths[pathIndex] = v;
  pathIndex++;
  
  if (pathIndex == V) {
     for (int i = 0 ; i<pathIndex ; ++i)
    cout << paths[i] << " ";
  cout << endl;
  }

  list<int>::iterator i;
  for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
    if (!visited[*i]) {
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
  // Initialize path[] as empty
  pathIndex = 0;
  
  maxLenPath = 0;

  for (auto& kv: adjList) {
    visited[kv.first] = false;
  }
  
  dfs_visit(v);
}


int main() {
  
  cin >> V >> E;
  
  createAdjList(E);

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
