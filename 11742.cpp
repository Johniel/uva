#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 9, M = 20, INF = 1 << 20;
  for(int n, m, rmin[M][M], rmax[M][M], s[M]; cin >> n >> m && n; ){
    fill(&rmin[0][0], &rmin[M-1][M], INF);
    fill(&rmax[0][0], &rmax[M-1][M],  INF);
    for(int i=0; i<m; ++i){
      int a, b, c;
      cin >> a >> b >> c;
      if(c < 0)
	rmin[b][a] = rmin[a][b] = min(rmin[a][b], c);
      else 
	rmax[b][a] = rmax[a][b] = min(rmax[a][b], c);
    }
    for(int i=0; i<n; s[i] = i++);
    int cnt = 0;
    do{
      bool flg = true;
      for(int i=0; i<n && flg; ++i){
	for(int j=1; i+j<n && flg; ++j){
	  //cout << s[i] << ' ' << s[i+j] << ' ' << rmax[s[i]][s[i+j]] << endl;
	  flg &= (rmin[s[i]][s[i+j]] == -INF || rmin[s[i]][s[i+j]] >= -j);
	  flg &= (rmax[s[i]][s[i+j]] ==  INF || rmax[s[i]][s[i+j]] >= j);
	}
      }
      //if(flg){ for(int i=0; i<n; ++i)cout << s[i] << ' '; cout << endl; }
      cnt += flg;
    }while(next_permutation(s, s + n));
    cout << cnt << endl;
  }
  return 0;
}
