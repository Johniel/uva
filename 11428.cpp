#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 10000, M = 59;
  lli num[59];
  int cnt = 0;
  num[0] = 0;
  for(lli i=1; ; ++i){
    if(i * i * i - num[cnt] >= N)break;
    num[++cnt] = i * i * i;
  }
 
  for(lli n; cin >> n; ){
    if(n == 0)break;
    bool flg = true;
    for(int j=0; j<cnt; ++j){
      for(int i=0; i<cnt; ++i){
	if(n == num[j] - num[i]){
	  flg = false;
	  cout << j << ' ' << i << endl;
	  i = j = 1 << 20;
	}
      }
    }
    if(flg)cout << "No solution" << endl;
  }
  return 0;
}
