#include <iostream>
#include <algorithm>

using namespace std;

string sim(string s)
{  
  if(s.size() < 2)return "";
  if(s[0] == '2'){
    return s.substr(1);
  }
  else if(s[0] == '3'){
    string t = sim( s.substr(1) );
    if(t.size() == 0)return "";
    return t + "2" + t;
  }
  return "";
}

string solve(string s)
{  
  if( count(s.begin(), s.end(), '0') )return "";
  return sim(s);
}

int main(void)
{
  string s;
  while(cin >> s && s != "0"){
    s = solve(s);
    if(s.size() == 0)cout << "NOT ACCEPTABLE" << endl;
    else cout << s << endl;
  }
  return 0;
}
