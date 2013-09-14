#include <iostream>
#include <algorithm>

using namespace std;

const int N = 8 * 2 + 1;
const int M = 1 << N;

double memo[M];
double adj[N][N];

double rec(int s, int size)
{
  if(s == (1 << size) - 1)return 0;
  if(0 <= memo[s])return memo[s];
  double mn = 1e256;
  for(int i=0; i<size; ++i){
    if(s & (1 << i))continue;
    for(int j=i+1; j<size; ++j){
      if(s & (1 << j))continue;
      int t = s | (1 << i) | (1 << j);
      mn = min(mn, rec(t, size) + adj[i][j]);
    }
  }
  return memo[s] = mn;
}

#define fr first 
#define sc second

#include <cmath>
pair<double, double> p[N];
double dist(int a, int b)
{
  return sqrt((p[a].fr - p[b].fr) * (p[a].fr - p[b].fr) + 
	      (p[a].sc - p[b].sc) * (p[a].sc - p[b].sc) );
}

void cost(int size)
{
  for(int i=0; i<size; ++i){
    for(int j=i+1; j<size; ++j){
      adj[i][j] = adj[j][i] = dist(i, j);
    }
  }
  return ;
}

#include <cstdio>
int main(void)
{
  int n, cnt = 0;
  while(cin >> n && n){
    fill(memo, memo + M, -1);
    for(int i=0; i<2*n; ++i){
      string s;
      cin >> s >> p[i].fr >> p[i].sc;
    }
    cost(2 * n);
    printf("Case %d: %.2lf\n", ++cnt, rec(0, 2 * n));
  }
  return 0;
}
