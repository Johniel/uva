#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 40000;

int p[N], size = 0;

int solve(int n)
{
  queue<int> q;
  for(int i=0; i<n; ++i){
    q.push(i + 1);
  }
  for(int i=0, len; i<n-1; ++i){
    len = p[i] % q.size();
    if( len == 0 ) len = q.size();
    if( i )--len;
    for(int j=0; j<len; ++j){
      q.push( q.front() );
      q.pop();
    }
    cout << "killed : " << q.front() << endl;
    q.pop();
  }
  return q.front();
}

int main(void)
{
  bool prime[N];
  fill( prime, prime + N, true );
  prime[0] = prime[1] = false;
  for( int i=2; i*i < N; ++i){
    for( int j=2; i*j < N; ++j){
      prime[i * j] = false;
    }
  }
  for(int i=0; i<N; ++i){
    if( prime[i] )p[size++] = i;
  }

  int n;
  while( cin >> n && n ){
    //cout << solve( n ) << endl;
    int survivor(int);
    cout << survivor( n ) <<endl;
  }
  return 0;
}
int survivor(int n)
{
   int i, s;
   for (s = 0, i = 1; i <= n; i++)
      s = (s + p[n - i]) % i; 
   return (s + 1);
}
