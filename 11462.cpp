#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
  int cnt[100 + 1], m;
  for(int n; ; ){    
    scanf("%d", &n);
    if(n == 0)break;
    fill(cnt, cnt + 100, 0);
    for(int i=0; i<n; ++i){
      scanf("%d", &m);
      ++cnt[m];
    }
    bool flg = true;
    for(int i=0; i<100; ++i){
      for(int j=0; j<cnt[i]; ++j){
	if(flg)flg = false;
	else printf(" ");
	printf("%d", i);
      }    
    }
    puts("");
  }
  return 0;
}

