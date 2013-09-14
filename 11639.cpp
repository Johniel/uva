#include <iostream>
#include <complex>
#include <algorithm>

using namespace std;

typedef complex<int> point;

int main(void)
{
  const int N = 100;
  int tc, F[N][N];
  cin >> tc;
  int cnt = 0;
  while(tc--){    
    point x1, x2, y1, y2;
    fill(&F[0][0], &F[N-1][N], 0);
    cin >> x1.real() >> x1.imag() >> y1.real() >> y1.imag(); 
    cin >> x2.real() >> x2.imag() >> y2.real() >> y2.imag(); 
    for(int i=x1.real(); i<y1.real(); ++i)
      for(int j=x1.imag(); j<y1.imag(); ++j)
	++F[i][j];
    for(int i=x2.real(); i<y2.real(); ++i)
      for(int j=x2.imag(); j<y2.imag(); ++j)
	++F[i][j];
    int a, b, c;
    a = b = c = 0;
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
	if(F[i][j] == 0)++a;
	else if(F[i][j] == 1)++b;
	else if(F[i][j] == 2)++c;
      }
    }
    cout << "Night " << ++cnt << ": " << c << ' ' << b << ' ' << a << endl;
  }
  return 0;
}
