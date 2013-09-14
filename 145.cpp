#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

int main(void)
{
  int a, b, c, d;
  char dist;
  string s;
  double cost[5][3] = {{0.10, 0.06, 0.02}, 
                       {0.25, 0.15, 0.05}, 
                       {0.53, 0.33, 0.13}, 
                       {0.87, 0.47, 0.17}, 
                       {1.44, 0.80, 0.30}};
  while(cin >> dist >> s >> a >> b >> c >> d){
    int src = a * 60 + b;
    int dst = c * 60 + d;
    double sum = 0;
    int cnt[3] = {0, 0, 0};
    for(int i=src; i != dst; i = (i + 1) % (24 * 60)){
      if( 0 * 60 <= i && i < 8 * 60)sum += cost[dist - 'A'][2], ++cnt[2];
      if( 8 * 60 <= i && i < 18 * 60)sum += cost[dist - 'A'][0], ++cnt[0];
      if(18 * 60 <= i && i < 22 * 60)sum += cost[dist - 'A'][1], ++cnt[1];
      if(22 * 60 <= i && i < 24 * 60)sum += cost[dist - 'A'][2], ++cnt[2];
    }
    if(src != dst){
      printf("%10s%6d%6d%6d  %c%8.2lf\n", s.c_str(), cnt[0], cnt[1], cnt[2], dist, sum);
    }
    else{
      sum = 0;
      sum += cost[dist-'A'][0] * 600;
      sum += cost[dist-'A'][1] * 240;
      sum += cost[dist-'A'][2] * 600;
      printf("%10s%6d%6d%6d  %c%8.2lf\n", s.c_str(), 600, 240, 600, dist, sum);
    }
  }
  return 0;
}
/*
  183-5724     2     4     0   A  0.44
  183-5724     2     4     0  A    0.44
  183-5724     2     4     0  A  0.44
  183-5724     2     4     0  A    0.44
  183-5724     2     4     0  A    0.44*/
