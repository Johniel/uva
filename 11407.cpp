#include <iostream>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

int main(void)
{
  const int N = 101, M = 10001;
  int num[N], tc, n, cnt[M];

  fill(cnt, cnt + M, 0);
  
  for(int i=0; i<M; ++i){
    for(int j=1; i + j * j<=M; ++j){
      if(cnt[i + j * j])
	cnt[i + j * j] = min(cnt[i + j * j], cnt[i] + 1);
      else cnt[i + j * j] = cnt[i] + 1;
    }
  }

  for(cin >> tc; tc--; ){
    cin >> n;
    cout << cnt[n] << endl;
  }
  return 0;
}
