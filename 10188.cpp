#include <iostream>

using namespace std;

const int N = 100 + 1;
string s, t;
int n, m;

bool getInput(void)
{ 
  string r;
  s = t = "";
  cin >> n;
  if(n == 0)return false;
  cin.ignore();
  for(int i=0; i<n; ++i){
    getline(cin, r);
    s += r;
  }
  cin >> m;
  cin.ignore();
  for(int i=0; i<m; ++i){
    getline(cin, r);
    t += r;
  }
  return true;
}

int main(void)
{
  int tc = 0;
  while(true){
    if(!getInput())break;
    cout << "Run #" << ++tc << ": ";
    if(s == t && n == m)cout << "Accepted" << endl;
    else{
      string a, b;
      for(int i=0; i<s.size(); ++i){
	if('0' <= s[i] && s[i] <= '9')
	  a += s[i];
      }
      for(int i=0; i<t.size(); ++i){
	if('0' <= t[i] && t[i] <= '9')
	  b += t[i];
      }
      if(a == b)cout << "Presentation Error" << endl;
      else cout << "Wrong Answer" << endl;
    }      
  }
  return 0;
}
