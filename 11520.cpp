#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 10;
char F[N][N];

inline bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

char select(vector<char> v)
{
  static bool used[CHAR_MAX];
  fill(used, used + CHAR_MAX, true);
  for(int i=0; i<v.size(); ++i){
    used[v[i]] = false;
  }
  for(int i='A'; ; ++i){
    if(used[i])return i;
  }
}

int main(void)
{
  const int adj = 4;
  int di[] = {0, 0, -1, 1};
  int dj[] = {-1, 1, 0, 0};
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int n;
    char m = '\0';
    cin >> n;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	cin >> F[i][j];
      }
    }    
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	if(F[i][j] == '.'){
	  vector<char> v;
	  for(int d=0; d<adj; ++d){
	    int ni = di[d] + i;
	    int nj = dj[d] + j;
	    if(isIn(ni, nj, n, n)){
	      v.push_back(F[ni][nj]);
	    }
	  }
	  F[i][j] = select(v);
	}
      }
    }
    cout << "Case " << ++cnt << ":" << endl;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	cout << F[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
