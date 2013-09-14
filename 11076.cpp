#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long int ulli;

const int N = 12 + 1;
const int M = 1 << N;

string s[N];
set<string> vis[M];

ulli sum;

void add(string r)
{
  ulli n = 0;
  reverse(r.begin(), r.end());
  for(int i=0; i<r.size(); ++i){
    if(i)n *= 10;
    n += r[i] - '0';
  }
  sum += n;
  return ;
}

void rec(int state, int size, string r)
{
  if(vis[state].count(r)){
    return ;
  }
  vis[state].insert(r);
  if(state == ((1 << size) - 1)){
    add(r);
    return ;
  }
  for(int i=0; i<size; ++i){
    int b = 1 << i;
    if(state & b)continue;
    rec(state | b, size, r + s[i]);
  }
  return ;
}

ulli fact(ulli n)
{
  ulli f = 1;
  for(ulli i = 1; i <= n; ++i){
    f *= i;
  }
  return f;
}

int main(void)
{
  int n;
  while(cin >> n && n){    
    
    int cnt[10];
    fill(cnt, cnt + 10, 0);
    for(int i=0; i<n; ++i){
      int m;
      cin >> m;
      ++cnt[m];
    }

    ulli p = 1;
    for(int i=0; i<10; ++i){
      p *= fact(cnt[i]);
    }

    cout << fact(n) / p << endl;

    continue;


    for(int i=0; i<n; ++i){
      cin >> s[i];
    }
    
    

    sum = 0;
    fill(vis, vis + M, set<string>());
    rec(0, n, "");
    cout << sum << endl;
  }
  return 0;
}
