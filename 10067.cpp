#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct S{
  int n[4];
  S(){}
  S(int a, int b, int c, int d){
    n[0] = a;
    n[1] = b;
    n[2] = c;
    n[4] = d;
  }
};

const int inf = 1 << 22;

const int T = 10;
int t[T][T][T][T];
bool vis[T][T][T][T];

inline bool& ref_vis(S s)
{
  return vis[s.n[0]][s.n[1]][s.n[2]][s.n[3]];
}

inline int& ref_t(S s)
{
  return t[s.n[0]][s.n[1]][s.n[2]][s.n[3]];
}

int bfs(S src, S dst)
{
  fill(&t[0][0][0][0], &t[T-1][T-1][T-1][T], inf);
  queue<S> q;
  int d[] = {1, 9};
  ref_vis(src) = true;
  ref_t(src) = 0;
  for(q.push(src); q.size(); q.pop()){
    S s = q.front();
    for(int i=0; i<4; ++i){
      for(int j=0; j<2; ++j){
        S t = s;
        t.n[i] = (t.n[i] + d[j]) % 10;
        if(ref_vis(t))continue;
        ref_vis(t) = true;
        ref_t(t) = ref_t(s) + 1;          
        q.push(t);
      }
    }
  }
  return ref_t(dst) == inf ? -1 : ref_t(dst);
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    fill(&vis[0][0][0][0], &vis[T-1][T-1][T-1][T], false);
    S src, dst;
    for(int i=0; i<4; ++i)cin >> src.n[i];
    for(int i=0; i<4; ++i)cin >> dst.n[i];
    int n; 
    cin >> n;
    while(n--){
      S s;
      for(int i=0; i<4; ++i)cin >> s.n[i];
      ref_vis(s) = true;
    }
    cout << bfs(src, dst) << endl;
  }
  return 0;
}
