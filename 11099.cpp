#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cassert>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

//const lli Q = 148933 + 1, P = 2000000 + 1;

const lli Q = 78498 + 1, P = 2000000 + 1, MAX = 2000000;
const string msg = "Not Exist!";

bool prime[P];
lli pf[P][7];
lli ans[P];
int size = 0;

int main(void)
{
  fill(prime, prime + P, true); 
  prime[0] = prime[1] = false;
  for(lli i=2; i*i<P; ++i){
    for(lli j=2; i*j<P; ++j){
      lli k = i * j;
      prime[k] = false;
      if(prime[i]){
        if(pf[k][0] == 0)pf[k][0] = i;
        else if(pf[k][1] == 0)pf[k][1] = i;
        else if(pf[k][2] == 0)pf[k][2] = i;
        else if(pf[k][3] == 0)pf[k][3] = i;
        else if(pf[k][4] == 0)pf[k][4] = i;
        else if(pf[k][5] == 0)pf[k][5] = i;
        else if(pf[k][6] == 0)pf[k][6] = i;
        else assert(false);
      }
    }
  }

  lli n;
  while(scanf("%Ld", &n) != EOF){
    
    if(n == 1)puts(msg.c_str());
    else if(prime[n]){
      lli m = n * n;
      if(0 <= m && m <= MAX)printf("%Ld\n", m);
      else puts(msg.c_str());
    }
    else if(ans[n]){
      if(0 <= ans[n] && ans[n] <= MAX)printf("%Ld\n", ans[n]);
      else puts(msg.c_str());
    }
    else{
      const lli ini = MAX + 1;
      lli m = 1, re = ini;
      lli rem = n;
      int last;
      set<lli> s, t;
      for(int i=0; i<7 && pf[n][i]; ++i){
#ifdef TEST
        cout << "pf : " << pf[n][i] << endl;
#endif
        m *= pf[n][i];
        while(rem % pf[n][i] == 0)rem /= pf[n][i];
        last = i;
      }
      if(rem != 1){
        pf[n][last + 1] = rem;
        m *= rem;
#ifdef TEST
        cout << "pf : " << rem << endl;
#endif
      }
#ifdef TEST
      cout << "min : " << m << endl;
#endif
      s.insert(m);
      t = s;
      while(true){
        for(int i=0; i<7 && pf[n][i]; ++i){
          FOR(j, s){
            m = *j * pf[n][i];
#ifdef TEST
            cout << m << " : " << *j << " * " << pf[n][i] << endl;
#endif
            if(m <= 0)break;
            if(MAX < m)break;
            if(m < *j)break;
            if(m < pf[n][i])break;
            t.insert(m);
            if(n < m)re = min(re, m);
          }
        }
        if(s.size() == t.size())break;
        s = t; 
      }
      ans[n] = re;
      if(0 <= re && re <= MAX)printf("%Ld\n", re);
      else puts(msg.c_str());
    }
  }
  return 0;
}
