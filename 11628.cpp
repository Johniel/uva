#include <iostream>

using namespace std;

int gcd(int a, int b)
{
  return (a%b)? gcd(b, a%b) : b;
}

int main(void)
{
  int t[10000][30];
  while(true){
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)break;
    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
	cin >> t[i][j];
      }
    }
    int sum = 0;
    for(int i=0; i<n; ++i){
      sum += t[i][m-1];
    }
    for(int i=0; i<n; ++i){
      int g = gcd(t[i][m-1], sum);
      cout << t[i][m-1] / g << " / " << sum / g << endl;
    }
  }
  return 0;
}
