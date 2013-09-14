#include <iostream>
#include <algorithm>
#include <climits>

#define REP(i, n) for(int i=0; i<n; ++i)

using namespace std;

static const int TOTAL = 100 * 100 + 1;
static const int LEN = 100 + 1;

static char text[TOTAL], s[LEN];

int main(void)
{
  int tc, n, l, cnt;
  bool flg;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d%d", &l, &n);
    //fill(text, text + l * n + 1, '\0');fill(s, s + l + 1,  '\0');
    cnt = l;
    scanf("%s", text);
    REP(i, n-1){
      scanf("%s", s);
      for(int j=0; j<l; ++j){
	flg = true;
	for(int k=0; k<l-j; ++k){
	  flg = (text[cnt-l+j+k] == s[k]);
	  if(!flg)break;
	}
	if(flg){
	  sprintf(text + j + cnt-l, "%s", s);
	  cnt += j;
	  break;
	}
      }
      if(!flg){
	strcat(text, s);
	cnt += l;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
