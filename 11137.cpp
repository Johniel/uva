#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 22, M = 10000 + 1;
  static lli coin[N], t[N][M];
  for(lli i=0; i<N; ++i){
    coin[i] = i * i * i;
  }

  fill(&t[0][0], &t[N-1][M], 0);
  for(int i=1; i<M; ++i){
    t[1][i] = 1;
  }

  for(int i=0; i<N; ++i){
    t[i][0] = 1;
  }

  for(int i=1; i<N; ++i){    
    for(int j=1; j<M; ++j){
      t[i][j] = t[i-1][j];
      if(0 <= j - coin[i]){
	//t[i][j] += t[i-1][j - coin[i]];
	t[i][j] += t[i][j - coin[i]];
      }
    }
  }
  /*
  for(int i=0; i<20; ++i){    
    cout << i << ' ' ;
  }
  cout << endl;
  for(int i=1; i<20; ++i){    
    for(int j=0; j<20; ++j){
      cout << t[i][j] << ' ' ;
    }
    cout << endl;
  }
  */
  for(int n; cin >> n;){
    cout << t[N-1][n] << endl;
  }
  return 0;
}
