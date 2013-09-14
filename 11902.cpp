#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;

bool g[N][N];
bool vis[N], r[N];
bool na[N];

void rec(int v, int size)
{
  vis[v] = true;
  for(int i=0; i<size; ++i){
    if(na[i])continue;
    if(!vis[i] && g[v][i])rec(i, size);
  }
  return ;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        int b;
        cin >> b;
        g[i][j] = b == 1;
      }
    }
    cout << "Case " << ++cnt << ':' << endl;
    string l = "+" + string(2*n-1, '-') + "+";
    fill(vis, vis + n, false);
    rec(0, n);
    copy(vis, vis + n, r);    
    cout << l << endl;
    cout << '|';
    for(int i=0; i<n; ++i){
      if(vis[i])cout << "Y|";
      else cout << "N|";
    }
    cout << endl;
    for(int i=1; i<n; ++i){
      fill(vis, vis + n, false);
      na[i] = true;
      rec(0, n);
      na[i] = false;
      cout << l << endl;
      cout << '|';
      for(int j=0; j<n; ++j){
        if(r[j] && !vis[j])cout << "Y|";
        else cout << "N|";
      }
      cout << endl;
    }
    cout << l << endl;
  }
  return 0;
}
