#include <iostream>
#include <algorithm>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int SIZE = 8;

int main(void)
{
  int tc;
  char G[SIZE][SIZE];
  cin >> tc;
  while(tc--){
    REP(i, SIZE){
      REP(j, SIZE)
	cin >> G[i][j];
    }
    
  }
  return 0;
}
