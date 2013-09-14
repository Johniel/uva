#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, string> m;
int len[10 + 1];
string r[10 + 1][2];
int n;

string solve(string s)
{
  for(int i=0; i<n; ++i){
    string a = r[i][0];
    string b = r[i][1];
    string t;
    while(true){
      t = "";
      //cout << a << " : " << s << endl;
      for(int j=0; j<s.size(); ++j){
        if(s.substr(j, a.size()) == a){
          t += b;
          string tmp = s.substr(j+a.size());
          t += tmp;
          //cout << tmp << endl;
          break;
        }
        else t += s[j];
      }      
      if(s == t)break;
      s = t;      
    }
  }
  return s;
}

int main(void)
{
  while(cin >> n && n){
    cin.ignore();
    for(int i=0; i<n; ++i){
      string a, b;
      getline(cin, a);
      getline(cin, b);
      m[a] = b;
      len[i] = a.size();
      r[i][0] = a;
      r[i][1] = b;
    }
    string s;
    getline(cin, s);
    cout << solve(s) << endl;
  }
  return 0;
}
