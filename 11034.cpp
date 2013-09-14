#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int sim(int t[], const int size, int cost)
{
  int r = size, time = 0;
  for(int i=0; i<size; i++){
    if(t[i] + time <= cost){
      time= t[i] + time;
      if(i)--r;
    }
    else time = t[i];
  }
  return r;
}

int main(void)
{
  const int N = 100000;
  int r[N], size_r;
  int l[N], size_l;
  int tc, n, m, t;
  string s;
  cin >> tc;
  while(tc--){
    cin >> n >> m;
    size_r = size_l = 0;
    for(int i=0; i<m; ++i){
      cin >> t >> s;
      if(s == "left")l[size_l++] = t;
      else r[size_r++] = t;
    }
    int a = sim(r, size_r, n * 100);
    int b = sim(l, size_l, n * 100);
    if(a < b)cout << b * 2 - 1 << endl;
    else cout << a * 2 << endl;
  }
  return 0;
}
