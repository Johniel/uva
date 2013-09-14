#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

const int N = 200;

int g[N][N];
int p[N][N];
int path[N], size;
int tax[N];

const int inf = 1 << 28;

void build(int src, int dst)
{
  int via = p[src][dst];
  if(src == -1 || dst == -1 || via == src)return;
  build(src, via);
  path[size++] = via;
  build(via, dst);
}

int main(void)
{
  int tc;
  string s;
  cin >> tc;
  getline(cin, s);
  getline(cin, s);
  while(tc--){
    getline(cin, s);
    istringstream iss(s);
    int node;
    for(int i=0, w; iss >> w; node = ++i){
      g[0][i] = w;
    }
    for(int i=1; i<node; ++i){
      for(int j=0; j<node; ++j){
        cin >> g[i][j];
      }
    }
    for(int i=0; i<node; ++i){
      p[i][i] = -1;
      for(int j=0; j<node; ++j){
        p[i][j] = i;
      }      
    }
    for(int i=0; i<node; ++i){
      cin >> tax[i];
    }
    for(int i=0; i<node; ++i){
      for(int j=0; j<node; ++j){
        if(g[i][j] < 0)g[i][j] = inf;
        else g[i][j] += tax[j];
      }
    }
    for(int k=0; k<node; ++k){
      for(int i=0; i<node; ++i){
        for(int j=0; j<node; ++j){
          if(g[i][j] > g[i][k] + g[k][j]){
            g[i][j] = g[i][k] + g[k][j];
            p[i][j] = k;
          }
        }
      }
    }
    cin.ignore();
    bool flg = true;
    while( getline(cin, s) && s.size() ){
      if(flg)flg = false;
      else cout << endl;
      istringstream iss(s);
      int src, dst;
      iss >> src >> dst;
      --src;
      --dst;
      cout << "From " << src+1 << " to " << dst+1 << " :" << endl;
      cout << "Path: ";
      if(src != dst){
        size = 0;
        build(src, dst);
        cout << src+1;
        for(int i=0; i<size; ++i){
          cout << "-->";
          cout << path[i]+1;
        }
        cout << "-->" << dst+1 << endl;
      }      
      else cout << src+1 << "-->" << dst+1 << endl;
      cout << "Total cost : " << g[src][dst] - tax[dst] << endl;
    }
    if(tc)cout << endl;
  }
  return 0;
}
