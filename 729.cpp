#include <iostream>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

struct HD{
  int v;
  string s;
  HD(string t){
    v = 0;
    for(int i=0, b=1; i<t.size(); ++i, b*=2){
      if(t[i] == '1')v += b;
    }      
    reverse(t.begin(), t.end());
    s = t;
    return ;
  }
};

bool operator < (HD a, HD b)
{
  return a.v < b.v; 
}

void backTruck(bool available[], int l, int d, string &s, int p, set<HD> &S)
{
  if(d == l){
    S.insert(HD(s));
    return ;
  }
  for(int i=p; i<s.size(); ++i){
    if(available[i]){
      available[i] = false;
      s[i] = '1';
      backTruck(available, l, d + 1, s, i+1, S);
      available[i] = true;
      s[i] = '0';      
    }
  }
  return ;
}

int main(void)
{
  int tc;
  cin >> tc;  
  bool available[16];
  fill(available, available + 16, true);
  while(tc--){
    int n, l;    
    cin >> l >> n;
    string s(l, '0');
    set<HD> S;
    backTruck(available, n, 0, s, 0, S);    
    FOR(i, S)cout << i->s << endl;
    if(tc)cout << endl;
  }
  return 0;
}
