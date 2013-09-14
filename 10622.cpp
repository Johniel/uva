#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

int gcd(int a, int b)
{
  return b? gcd(b, a%b) : a;
}

int main(void)
{
  const int P = 4792 + 1;
  vector<int> prime;
  int p[P];
  prime.push_back(2);
  for(int i=3; i*i < INT_MAX && 0 < i*i; i+=2){
    bool flg = true;
    FOR(j, prime){
      if(i % *j == 0){
	flg = false;
	break;
      }
    }
    if(flg){
      prime.push_back(i);
    }
  }
  int size = 0, f[P];
  FOR(i, prime)p[size++] = *i;
  for(int n; cin >> n && n; ){
    int cnt = 0;
    fill(f, f + P, 0);
    REP(i, size){
      if(n % p[i])continue;
      while(n % p[i] == 0){
	++f[cnt];
	n /= p[i];
      }
      ++cnt;
    }
    if(abs(n) != 1)f[cnt++] = 1;

    int m = f[cnt - 1];
    REP(i, cnt - 1){
      m = gcd(max(m, f[i]), min(m, f[i]));
    }
    
    if(n < 0){
      while(m % 2 == 0){
	m /= 2;
      }
    }
    cout << m << endl;
  }
  return 0;
}
