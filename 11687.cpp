#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  for(string s; ; ){
    cin >> s;
    if(s == "END")break;
    int d = s.size(), n = -1, re = 0;
    if(s != "1"){
      while(true){
	int cnt =0;
	n = d;
	while(n){
	  n /= 10;
	  ++cnt;
	}
	//cout << d << ' ' << cnt << endl;
	++re;
	if(cnt == d)break;      
	d = cnt;
      }
    }
    cout << re + 1 << endl;
  }
  return 0;
}
