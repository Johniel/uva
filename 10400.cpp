#include <iostream>
#include <algorithm>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int N = 100 + 1;
const int M = 32000 * 2 + 1, BASE = 32000;

int num[N], t[N][M];

#define t(i, j) t[i][j + BASE]

void dp(int n, int r)
{  
  fill(&t[0][0], &t[N-1][M], -1);
  t(0, num[0]) = 0;
  for(int i=1; i<n; ++i){
    for(int j=-M/2; j<=M/2; ++j){
      if(t(i-1, j) == -1)continue;  

      if(0 <= j * num[i] + BASE && j * num[i] + BASE < M){
	t(i, j * num[i]) = j + BASE;
      }

      if(0 <= j + num[i] + BASE && j + num[i] + BASE < M){
	t(i, j + num[i]) = j + BASE;
      }

      if(0 <= j - num[i] + BASE && j - num[i] + BASE < M){
	t(i, j - num[i]) = j + BASE;
      }      

      if(num[i]){
	t(i, j / num[i]) = j + BASE;
      }
    }
  }
  int eq = r;
  int prev = t(n-1, r);
  if(prev == -1)cout << "NO EXPRESSION" << endl;
  else{
    string s = "";
    for(int i=n; i--; ){
      prev -= BASE;

      if(prev * num[i] == r){
	s += '*';
      }
      else if(prev + num[i] == r){
	s += '+';
      }
      else if(prev - num[i] == r){
	s += '-';
      }
      else if(prev / num[i] == r){
	s += '/';
      }
      if(i){
	r = prev;
	prev = t(i-1, r);
      }
    }
    reverse(s.begin(), s.end());
    s += '=';
    for(int i=0; i<n; ++i)cout << num[i] << s[i];
    cout<< eq << endl;
  }
  return ;
}

int main(void)
{
  int tc, n, r;
  for(cin >> tc; tc--; ){
    cin >> n;
    for(int i=0; i<n; ++i)cin >> num[i];
    cin >> r;
    dp(n, r);
  }
  return 0;
}

