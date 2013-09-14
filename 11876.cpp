#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int P = 78498;
const lli N = 1000000 + 1;
int nod[N];

int n[N];

int p[N], size = 0;

void init(void)
{ 
  bool prime[N];
  fill( prime, prime + N, true );
  prime[0] = prime[1] = false;

  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i*j] = false;
    }
  }
  for(int i=0; i<N; ++i){
    if( prime[i] ) p[ size++ ] = i;
  }

  for(lli i=1; i<N; ++i){    
    for(lli j=1; i*j<N; ++j){
      lli k = i * j;
      ++nod[k];
    }
  }

  n[0] = 1;
  for(lli i=1; i<N; ++i){
    n[i] = n[i-1] + nod[ n[i-1] ];
  }


  //for(int i=0; i<10; ++i) cout << n[i] << ' '; cout << endl;

  return ;
}

int main(void)
{
  init();

  int cnt = 0;
  int tc;
  cin >> tc;
  while( tc-- ){    
    int a, b;
    cin >> a >> b;
    int *s = lower_bound( n, n + N, a );
    int *t = upper_bound( n, n + N, b );
    cout << "Case " << ++cnt << ": " << (int)(t - s) << endl;
  }
  return 0;
}
