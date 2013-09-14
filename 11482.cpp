#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc = 0;
  for(int n, m; ; cout << endl){
    cin >> n >> m;
    if(n + m == 0)break;
    cout << "Triangular Museum " << ++tc << endl;
    for(int i = 0, cnt = 1; i< n * m; ++i){
      for(int j = 0; j <  n * m - i - 1; ++j){
	cout << ' ';
      }

      for(int k = 0; k < cnt; ++k){

	cout << '/';

	for(int j = 0; j < (i % n) * 2; ++j){
	  cout << (i%n == n-1? '_' : ' ');
	}

	cout << '\\';

	if(k+1 < cnt){
	  for(int j = 0; j < 2 * (n-1) - (i % n) * 2; ++j){
	    cout << ' ';
	  }
	}
      }
      if(i%n == n-1)++cnt;
      cout << endl;
    }
  }
  return 0;
}
