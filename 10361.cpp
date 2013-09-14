#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 1000;
  int tc;
  cin >> tc;
  cin.ignore();
  for(; tc--; ){
    int cnt = 0;
    string s, u, t;
    string q[5];
    getline(cin, s);
    bool flg = true;
    for(int i=0; i<s.size(); ++i){
      if(s[i] == '<'){
	q[0] = t;
	for(++i; s[i] != '>'; ++i)q[1] += s[i];
	for(++i; s[i] != '<'; ++i)q[2] += s[i];
	for(++i; s[i] != '>'; ++i)q[3] += s[i];
	for(++i; i<s.size() && s[i] != ' '; ++i)q[4] += s[i];
	if(flg)flg = false; else cout << ' ' ;
	cout << q[0] << q[1] << q[2] << q[3] << q[4];
      }
      else if(s[i] == ' '){
	if(flg)flg = false; else cout << ' ' ;
	cout << t ;
	t = "";
      }
      else t += s[i];      
    }
    cout << endl;
    getline(cin, t);
    flg = true;
    for(int i=0; i+2<(int)t.size(); ++i){
      if(t[i] == '.' && t[i + 1] == '.' && t[i + 2] == '.'){
	cout << q[3] << q[2] << q[1] << q[4];
	i += 2;
      }
      else cout << t[i];
    }
    cout << endl;
  }
  return 0;
}
