#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int M = 2050;
const int N = 1030;
int m[2050];
int buff[M], len;
set<int> vis[M][N];

bool rec(int depth, int sum, int add, int n, int size)
{
  sum %= n;
  if( depth == size ){
    if( add != n )return false;
    else return sum == 0;
  }
  if( add == n ){
    return sum == 0;
  }
  if( vis[depth][add].count( sum ) )return false;
  vis[depth][add].insert( sum );
  bool flg;
  flg = rec( depth + 1, sum + m[depth], add + 1, n, size);
  if(flg){
    buff[ len++ ] = m[depth];
    return true;
  }
  flg = rec( depth + 1, sum, add, n, size);
  if(flg)return true;
  return false;
}

int main(void)
{
  int n;
  while( cin >> n && n ){
    const int size = 2 * n - 1;
    fill( &vis[0][0], &vis[M-1][1000], set<int>() );
    for(int i=0; i<size; ++i){
      cin >> m[i];
    }
    len = 0;
    if( rec(0, 0, 0, n, size) ){
      reverse( buff, buff + len );
      cout << "Yes" << endl;
      for(int i=0; i<n; ++i){
        if(i)cout << ' ';
        cout << buff[i];
      }
      cout << endl;
    }
    else cout << "No" << endl;
  }  
  return 0;
}
