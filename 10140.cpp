#include <iostream>
#include <algorithm>

using namespace std;

const int N = 70000;
static int p[N], size = 0;
static bool prime[N];

const int D = 1000000 + 1;
int q[D];
bool pr[D];

int gen(int a, int b)
{
  fill( pr, pr + D, true );
  if(a == 1)++a;
  for(int i=0; i<size; ++i){
    int begin;
    if( a % p[i] == 0 )begin = a % p[i];
    else begin = p[i] - a % p[i];
    if( a <= p[i] && p[i] <= b)begin += p[i];
    for(int j=begin; j<b-a+1; j+=p[i]){
      pr[j] = false;
    }
  }
  int len = 0;
  for(int i=0; i<b-a+1; ++i){
    if( pr[i] ) q[len++] = a + i;
  }
  return len;
}

int main(void)
{
  fill( prime, prime + N, true );
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i*j] = false;
    }
  }
  for(int i=0; i<N; ++i){
    if(prime[i]){
      p[size] = i;
      ++size;
    }
  }
  int a, b; 
  while( cin >> a >> b ){
    int mn = 2 * N, mx = -1;
    int s, t;
    int len = gen(a, b);
    for(int i=0; i+1<len; ++i){
      int tmp = q[i + 1] - q[i];
      if( mn > tmp ){
        mn = tmp;
        s = i;
      }
      if( mx < tmp ){
        mx = tmp;
        t = i;
      }
    }
    if( mn == 2 * N || mx == -1 ){
      cout << "There are no adjacent primes." << endl;
    }
    else{
      cout << q[s] << "," << q[s+1] << " are closest, " ;
      cout << q[t] << "," << q[t+1] << " are most distant." << endl;
    }
  }
  return 0;
}
