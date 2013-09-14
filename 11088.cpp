#include <iostream>
#include <algorithm>

using namespace std;

const int T = 15;
const int S = 1 << T;

int rec(int visited, int val[], int size_v, int mx[])
{
  if(mx[visited] != -1)return mx[visited];  
  int result = 0;
  for(int i=0; i<size_v-2; ++i){
    if(visited & (1 << i))continue;
    for(int j=i+1; j<size_v-1; ++j){
      if(visited & (1 << j))continue;
      if(val[i] + val[j] + val[j+1] < 20)break;
      for(int k=j+1; k<size_v; ++k){
        if(visited & (1 << k))continue;
        int tmp = (1 << i) | (1 << j) | (1 << k);
        bool u20 = val[i] + val[j] + val[k] < 20;
        result = max(result, rec(visited | tmp, val, size_v, mx) + !u20);
      }
    }
  }
  return mx[visited] = result;
}

int main(void)
{
  int tc = 0, mx[S], v[T];
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    fill(mx, mx + S, -1);
    for(int i=0; i<n; ++i){
      cin >> v[i];
    }
    sort(v, v + n);
    reverse(v, v + n);
    cout << "Case " << ++tc << ": " << rec(0, v, n, mx) << endl;
  }
  return 0;
}
