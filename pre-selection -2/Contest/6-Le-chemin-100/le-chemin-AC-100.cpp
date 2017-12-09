//Le chemin
/*
 * Constest: TOP2018 - Pre-selection round #2
 * Subject: Le chemin
 * Lang: C++11
* Submission result: Accepted
*Time complexity: θ(n+m)
*/
#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
list<int> *adjList = NULL;

void createAdjList(int nbEdges) {
  for (int edge = 0 ; edge < nbEdges ; ++edge) {
    int vertex1 , vertex2;
    cin >> vertex1 >> vertex2;

    vertex1--;
    vertex2--;

    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
  }
}


void dfs_visit(int v, bool visited[]){
  visited[v] = true;

  if (v == b) {
    printf("GO SHAHIR!\n");
    exit(0);
  }

  list<int>::iterator i;
  for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
    if (!visited[*i])
      dfs_visit(*i, visited);
}

void dfs(int v){
  bool *visited = new bool[n];
  for (int i = 0; i < n; ++i)
    visited[i] = false;
  
  dfs_visit(v, visited);
}
int main() {
  ios::sync_with_stdio(false);
  
  cin >> n >> m >> a >> b;
  
  a--;
  b--;

  adjList = new list<int>[n];

  createAdjList(m);

 
  dfs(a);

  printf("NO SHAHIR!\n");

  return 0;
}
