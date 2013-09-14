#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;  

int main(void)
{
  int m[100][100], h[100], w[100];
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    REP(i, n){
      REP(j, n)
	cin >> m[i][j];
    }    
    REP(i, n-1){
      int b;
      b = 0;
      REP(j, n-1)b ^= m[i][j];
      w[i] = b;
      b = 0;
      REP(j, n-1)b ^= m[j][i];
      h[i] = b;      
    }
    REP(i, n-1){
      
    }
  }
  return 0;
}
