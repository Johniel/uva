#include <iostream>
#include <algorithm>

using namespace std;

int conv(string s)
{
  int sum = 0;
  reverse(s.begin(), s.end());
  for(int i = 0, j = 1; i < s.size(); ++i, j *= 2){
    if(s[i] == '1')sum += j;
  }
  return sum;
}

int main(void)
{
  string s[2], t, u;  
  getline(cin, s[0]);
  getline(cin, s[1]);
  int up = conv("11111");
  int down = conv("11011");
  while(cin >> u){
    bool flg = false;
    for(int i=0; i<u.size(); ++i){
      t += u[i];
      if(t.size() == 5){
	int n = conv(t);	
	if(n == up)flg = true;	 
	else if(n == down)flg = false;
	else cout << s[flg][n];	
	t = "";
      }
    }
    cout << endl;
  }
  return 0;
}
