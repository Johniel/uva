#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli t[5][4][8][8][8][8][5][4];

lli rec( int first_color, int first_size, int a, int b, int c, int d, int prev, int last)
{
  if( a == 0 && b == 0 && c == 0 && d == 0){ 
    if( prev == first_color || last == first_size )return 0;
    else return 1;
  }
  if( t[first_color][first_size][a][b][c][d][prev][last] != -1 ){
    return t[first_color][first_size][a][b][c][d][prev][last];
  }
  lli sum = 0;
  int u[4] = {a, b, c, d};
  for(int i = 0; i < 4; ++i){
    for(int j = 1; j <= min(u[i], 3); ++j){
      if( prev == i )continue;
      if( last == j )continue;
      int fc = first_color, fs = first_size;
      if( fc == 4 )fc = i;
      if( fs == 0 )fs = j;
      u[i] -= j;
      sum += rec(fc, fs, u[0], u[1], u[2], u[3], i, j);
      u[i] += j;
    }
  }
  return t[first_color][first_size][a][b][c][d][prev][last] = sum;
}

lli call_rec(int m[])
{
  if( count( m, m + 4, 0 ) == 4 ) return 1;
  //fill(&t[0][0][0][0][0][0][0][0], &t[5-1][4-1][8-1][8-1][8-1][8-1][5-1][4], -1);
  return rec(4, 0, m[0], m[1], m[2], m[3], 4, 0);
}

int main(void)
{
  fill(&t[0][0][0][0][0][0][0][0], &t[5-1][4-1][8-1][8-1][8-1][8-1][5-1][4], -1);
  int tc;
  int m[4];
  cin >> tc;
  while( tc-- ){
    int n;
    cin >> n;
    fill(m, m + 4, 0);
    for(int i=0; i<n; ++i){
      cin >> m[i];
    }
    cout << call_rec( m ) << endl;
  }
  return 0;
}
