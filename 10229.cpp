#include <iostream>
#include <algorithm>

using namespace std;

/*
| 0 1 |^n 
| 1 1 |

 equal

|fn-2 fn-1 |
|fn-1 fn   |

*/

typedef long long int lli;

lli mod;

struct M{
  lli m[2][2];
  M(){
    m[0][0] = 0;
    m[0][1] = m[1][0] = m[1][1] = 1;
  }
};
M operator * (const M &a, const M &b)
{
  M c;
  c.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[1][0] * b.m[0][1];
  c.m[0][1] = a.m[0][1] * b.m[0][0] + a.m[1][1] * b.m[0][1];
  c.m[1][0] = a.m[0][0] * b.m[1][0] + a.m[1][0] * b.m[1][1];
  c.m[1][1] = a.m[0][1] * b.m[1][0] + a.m[1][1] * b.m[1][1];
  c.m[0][0] %= mod;
  c.m[0][1] %= mod;
  c.m[1][0] %= mod;
  c.m[1][1] %= mod;
  return c;
}

M pow(M r, lli p)
{
  if(p == 1)return r;
  if(p == 2)return r * r;
  M tmp = pow(r, p/2);
  tmp = tmp * tmp;
  return p%2 ? tmp * r : tmp;
}

int main(void)
{
  lli n;
  while( cin >> n >> mod ){
    if(n == 0){
      cout << 0 << endl;
    }
    else{
      mod = 1 << mod;
      cout << pow( M(), n + 1 ).m[0][0] << endl;
    }
  }
  return 0;
}
