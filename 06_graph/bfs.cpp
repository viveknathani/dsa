#include<iostream>
#include<list>

using namespace std;

class Graph
{
private:
  int V; //no of vertices
  list <int> *adj;

public:
  Graph(int V);
  void addEdge(int v, int w);
  void bfs(int s);
};

Graph::Graph(int V)
{
  this->V=V;
  adj=new list <int> [V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

void Graph::bfs(int s)
{
  cout<<"bfs traversal : ";
  bool *checked=new bool[V];
  for(int i=0; i<V; i++)
  {
    checked[i]=true;
  }

  list <int> queue;

  checked[s]=true;
  queue.push_back(s);

  list <int>::iterator i;

  while(!queue.empty())
  {
    s=queue.front();
    cout<<s<<" ";
    queue.pop_front();

    for(i=adj[s].begin(); i!=adj[s].end(); ++i)
    {
      if(!checked[*i])
      {
        checked[*i]=true;
        queue.push_back(*i);
      }
    }
  }
  cout<<endl;
}

int main()
{
  Graph G(3);
  G.addEdge(4, 1);
  G.addEdge(5, 4);
  G.addEdge(2, 3);
  G.addEdge(4, 44);
  G.addEdge(5, 2);

  G.bfs(2);
  G.bfs(4);
  G.bfs(5);

  return 0;
}
