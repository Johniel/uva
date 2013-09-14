#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int lli;

const int N = 100 + 1;
const int D = 4 + 1;
lli p[N][D];
lli q[N][D];

void init(void)
{  
  for(int i=1; i<N; ++i){
    for(int j=0; j<D; ++j){
      if(j)p[i][j] = p[i][j-1] * i;
      else p[i][j] = i * i;
    }
  }
  for(int i=1; i<N; ++i){
    for(int j=0; j<D; ++j){
      if(i)p[i][j] += p[i-1][j];
    }
  }
  for(lli i=1; i<N; ++i){                       
    lli n = (i + 1) * i / 2.0;
    q[i][0] = n * n - p[i][0];
    q[i][1] = n * n * n - p[i][1];
    q[i][2] = n * n * n * n - p[i][2];
  }
  return ;
}

int main(void)
{
  init();
  int n;
  while( cin >> n ){ 
    if(n){
      //cout << p[n][0] << ' ' << p[n][1] << ' ' << p[n][2] << endl;
      /*
      for(int i=0; i<3; ++i){
        if(i)cout << ' ';
        cout << p[n][i] << ' ' << p[n][i+1] - p[n][i] << flush;
      }
      cout << endl;
      */
      cout << p[n][0] << ' ' << q[n][0] << ' '; 
      cout << p[n][1] << ' ' << q[n][1] << ' '; 
      cout << p[n][2] << ' ' << q[n][2] << endl;
    }
    else cout << "0 0 0 0 0 0" << endl;
  }
  return 0;
}
