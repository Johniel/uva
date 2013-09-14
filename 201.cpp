#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  const int N = 11;
  const int G = N * N;
  bool g[G][G];
  int n;
  int no[N][N], name = 0;
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      no[i][j] = name++;
    }
  }
  int tc = 0;
  while(cin >> n){
    fill(&g[0][0], &g[G-1][G], false);
    int m;
    cin >> m;
    while(m--){
      int i, j;
      char c; 
      cin >> c >> j >> i;
      --i;
      --j;
      if(c == 'V'){
        g[ no[i][j]   ][ no[i+1][j] ] = true;
        g[ no[i+1][j] ][ no[i][j]   ] = true;
      }
      if(c == 'H'){
        swap(i, j);
        g[ no[i][j]   ][ no[i][j+1] ] = true;
        g[ no[i][j+1] ][ no[i][j]   ] = true;
      }
    }
    map<int, int> r;
    for(int ai=0; ai<n; ++ai){
      for(int aj=0; aj<n; ++aj){
        for(int l=1; ai+l<n && aj+l<n; ++l){
          bool flg = true;
          for(int i=0; i<l && flg; ++i){
            flg = flg && g[ no[ai+i][aj] ][ no[ai+i+1][aj] ];
            flg = flg && g[ no[ai+i][aj+l] ][ no[ai+i+1][aj+l] ];
          }
          for(int j=0; j<l && flg; ++j){
            flg = flg && g[ no[ai][aj+j] ][ no[ai][aj+j+1] ];
            flg = flg && g[ no[ai+l][aj+j] ][ no[ai+l][aj+j+1] ];
          }
          if(flg)++r[l];
        }
      }
    }
    if(tc)cout << endl << "**********************************" << endl << endl;
    cout << "Problem #" << ++tc << endl << endl;
    if(r.size()){
      for(map<int, int>::iterator itr = r.begin(); itr != r.end(); ++itr){
        cout << itr->second << " square (s) of size " << itr->first << endl;
      }
    }
    else cout << "No completed squares can be found." << endl;
  }
  return 0;
}
