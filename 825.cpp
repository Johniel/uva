#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{ 
  const int adj = 2;
  const int di[] = {0, 1};
  const int dj[] = {1, 0};
  int h, w, n, m, tc;
  for(cin >> tc; tc--; ){
    cin >> w >> h;
    int cnt[h+1][w+1];
    fill(&cnt[0][0], &cnt[h-1][w], 0);
    for(int i=0; i<w; ++i){
      string s;
      cin >> m;
      getline(cin, s);
      istringstream iss(s);
      while(iss >> n){
	cnt[n-1][m-1] = -1;
      }
    }
    cnt[0][0] = 1;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(cnt[i][j] == -1)continue;
	for(int k=0; k<adj; ++k){
	  int ni = i + di[k];
	  int nj = j + dj[k];
	  if(cnt[ni][nj] == -1)continue;
	  cnt[ni][nj] += cnt[i][j];
	}
      }
    }
    cout << max(cnt[h-1][w-1], 0) << endl;
    if(tc)cout << endl;
  }
  return 0;
}
