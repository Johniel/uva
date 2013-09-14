#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int H = 10;
const int W = 10;

int main(void)
{
  char g[H][W];
  bool vis[H][W];
  int no[H][W];
  int h, w;
  int tc = 0, cnt;
  while(cin >> h >> w){
    if(tc)puts("");
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cin >> g[i][j];
        no[i][j] = 0;
      }
    }
    cnt = 0;

    fill(&vis[0][0], &vis[H-1][W], false);
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(g[i][j] == '*')continue;
        if(vis[i][j])continue;
        no[i][j] = ++cnt;
        for(int k=j; k<w; ++k){
          if(g[i][k] == '*')break;
          vis[i][k] = true;
        }
      }
    }
    fill(&vis[0][0], &vis[H-1][W], false);
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(g[i][j] == '*')continue;
        if(vis[i][j])continue;
        no[i][j] = ++cnt;
        for(int k=i; k<h; ++k){
          if(g[k][j] == '*')break;
          vis[k][j] = true;
        }
      }
    }
    cnt = 0;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(no[i][j])no[i][j] = ++cnt;
      }
    }    
    /*
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        printf("%3d", no[i][j]);
      }
      puts("");
    }
    */
    
    printf("puzzle #%d:\n", ++tc);
    puts("Across");
    fill(&vis[0][0], &vis[H-1][W], false);
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(g[i][j] == '*')continue;
        if(vis[i][j])continue;
        string s;
        for(int k=j; k<w; ++k){
          if(g[i][k] == '*')break;
          vis[i][k] = true;
          s += g[i][k];
        }
        printf("%3d.%s\n", no[i][j], s.c_str());        
      }
    }


    puts("Down");
    fill(&vis[0][0], &vis[H-1][W], false);
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(g[i][j] == '*')continue;
        if(vis[i][j])continue;
        string s;
        for(int k=i; k<h; ++k){
          if(g[k][j] == '*')break;
          vis[k][j] = true;
          s += g[k][j];
        }
        printf("%3d.%s\n", no[i][j], s.c_str());        
      }
    }
  }
  return 0;
}
