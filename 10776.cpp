#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

typedef long long int lli;

const int U = 30 + 1, C = 'z' + 1;

int sub[C];
int freq[C];
pair<char, int> p[C];

void bt(string s, int i, int lim, int sum)
{  
  if(lim > sum){
    return ;
  }
  if(lim == 0){
    cout << s << endl;
    return ;
  }
  if(p[i].first == -1)return ;
  for(int j=p[i].second; 0 < j; --j){
    if(lim < j)continue;
    string t = s + string(j, p[i].first);
    bt(t, i + 1, lim - j, sum - p[i].second);
  }
  bt(s, i + 1, lim, sum - p[i].second);
  return ; 
}

int main(void)
{ 
  string s;
  int n;
  while(cin >> s >> n){
    fill(freq, freq + C, 0);
    fill(sub, sub + C, 0);    
    FOR(i, s){
      ++freq[*i];
      if(n < freq[*i])freq[*i] = n;
    }
    int size = 0, sum = 0;
    for(int i=0; i<C; ++i){
      if(freq[i] == 0)continue;
      p[size++] = make_pair(i, freq[i]);
      sum += freq[i];
    }				
    p[size].first = -1;
    bt("", 0, n, sum);
  }
  return 0;
}
