#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool cmp(pair<int, int> a, pair<int, int> b)
{
  return a.first < b.first;
}

int main(void)
{
  static const int NODE = 1000, EDGE = 25000;
  static pair<int, int> E[EDGE];
  static int visited[NODE];
  int node, edge;
  while(true){
    cin >> node >> edge; 
    if(node == 0 && edge == 0)break;
    fill(visited, visited + node, false);
    for(int i=0; i<edge; ++i){
      int src, dst;
      cin >> src >> dst;
      if(src > dst)swap(src, dst);
      E[i] = make_pair(src, dst);
    }
    sort(E, E + edge, cmp);
    for(int i=edge; i--; ){
      if(visited[E[i].first] != 1 && visited[E[i].second] != 1){
	visited[E[i].first] = 1;
	visited[E[i].second] = 2;
      }
    }
    for(int i=0; i<node; ++i){
      if(visited[i] == 1)cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
  return 0;
}
