#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int main(void)
{
  int n, m;
  int v[30];
  while(cin >> n >> m && (n | m)){
    queue<int> q;
    fill(v, v + 30, 0);
    for(int i=0; i<n; ++i){
      q.push(i + 1);
    }
    int sum = 0;
    int cnt = 1;
    while(q.size()){
      if(sum == 0){
        sum = cnt;
        if(++cnt > m)cnt = 1;
      }
      int a = q.front();
      q.pop();
      int b = min(sum, 40 - v[a]);
      sum -= b;
      v[a] += b;
      if(v[a] < 40)q.push(a);
      else printf("%3d", a);
    }
    puts("");
  }
  return 0;
}
