#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

const int N = 20 + 2;
const double eps = 1e-8;

int path[N][N][N];
int buff[N];
int size;

double eq(double a, double b)
{
  return fabs(a - b) < eps;
}

void build_path(int i, int j, int d)
{

  return ;
}

const double inf = 1e256;

int main(void)
{
  double g[N][N][N]; 
  for(int node, edge; cin >> node && node; ){
    REP(i, node)REP(j, node)REP(k, node){
      g[i][j][k] = inf;
      path[i][j][k] = -1;
    }

    for(int i=0; i<node; ++i){
      g[i][i][0] = 1;
      for(int j=0; j<node; ++j){
        if(i == j)continue;
        double c;
        cin >> c;
        g[i][j][0] = c;
      }
    } 
    
    int mx = -1;
    for(int s=1; s<node; ++s){
      REP(k, node)REP(i, node)REP(j, node){
        double tmp = g[i][k][s-1] * g[k][j][0];
        if(g[i][j][s] < tmp){
          g[i][j][s] = tmp;
          path[i][j][s] = k;
          
        }
      }
    }

    if(true)cout << "no arbitrage sequence exists" << endl;
    else{

    }
  }
  return 0;
}
