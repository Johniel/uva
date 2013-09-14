#include <iostream>

using namespace std;

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    string s;
    while(n){
      s += '0' + n % 2;
      n /= 2;
    }
    reverse(s.begin(), s.end());
    cout << "The parity of " << s << " is " 
	 <<  count(s.begin(), s.end(), '1') << " (mod 2)." << endl;
  }
  return 0;
}
