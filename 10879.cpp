#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc, cnt = 0, n;
  for(cin >> tc; tc--; ){
    cin >> n;
    int i=2;
    cout << "Case #" << ++cnt << ": " << n << " = ";
    for(; ; ++i){
      if(n % i == 0){
	cout << i << " * " << n/i << " = ";
	++i;
	break;
      }
    } 
    for(; ; ++i){
      if(n % i == 0){
	cout << i << " * " << n/i << endl;
	++i;
	break;
      }
    }
  }
  return 0;
}
