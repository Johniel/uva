#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

string toCode(string s, map<char, int> M)
{
  int cnt = 0;
  int l = -1;
  string t;
  t += s[0];
  for(int i=0; i<s.size(); ++i){
    /*
    if(i < s.size()){
      if(M[s[i]] == l){
	s.erase(s.begin() + i);
	--i;
	continue;
      }
    }
    */
    if(M[s[i]]){
      l = M[s[i]];
      if(cnt == 3){	
	//while(t.size() != 2)t.erase(t.begin() + 1);
	t += '0' + M[s[i]];
	cnt = 2;
      }
      else{
	t += '0' + M[s[i]];
	++cnt;
      }
    }
  }
  /*
  if(t.size() < 4){
    t += "000";	
    while(t.size() != 4)t.erase(t.begin() + 1);
  }
  */
  return t;
}

void output(string s, map<char, int> M)
{
  cout << string(9, ' ') << s 
       << string(25 - (int)s.size(), ' ') << toCode(s, M) << endl; 
}

int main(void)
{
  string s;
  map<char, int> M;
  M['B'] = M['P'] = M['F'] = M['V'] = 1;
  M['C'] = M['S'] = M['K'] = M['G'] = 
    M['J'] = M['Q'] = M['X'] = M['Z'] = 2;
  M['D'] = M['T'] = 3;
  M['L'] = 4;
  M['M'] = M['N'] = 5;
  M['R'] = 6;
  cout << string(9, ' ') << "NAME" << string(21, ' ') << "SOUNDEX CODE" << endl;
  while(cin >> s)
    output(s, M);
  cout << "                   END OF OUTPUT" << endl;
  return 0;
}
