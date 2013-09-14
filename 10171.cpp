#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

inline
int conv(char c)
{
  return c - 'A';
}

int main(void)
{
  int edge;  
  const int node = conv('Z') + 1, INF = 1 << 22;
  int y[node][node], m[node][node];
  while(cin >> edge && edge){
    fill(&y[0][0], &y[node-1][node], INF);
    fill(&m[0][0], &m[node-1][node], INF);
    char c, d, src, dst;
    int cost, s, t, mn = INF;
    for(int i=0; i<edge; ++i){
      cin >> c >> d >> src >> dst >> cost;
      s = conv(src);
      t = conv(dst);
      if(c == 'Y'){
	y[s][t] = min(y[s][t], cost);
	if(d == 'B')y[t][s] = min(y[t][s], cost);
      }
      else if(c == 'M'){
	m[s][t] = min(m[s][t], cost);
	if(d == 'B')m[t][s] = min(m[t][s], cost);
      }
    }
    REP(i, node){
      y[i][i] = m[i][i] = 0;
    }
    REP(k, node)REP(i, node)REP(j, node){
      y[i][j] = min(y[i][j], y[i][k] + y[k][j]);
      m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
    }  
    cin >> src >> dst;
    s = conv(src);
    t = conv(dst);
    REP(i, node){
      if(y[s][i] + m[t][i] < mn){
	mn = y[s][i] + m[t][i];
      }
    }
    if(mn < INF){
      cout << mn ;
      REP(i, node){
	if(y[s][i] + m[t][i] == mn){
	  cout << ' ' << (char)(i + 'A');
	}
      }
      cout << endl;
    }
    else cout << "You will never meet." << endl;
  }
  return 0;
}
