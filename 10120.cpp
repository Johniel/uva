#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
  const int N = 50;
  const string T = "Let me try!";
  const string F = "Don't make fun of me!";
  int n, m;
  bool vis[N][N];
  while(cin >> n >> m && (n | m)){    
    if(49 <= n){
      cout << T << endl;
      continue;
    }
    queue< pair<int, int> > q;    
    bool flg = false;    
    fill(&vis[0][0], &vis[N-1][N], false);
    q.push(make_pair(1, 1));    
    for(; q.size() && !flg; q.pop()){
      pair<int, int> p = q.front();
      if(flg = p.first == m)continue;
      int i = p.second;
      int f = p.first + (2 * p.second + 1);
      int b = p.first - (2 * p.second + 1);
      if(0 < f && f <= n && !vis[f][i]){   
        vis[f][i] = true;
        q.push(make_pair(f, p.second + 1));
      }
      if(0 < b && b <= n && !vis[b][i]){   
        vis[b][i] = true;
        q.push(make_pair(b, p.second + 1));
      }
    }
    cout << (flg ? T : F) << endl;
  }
  return 0;
}
