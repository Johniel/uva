#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 9;
  int tc, t[N][N];
  for(cin >> tc; tc--; ){
    fill(&t[0][0], &t[N-1][N], -1);
    for(int i=0; i<N; i+=2){
      for(int j=0; j<i+1; j+=2)
	cin >> t[i][j];
    }    
    for(int i=2; i<N; i+=2){
      for(int j=1; j<i; j+=2){
	t[i][j] = (t[i-2][j-1] - t[i][j-1] - t[i][j+1])/2;
	t[i-1][j-1] = t[i][j] + t[i][j-1];
	t[i-1][j] = t[i][j] + t[i][j+1];
      }
    }
    for(int i=0; i<N; ++i){
      for(int j=0; j<i+1; ++j){
	if(j)cout << ' ' ;
	//cout << ' ' ;
	cout << t[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
