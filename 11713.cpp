#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  map<char, int> M;
  M['a'] = M['A'] = true;;
  M['o'] = M['O'] = true;;
  M['e'] = M['E'] = true;
  M['u'] = M['U'] = true;
  M['i'] =M['I'] = true;
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(s.size() == t.size()){
      bool flg = true;
      for(int i=0; i<s.size(); ++i){
	if(s[i] != t[i]){
	  flg = (M[s[i]] && M[t[i]]);
	}
      }
      if(flg)cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }
  return 0;
}
