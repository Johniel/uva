#include <iostream>
#include <algorithm>

using namespace std;

const int N = 31, src = 0, dst = 1;

bool g[N][N], vis[N];
pair<int, int> p[N][2];

int n, m;

bool rec(int v, int dir, int depth, int u)
{
  //cout << v << " : " << depth << endl;
  vis[v] = true;
  if(depth == n+1)return v == u;
  for(int i=0; i<m+2; ++i){
    if(vis[i])continue;
    int next = p[v][dir].second;
    if(p[i][dir].first == next){ if(rec(i, dir, depth + 1, u))return true; } continue;
    if(p[i][0].first == next){      
      //cout << p[v][dir].first <<", "<< p[v][dir].second <<" => "<< p[i][0].first <<","<< p[i][0].second << endl;
      if(rec(i, 0, depth + 1, u))return true;
    }
    if(p[i][1].first == next){
      //cout << p[v][dir].first <<", "<< p[v][dir].second <<" => "<< p[i][1].first <<","<< p[i][1].second << endl;
      if(rec(i, 1, depth + 1, u))return true;
    }
  }
  vis[v] = false;
  return false;
}

int main(void)
{
  while(cin >> n >> m && n){   
    fill(vis, vis + N, false);
    for(int i=0; i<m+2; ++i){
      int a, b;
      cin >> a >> b;
      p[i][0] = make_pair(a, b);
      //p[i][1] = make_pair(b, a); continue;
      if(1 < i)p[i][1] = make_pair(b, a);
      else p[i][1] = make_pair(a, b);
    }
    bool flg = false;
    flg |= rec(src, 0, 0, dst) | rec(src, 1, 0, dst);
    flg |= rec(dst, 0, 0, src) | rec(dst, 1, 0, src);
    cout << (flg ? "YES" : "NO") << endl;
  }  
  return 0;
}
