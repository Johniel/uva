#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int lli;

const lli p = 107, mod = 10000000000007LL;
const int L = 1005;

//int cnt[H];

int main(void)
{
  char s[L], t[L];
  //int mx[L];
  int i, j, h, size;
  bool flg;
  const int N = L * L;
  static pair<int, lli> hash[N];
  int h_size;
  while( gets(s) ){
    if( strlen(s) == 0 )break;
    //fill(cnt, cnt + H, 0);
    //fill(mx, mx + L, 0);
    size = 0;
    for(i=0; s[i]; ++i){
      if(s[i] == ' ')continue;
      t[ size++ ] = s[i];
    }
    h_size = 0;
    for(i=0; i<size; ++i){
      h = 0;
      for(j=i; j<size; ++j){
        h *= p;
        h += t[j] - 'A' + 1;
        h %= mod;        
        hash[ h_size++ ] = make_pair(j - i + 1, h);
      }
    }
    sort( hash, hash + h_size );
    flg = true;
    for(i=0, j=1; i<h_size; ++j){
      //cout << i << " : " << hash[i].first << ' ' << j << endl;
      if( hash[i].first != j )break;
      int cnt = 1;
      int mx = 0;
      for(++i; i < h_size; ++i){        
        if( hash[i].first != j )break;
        if( hash[i].second == hash[i-1].second )++cnt;
        else{
          mx = max(mx, cnt);
          cnt = 1;
        }
      }
      mx = max(mx, cnt);
      if( mx < 2 )break;
      flg = false;
      printf("%d\n", mx);
    }
    if(flg)puts("");
    puts("");
  }
  return 0;
}
