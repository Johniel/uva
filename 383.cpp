#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  const int NODE = 30 + 1, INF = 1 << 20;  
  int tc, cnt = 0;
  int graph[NODE][NODE];
  cout << "SHIPPING ROUTES OUTPUT" << endl;
  cout << endl;
  for(cin >> tc; tc--; ){
    int node, edge, query;
    int no = 0;
    map<string, int> name;    
    fill(&graph[0][0], &graph[NODE-1][NODE], INF);
    cin >> node >> edge >> query;        
    for(int i=0; i<node; ++i){
      string s;
      cin >> s;
      name[s] = no++;
    }
    for(int i=0; i<edge; ++i){
      string src, dst;
      cin >> src >> dst;
      int s = name[src], d = name[dst];
      graph[s][d] = 1;
      graph[d][s] = 1;
    }
    for(int k=0; k<node; ++k){
      for(int i=0; i<node; ++i){
	for(int j=0; j<node; ++j){
	  graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
	}
      }
    }
    cout << "DATA SET  " << ++cnt << endl << endl;
    for(int i=0; i<query; ++i){
      int n;
      string s, t;
      cin >> n >> s >> t;
      int src = name[s], dst = name[t];
      if(graph[src][dst] == INF)cout << "NO SHIPMENT POSSIBLE" << endl;
      else cout << '$' << n * 100 * graph[src][dst] << endl;
    }
    cout << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
