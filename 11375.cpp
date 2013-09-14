#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <cassert>
#include <cstdio>
#include <sstream>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

const lli BASE = 1000000000000000000ll;
const int V = 27;

struct BigInt{
  lli v[V];
  int size;
  BigInt(){
    fill(v, v + V, 0);
    size = 1;
  }
  BigInt(int n){
    fill(v, v + V, 0);
    size = 1;
    v[0] = n;
  }  
};

inline
void reg(BigInt &bi)
{
  lli c = 0;
  for(int i=0; i<bi.size + 1; ++i){
    bi.v[i] += c;
    c = bi.v[i] / BASE;
    bi.v[i] %= BASE;
    if(bi.v[i])bi.size = i + 1;
  }
  return ;
}

inline
bool operator == (const BigInt &a, const BigInt &b)
{
  int lim = max(a.size, b.size);
  for(int i=0; i<lim; ++i){
    if(a.v[i] != b.v[i])return false;
  }
  return true;
}

inline
BigInt operator + (const BigInt &a, const BigInt &b)
{
  BigInt r(0);
  int lim = max(a.size, b.size);
  for(int i=0; i<lim; ++i){
    r.v[i] = a.v[i] + b.v[i];
  }
  reg(r);
  return r;
}

inline
string toString(const BigInt &bi)
{
  string s, t;
  ostringstream oss;
  char buff[256];
  for(int i=0; i<bi.size; ++i){
    sprintf(buff, "%018lld", bi.v[i]);
    s = string(buff);
    reverse(s.begin(), s.end());
    oss << s;
  }
  s = oss.str();
  reverse(s.begin(), s.end());
  bool flg = false;
  for(int i=0; i<s.size(); ++i){      
    if(s[i] != '0'){
      flg = true;
    }
    if(flg)t += s[i];
  }
  return t.size() ? t : "0";
}

#include <cstring>

inline
void output(const BigInt &bi)
{
  char buff[256];
  bool flg = false;
  for(int i=bi.size-1; 0<=i; --i){
    sprintf(buff, "%018lld", bi.v[i]);
    int len = strlen(buff);
    for(int j=0; j<len; ++j){
      if(buff[j] != '0')flg = true;
      if(flg)printf("%c", buff[j]);
    }
  }
  if(flg)puts("");
  else puts("0");
  return ;
}

const int m[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

const int D = 2000 + 1;
const int M = 10;
const BigInt zero(0), one(1);
static BigInt t[D][M];
BigInt mx;

void dp(int n)
{
  fill(&t[0][0], &t[D-1][M], zero);
  for(int i=1; i<10; ++i){
    if(m[i] <= n){
      t[n - m[i]][i] = one;
    }
  }
  for(int i=n; i; --i){
    for(int j=0; j<10; ++j){
      //if(t[i][j] == zero)continue;
      if(t[i][j].size == 1 && t[i][j].v[0] == 0)continue;
      for(int k=0; k<10; ++k){
	if(m[k] <= i){
	  t[i - m[k]][k] = t[i - m[k]][k] + t[i][j];
	}
      }
    }
  }
  BigInt sum(0);
  for(int i=0; i<n; ++i){
    for(int j=0; j<M; ++j){
      sum = sum + t[i][j];
    }
  }
  if(m[0] <= n)sum = sum + one;
  mx = sum;
  return ;
}

inline
void calc(int n)
{
  BigInt sum(0);
  for(int i=2000; i >= 2000-n; --i){
    for(int j=0; j<M; ++j){
      sum = sum + t[i][j];
    }
  }
  if(m[0] <= n)sum = sum + one;
  output(sum);
  return ;
}

int main(void)
{
  dp(2000);
  for(int n; scanf("%d", &n) == 1; calc(n));
  return 0;
}
