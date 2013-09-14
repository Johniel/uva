#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int T = 4000 + 1;
const int N = 1000 + 1;

int depth[T];
int next[T];
int p[T];
vector<int> e[T];

void rec(int v, int d)
{
  //cout << v << ' ' << d << endl;
  //depth[v] = d;
  depth[v] = max(depth[v], d);
  for(int i=0; i<e[v].size(); ++i){
    //if(depth[i] == -1)continue;
    rec(e[v][i], d + 1);    
  }
  return ;
}

void ini(void)
{
  for(int i=2; i<T; ++i){
    int sum = 0;
    for(int j=1; j<=i; ++j){
      if(i % j)continue;
      for(int k=j; k; k /= 10){
        sum += k % 10;
      }
    }
    if(!(sum == 15 && i == 15))e[sum].push_back(i);
    next[i] = sum;
  }
  fill(depth, depth + T, -1);
  depth[0] = 0;
  depth[1] = 0;
  rec(15, 0);
  return ;
}

int main(void)
{
  ini();
  for(int a, b, cnt = 0; cin >> a >> b; ){    
    ++cnt;
    cout << "Input" << cnt << ":" << ' ' << a << ' ' << b << endl;
    if(a > b)swap(a, b);
    if(a == 1 && b == 1){
      cout << "Output" << cnt << ": 1" << endl;
      continue;
    }
    if(a == 0 && b == 0 || a == 0 && b == 1){
      cout << "Output" << cnt << ": 0" << endl;
      continue;
    }
    cout << "Output" << cnt << ":" << flush;

    int mx = -1, idx;
    for(int i=a; i<=b; ++i){
      if(depth[i] > mx){
        mx = depth[i];
        idx = i;
      }
    }
    int tmp[T], size = 0;
    for(int i=idx; i !=15; i = next[i]){
      cout << ' ' << i ;
    }
    cout << ' ' << 15 << endl;
  }
  return 0;
}
