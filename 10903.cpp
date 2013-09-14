#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
  const int P = 100 + 1;
  int win[P], lose[P];
  bool flg = true;
  char s[20], t[20];
  for(int n, m; scanf("%d%d", &n, &m) == 2 && n; ){
    if(flg)flg = false;
    else puts("");
    int game = m * n * (n - 1) / 2;
    fill(win, win + n, 0);
    fill(lose, lose + n, 0);
    for(int i=0; i<game; ++i){
      int a, b;
      scanf("%d %s %d %s", &a, s, &b, t);
      //printf("%d %s %d %s\n", a, s, b, t);
      --a;
      --b;
      if(s[0] == t[0])continue;
      if((s[0] == 'r' && t[0] == 'p') || 
	 (s[0] == 'p' && t[0] == 's') || 
	 (s[0] == 's' && t[0] == 'r')){
	++win[b];
	++lose[a];
      }
      else{
	++win[a];
	++lose[b];
      }
    }
    for(int i=0; i<n; ++i){
      if(win[i] + lose[i]){
	double w = win[i], l = lose[i];
	printf("%.3lf\n", w / (w + l));
      }
      else puts("-");
    }
  }
  return 0;
}
