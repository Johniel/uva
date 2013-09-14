#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  int tc = 0, cnt = 0;
  map<char, int> M;
  M['a'] = 1;
  M['b'] = 2;
  M['c'] = 3;
  M['d'] = 1;
  M['e'] = 2;
  M['f'] = 3;
  M['g'] = 1;
  M['h'] = 2;
  M['i'] = 3;
  M['j'] = 1;
  M['k'] = 2;
  M['l'] = 3;
  M['m'] = 1;
  M['n'] = 2;
  M['o'] = 3;
  M['p'] = 1;
  M['q'] = 2;
  M['r'] = 3;
  M['s'] = 4;
  M['t'] = 1;
  M['u'] = 2;
  M['v'] = 3;  
  M['w'] = 1;
  M['x'] = 2;
  M['y'] = 3;
  M['z'] = 4;
  M[' '] = 1;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    int len = s.size(), sum = 0;
    REP(i, len)
      sum += M[s[i]];
    cout << "Case #" << ++cnt << ": " << sum << endl;
  }
  return 0;
}
