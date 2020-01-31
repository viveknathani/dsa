#include<iostream>
#include<list>

using namespace std;

class Graph
{
private:
  int V; //no of vertices
  list <int> *adj;
  void dfsUtility(int v, bool visited[]);

public:
  Graph(int V);
  void addEdge(int v, int w);
  void dfs(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::dfsUtility(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfsUtility(*i, visited);
}

void Graph::dfs(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    dfsUtility(v, visited);
}


int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.dfs(2);
  return 0;
}
