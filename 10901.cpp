#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int L = 0, R = 1, N = 10000 + 1;
queue<int> q[2], no[2];
int re[N];

void sim(const int cap, const int time)
{
  int pos = L, a, b, t = 0;
  while(q[L].size() + q[R].size()){    
    int cnt = 0;
    queue<int> tmp;
    a = q[0].empty() ? 1 << 22 : q[0].front();
    b = q[1].empty() ? 1 << 22 : q[1].front();
    if(t < min(a, b))t = min(a, b);
    while(q[pos].size() && q[pos].front() <= t){
      tmp.push( no[pos].front() );
      q[pos].pop();
      no[pos].pop();
      if(++cnt == cap)break;
    }
    pos ^= 1;
    t += time;
    while(tmp.size()){
      re[tmp.front()] = t;
      tmp.pop();
    }
  }
  return ;
}

int main(void)
{
  int tc, n, t, m, x, y;
  for(cin >> tc; tc--; ){
    string s;
    cin >> n >> t >> m;
    q[L] = q[R] = no[R] = no[L] = queue<int>();
    for(int i=0; i<m; ++i){
      cin >> x >> s;
      y = s == "left" ? L : R;
      no[y].push(i);
      q[y].push(x);
    }
    sim(n, t);
    for(int i=0; i<m; ++i)cout << re[i] << endl;
    if(tc)cout << endl;
  }
  return 0;
}




















/*
bool rpc(string s, string t)
{
  if(s == "paper"){
    return t == "rock";
  }
  else if(s == "scissors"){
    return t == "paper";
  }
  else if(s == "rock"){
    return t == "paper";
  }
}

int main(void)
{
  const int N = 100 + 1;
  int cnt[N], win[N];
  bool flg = true;
  for(int n, m; cin >> n >> m; ){
    fill(cnt, cnt + N, 0);
    fill(win, win + N, 0);
    if(flg)flg = false;
    else cout << endl;
    for(int i=0; i < m * n * (n - 1) / 2; ++i){
      string s, t;
      int a, b;
      cin >> a >> s >> b >> t;
      ++cnt[a];
      ++cnt[b];
      if(rpc(s, t) == rpc(t, s))continue;
      else if(rpc(s, t))++win[a];	
      else ++win[b];
    }
    for(int i=1; i<=n; ++i){
      printf("%.3lf\n", (double)win[i]/(double)cnt[i]);
    }
  }
  return 0;
}
*/
