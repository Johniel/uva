#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    for(int i=1, j = 1; i<2000000000; ++j){
      cout << i << ' ' << j << endl;
      i += j - 1;
      if(n < i){
	cout << j << endl;
	break;
      }
    }
  }
  return 0;
}
