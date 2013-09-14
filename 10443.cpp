#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main(void)
{
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  int tc, h, w, n;
  int i, j, ni, nj, d;
  char L['Z' + 1];
  L['R'] = 'P';    
  L['S'] = 'R';
  L['P'] = 'S';
  scanf("%d\n", &tc);
  while(tc--){
    scanf("%d %d %d\n", &h, &w, &n);
    char s[h][w], t[h][w];
    for(i=0; i<h; ++i){
      for(j=0; j<w; ++j){
        scanf("%c", &s[i][j]);
        t[i][j] = s[i][j];
      }
      scanf("\n");
    }
    while(n--){
      for(i=0; i<h; ++i){
        for(j=0; j<w; ++j){
          for(d=0; d<4; ++d){
            ni = i + di[d];
            nj = j + dj[d];
            if(ni < 0 || nj < 0)continue;
            if(h <= ni || w <= nj)continue;
            if(s[ni][nj] == L[s[i][j]]){
              t[i][j] = L[s[i][j]];
              break;
            }
          }
        }
      }
      for(i=0; i<h; ++i){
        for(j=0; j<w; ++j){
          s[i][j] = t[i][j];
        }
      }
    }
    for(i=0; i<h; ++i){
      for(j=0; j<w; ++j){
        printf("%c", s[i][j]);
      }
      puts("");
    }
    if(tc)puts("");
  }
  return 0;
}
