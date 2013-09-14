#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int L = 10000;
  int H[L], W[L], _h, _w;
  int adj = 5, tc = 0;
  int di[] = {0, 0, -1, 1, 0};
  int dj[] = {-1, 1, 0, 0, 0};
  for(int h, w, e; ; ){
    cin >> h >> w >> e;
    if(h + w + e == 0)break;
    fill(H, H + L, false);
    fill(W, W + L, false);
    for(int i=0; i<e; ++i){
      cin >> _h >> _w;
      H[_h] = W[_w] = true;
    }
    cin >> _h >> _w;
    bool flg = true;
    cout << "Case " << ++tc << ": ";
    for(int d=0; d<adj; ++d){
      int ni = _h + di[d], nj = _w + dj[d];
      if(0 <= ni && ni < h && 0 <= nj && nj < w){
	if(!H[ni] && !W[nj]){
	  cout << "Escaped again! More 2D grid problems!" << endl;
	  flg = false;
	  break;
	}
      }
    }
    if(flg){
      cout << "Party time! Let's find a restaurant!" << endl;
    }
  }
  return 0;
}
