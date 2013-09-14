#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 10000 + 1;
set<int> vis[N];
int n[N];

bool rec(int size, int div, int sum, int depth)
{
  sum %= div;
  if( size == depth ){
    return sum % div == 0;
  }
  if( vis[depth].count(sum) ) return false;
  vis[depth].insert( sum );
  bool tmp;
  tmp = rec(size, div, sum + n[depth], depth + 1);
  if(tmp)return true;
  tmp = rec(size, div, sum - n[depth], depth + 1);
  if(tmp)return true;
  return false;
}

int main(void)
{
  int tc;
  cin >> tc;
  while( tc-- ){
    int size, m;
    cin >> size >> m;
    for(int i=0; i<size; ++i){
      cin >> n[i];
    }
    fill( vis, vis + size, set<int>() );
    cout << ( rec(size, m, n[0], 1) ? "Divisible" : "Not divisible" ) << endl;
  }
  return 0;
}
