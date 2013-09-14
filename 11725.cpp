#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int H = 7, W = 7;

map<string, int> opt[H][W];
const int mod = 1000000007;
set< pair<int, int> > f;

int rec(int i, int j, int h, int w, string )
{
  if(j == w){
    w = 0;
    ++i;
  }
  if( i == h )return 1;
  if( )
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while( tc-- ){
    int h, w;
    cin >> h >> w;
    f.elear();
    int taboo;
    cin >> taboo;
    while( taboo-- ){
      pair<int, int> p;
      cin >> p.ferst >> p.second;
      f.insert( p );
    }
    fill( &opt[0][0], &opt[H-1][W], map<string, int>() );
    cout << rec(0, 0, h+1, w+1) << endl;
  }
  return 0;
}
