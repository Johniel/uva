#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

lli a2l(string s)
{
  lli sum = 0;
  lli w = 1;
  reverse(ALL(s));
  REP(i, s.size()){
    if(s[i] == '1')sum += w;
    w <<= 1;
  }
  return sum;
}

lli greedy(int o, int z)
{
  string s;
  while(1 < o && 0 < z){
    s += "101";
    o-=2;
    z-=1;
  }
  if(o && z){
    return min(a2l(s + "01"), a2l("01" + s));
  }
  else if(o){
    return a2l(s + string(o, '1'));
  }
  else if(z){
    return a2l(s);
  }
  else return a2l(s);
}

int main(void)
{
  int tc, p, q;
  for(cin >> tc; tc-- && cin >> p >> q;
      cout << greedy(p, q) << endl);
  return 0;
}
