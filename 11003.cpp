#include <iostream>
#include <algorithm>

using namespace std;

const int B = 1000 + 10;
struct Box{ int w, l; } b[B];

const int T = 3000 + 10;
int t[B][T];

int dp(int size)
{
  fill(&t[0][0], &t[B-1][T], 0);
  for(int i=0; i<size; ++i){
    for(int j=0; j<T; ++j){
      if(j <= b[i].l)t[i][j] = 1;
      if(i)t[i][j] = max(t[i][j], t[i - 1][j]);
      if(i && j + b[i].w < T && j <= b[i].l){
        t[i][j] = max(t[i][j], t[i - 1][j + b[i].w] + 1);
      }
    }
  }
  return t[size-1][0];
}
//weight and maximum load of each box respectively. 
int main(void)
{
  int n;
  while( cin >> n && n ){
    for(int i=0; i<n; ++i){
      cin >> b[i].w >> b[i].l;
    }
    cout << dp(n) << endl;
  }
  return 0;
}
