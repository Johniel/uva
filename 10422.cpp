#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

const int B = 5;

struct S{
  int i, j;
  char b[B][B];
  S(){}
};
bool operator < (const S &a, const S &b)
{
  for(int i=0; i<B; ++i){
    for(int j=0; j<B; ++j){
      if(a.b[i][j] != b.b[i][j])return a.b[i][j] < b.b[i][j];
    }
  }
  return false;
}

const int adj = 8;
const int di[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int dj[] = {-1, +1, -2, +2, -2, +2, -1, +1};

void output(S s)
{
  for(int i=0; i<B; ++i){
    for(int j=0; j<B; ++j){
      cout << s.b[i][j];
    }
    cout << endl;
  }
  cout << endl;
  return ;
}

map<S, int> bfs1(void)
{
  map<S, int> m;
  S ini;
  ini.i = ini.j = 2;
  for(int i=0; i<B; ++i){
    if(i == 2)ini.b[i][i] = '@';
    else if(i < 2)ini.b[i][i] = '1';
    else if(2 < i)ini.b[i][i] = '0';
    for(int j=i+1; j<B; ++j){
      ini.b[i][j] = '1';
      ini.b[j][i] = '0';
    }
  }
  queue<S> q;  
  m[ini] = 0;
  for(q.push(ini); q.size(); q.pop()){
    S n = q.front();
    if( 5 < m[n] )continue;
    for(int d=0; d<adj; ++d){
      int ni = n.i + di[d];
      int nj = n.j + dj[d];
      if(ni < 0 || nj < 0)continue;
      if(B <= ni || B <= nj)continue;      
      S tmp = n;
      swap( tmp.b[ tmp.i ][ tmp.j ], tmp.b[ ni ][ nj ] );
      tmp.i = ni;
      tmp.j = nj;
      if( m.find( tmp ) != m.end() )continue;
      m[ tmp ] = m[ n ] + 1;
      q.push( tmp );
    }
  }
  return m;
}

int bfs2(map<S, int> &a, S ini)
{
  map<S, int> b; 
  queue<S> q;  
  b[ini] = 0;
  for(q.push(ini); q.size(); q.pop()){
    S n = q.front();
    if( a.find( n ) != a.end() )return a[ n ] + b[ n ];
    if( 5 < b[n] )continue;
    for(int d=0; d<adj; ++d){
      int ni = n.i + di[d];
      int nj = n.j + dj[d];
      if(ni < 0 || nj < 0)continue;
      if(B <= ni || B <= nj)continue;      
      S tmp = n;
      swap( tmp.b[ tmp.i ][ tmp.j ], tmp.b[ ni ][ nj ] );
      tmp.i = ni;
      tmp.j = nj;
      if( b.find( tmp ) != b.end() )continue;
      b[ tmp ] = b[ n ] + 1;
      q.push( tmp );
    }
  }
  return -1;
}

int main(void)
{
  map<S, int> m = bfs1();
  int tc;
  cin >> tc;
  cin.ignore();
  while( tc-- ){
    S ini;
    for(int i=0; i<B; ++i){
      string s;
      getline(cin, s);
      for(int j=0; j<B; ++j){
        if( s[j] == ' ' ){
          ini.b[i][j] = '@';
          ini.i = i;
          ini.j = j;
        }
        else ini.b[i][j] = s[j];
      }
    }
    int r = bfs2(m, ini);
    if(10 < r)r = -1;
    if(r < 0)cout << "Unsolvable in less than 11 move(s)." << endl;
    else cout << "Solvable in " << r << " move(s)." << endl;
  }
  return 0;
}
