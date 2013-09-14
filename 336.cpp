#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int N = 30 + 1;
static const int INF = 1<<20;

int name[N];
int field[N][N];

int main(void)
{
  int tc = 0;
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    fill(&field[0][0], &field[N-1][N], INF);
    fill(name, name + N, -1);
    int lim = INT_MIN;
    REP(i, n){
      int to, from, pt, pf;
      cin >> to >> from;
      REP(j, 2 * n){
	if(name[j] == to || name[j] == -1){
	  pt = j;
	  break;
	}
      }
      REP(j, 2 * n){
	if(name[j] == from || name[j] == -1){
	pf = j;
	break;
	}
      }
      if(name[pf] == -1 && name[pt] == -1)pf++;
      name[pt] = to;
      name[pf] = from; 
      field[pt][pf] = field[pf][pt] = 1;
      lim = max(lim, pf);
    }
    n = lim + 1;
    REP(k, n)REP(i, n)REP(j, n)
      field[i][j] = min(field[i][j], field[i][k] + field[k][j]);
    //int c = 0;
    while(true){
      int cnt = 0;
      int node, ttl;
      cin >> node >> ttl;
      //cout << node << ' ' << ttl << endl;if(tc == 10)exit(1);
      if(node == 0 && ttl == 0)
	break;
      int i;
      REP(k, n)if(name[k] == node){
	i = k;
	break;
      }
      REP(j, n)if(field[i][j] > ttl && j != i)cnt++;
      cout << "Case " << ++tc << ": " << cnt ;
      cout << " nodes not reachable from node "<< node ;
      cout << " with TTL = "<< ttl << "." << endl;
    }
  }
  return 0;
}
