#include <iostream>
#include <algorithm>

using namespace std;

static const int H = 25, W = 25;

bool F[H][W];

int floodFill(int pi, int pj, int h, int w)
{
  static const int adj = 8;
  static const int di[] = {-1, -1, -1,  0, 0,  1, 1, 1};
  static const int dj[] = {-1,  0,  1, -1, 1, -1, 0, 1};
  int cnt = 1;
  F[pi][pj] = 0;
  for(int d=0; d<adj; ++d){
    int ni = pi + di[d], nj = pj + dj[d];
    if(ni < 0 || h <= ni || nj < 0 || w <= nj || !F[ni][nj])continue;
    cnt += floodFill(ni, nj, h, w);
  }
  return cnt;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    cin.ignore();
    getline(cin, s);
    int h = s.size();
    int w = s.size();
    for(int i=0; i<w; ++i)
      F[0][i] = (s[i] == '1');
    for(int i=1; i<h; ++i){
      getline(cin, s);
      for(int j=0; j<w; ++j){
	F[i][j] = (s[j] == '1');
      }
    }
    int result = 0;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(F[i][j])
	  result = max(result, floodFill(i, j, h, w));
      }
    }    
    cout << result << endl;
    if(tc)cout << endl;
  }
  return 0;
}
