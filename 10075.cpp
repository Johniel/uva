#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int lli;
#define R 6378
double dist(double a_lat,double b_lat,double a_long,double b_long){
  return R*acos(   cos(a_lat)*cos(b_lat)*cos(a_long-b_long)+sin(a_lat)*sin(b_lat) );
}

int main(void)
{
  const int V = 100 + 1;
  const lli inf = 1LL << 57;
  pair<double, double> p[V];
  lli g[V][V];
  int node, edge, q, tc = 0;  
  bool flg = true;
  string s, t;  

  while( cin >> node >> edge >> q && ( node | edge | q ) ){

    map<string, int> no;
    int cnt = 0;
    fill( &g[0][0], &g[V-1][V], inf );

    for(int i=0; i<node; ++i){
      cin >> s >> p[i].first >> p[i].second;
      p[i].first = p[i].first * M_PI / 180.0;
      p[i].second = p[i].second * M_PI / 180.0;
      g[ cnt ][ cnt ] = 0;
      no[ s ] = cnt++;
    }    

    for(int k=0; k<edge; ++k){
      cin >> s >> t;
      int i = no[s], j = no[t];
      if(i == j)continue;
      lli tmp = (lli)(dist( p[i].first, p[j].first, 
                            p[i].second, p[j].second ) + 0.5);
      g[i][j] = min(g[i][j], tmp);
    }

    for(int k=0; k<node; ++k){
      for(int i=0; i<node; ++i){
        for(int j=0; j<node; ++j){
          g[i][j] = min( g[i][j], g[i][k] + g[k][j] );
        }
      }
    }

    if(flg)flg = false;
    else cout << endl;
    cout << "Case #" << ++tc << endl; 
    while(q--){
      cin >> s >> t;     
      int a = no[s];
      int b = no[t];
      if( inf <= g[a][b] )cout << "no route exists" << endl;
      else cout << g[a][b] << " km" << endl;
    }
  }
  return 0;
}
