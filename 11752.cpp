#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef unsigned long long int lli;

int head(lli n)
{
  int cnt = 0;
  while(n){
    n = n >> 1;
    ++cnt;
  }
  return cnt;
}

lli power(lli n, lli p)
{
  if(p == 0)return 1;
  if(p == 1)return n;
  lli m = power(n, p / 2ll);
  lli tmp = m;
  m *= m;
  /*
  if(p % 2){
    tmp = m * n;
    return tmp;
  }
  else return m;
  */
  return p % 2 ? m * n : m;
}

int main(void)
{
  lli lim = 4294967296ll;
  lli p[] = {2, 3, 5, 7, 
             11, 13, 17, 19, 
             23, 29, 
             31, 37, 
             41, 43, 47, 
             53, 59, 
             61, 67, 
             71, 73, 79, 
             83, 89, 
             97};
  int len = sizeof(p) / sizeof(lli); 

  const lli P = 64;

  set<lli> x, y;
  for(int i=0; i<len; ++i){
    if(p[i] * p[i] <= P)x.insert(p[i] * p[i]);
    for(int j=0; j<len; ++j){
      if(p[i] * p[j] <= P)x.insert(p[i] * p[j]);
    }
  }
  
  while(true){
    int tmp = x.size();
    FOR(i, x){
      for(int j=0; j<len; ++j){
        if(*i * p[j] <= P)x.insert(*i * p[j]);
      }
    }
    if(tmp == x.size())break;
  }

  lli comp[x.size()];
  int size = 0;
  FOR(i, x)comp[size++] = *i;

  //for(int i=0; i<size; ++i)cout << comp[i] << ' ' ; cout << endl; return 0;

  set<lli> S;
  S.insert(1);
  
  for(int i=0; i<size; ++i){
    for(lli j=2; j<=lim; ++j){
      if(128 < head(j) * comp[i])break;
      lli tmp = power(j, comp[i]);
      if(tmp > 0){
        //cout << j << ' ' << comp[i] << ' ' << tmp << endl;
        S.insert(tmp);
      }
      else break;
    }
  }
  set<lli>::iterator itr;
  for(itr = S.begin(); itr != S.end(); ++itr){
    cout << *itr << endl;
  }
  return 0;
}
