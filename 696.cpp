#include <iostream>
#include <algorithm> 

using namespace std;

const int H = 500, W = 500;

int v[H][W];

void f(int i, int j, int h, int w, int a)
{
  const int adj = 8;
  const int di[] = {-2, -2, -1, -1, +1, +1, +2, +2};  
  const int dj[] = {-1, +1, -2, +2, -2, +2, -1, +1};
  for(int d = 0; d < adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(ni < 0 || nj < 0)continue;
    if(h <= ni || w <= nj)continue;
    v[ni][nj] += a;
  }
  v[i][j] += a;
  return ;
}

void bt(int h, int w, int i, int j, int &r, int d)
{
  r = max(r, d);
  for(; i < h; ++i){
    for(; j < w; ++j){
      if(v[i][j])continue;
      f(i, j, h, w, +1);
      bt(h, w, i, j+1, r, d+1);
      f(i, j, h, w, -1);
    }
    j = 0;
  }
  return ;
}

int calc(int h, int w)
{
  int mn = min(h, w);
  int mx = h + w - mn;
  if(h == 2 && w == 2)return 4;
  if(mn == 1)return mx;
  
  if(mn == 2){
    int r = (mx / 4) * 4;
    r += min(mx % 4, 2) * 2;
    return r;
  }
  
  return (h * w + 1) / 2;
}

int main(void)
{
  int h, w;
  while(cin >> h >> w && h){    
    int r = 0;

    int c = calc(h, w);
    
    cout << c << " knights may be placed on a ";
    cout << h << " row ";
    cout << w << " column board." << endl; 

    continue;
    bt(h, w, 0, 0, r, 0);


    cout << r << ' ' << calc(h, w) << endl;

    continue;
    cout << r << " knights may be placed on a ";
    cout << h << " row ";
    cout << w << " column board." << endl; 
  }
  return 0;
}
