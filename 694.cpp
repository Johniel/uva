#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int c = 0;
  while(true){
    int cnt = 0;
   long long int a, b, tmp;
    cin >> a >> b;
    tmp = a;
    if(a == -1 && b == -1)
      break;
    while(a <= b){
      if(a == 1){cnt++;break;}
      cnt++;
      if(a%2 == 1){
	a = 3 * a + 1;
      }
      else{
	a = a / 2;
      }
    }
    cout << "Case " << ++c << ": A = " << tmp 
	 << ", limit = " << b << ", number of terms = " << cnt << endl;
  }
}
