#include <iostream>
#include <algorithm>

using namespace std;

int B2D(string s)
{
  int sum = 0;
  reverse(s.begin(), s.end());
  for(int i=0, b=1; i<s.size(); ++i, b*=2){
    if(s[i] == '1')sum += b;
  }
  return sum;
}

int main(void)
{
  while(true){
    string r;
    char b = '1';
    while(true){
      string s;
      cin >> s;
      if(s == "#")break;
      if(s == "~")return 0;
      
      if(s.size() <= 2){
	if(s == "0")b = '1';
	else if(s == "00")b = '0';
      }
      else{
	r += string((int)s.size() - 2, b);
      }
    }
    cout << B2D(r) << endl;
  }
  return 0;
}
