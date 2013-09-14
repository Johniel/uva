#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long int lli;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int D = 33 * 2;
lli t[D][D][D];

lli rec(lli a, lli b, bool p, lli g)
{
  if(a + b <= 0){
    return !p;
  }
  if(t[a][b][p] != -1){
    return t[a][b][p];
  }
  lli sum = 0;
  if(p){
    if(b){
      for(lli i=1; i<=g; ++i){
	if(a-i>=0){
	  sum += rec(a-i, b, !p, g);	
	}
      }    
    }
    else sum += rec(0, 0, !p, g);
  }
  else{
    if(a){
      for(lli i=1; i<=g; ++i){
	if(b-i>=0){
	  sum += rec(a, b-i, !p, g);
	}
      }
    }
    else sum += rec(0, 0, !p, g);
  }
  return t[a][b][p] = sum;
}

int main(void)
{
  for(int tc=0; ;){
    lli d, g;
    cin >> d >> g;
    if(d == -1 && g == -1)break;
    fill(&t[0][0][0], &t[D-1][D-1][D], -1);
    if(d == 0 && g == 0){
      cout << "Case " << ++tc << ": " << 1 << endl;
    }
    else{
      cout << "Case " << ++tc << ": " << rec(d, d, 0, g)*2 << endl;
    }
  }
  return 0;
}
