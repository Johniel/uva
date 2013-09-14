#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  for(string s; ; ){
    cin >> s;
    string r = s;
    if(s == "0")break;
    int sum = 0, cnt = 0;
    for(int i=0; i<s.size(); ++i){
      sum += s[i] - '0';
    }
    while(true){
      if(sum == 9){
	++cnt;
	break;
      }
      if(sum % 9)break;
      ++cnt;
      int tmp = 0;
      while(10 <= sum){
	tmp += sum % 10;
	sum /= 10;
      }
      sum += tmp;
    }
    if(cnt)cout << r << " is a multiple of 9 and has 9-degree " << cnt << "." << endl;
    else cout << r << " is not a multiple of 9." << endl;
  }
  return 0;
}
