#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  map<char, int> M;
  M['A'] = M['B'] = M['C'] = 2;
  M['D'] = M['E'] = M['F'] = 3;
  M['G'] = M['H'] = M['I'] = 4;
  M['J'] = M['K'] = M['L'] = 5;
  M['M'] = M['N'] = M['O'] = 6;
  M['P'] = M['Q'] = M['R'] = M['S'] = 7;
  M['T'] = M['U'] = M['V'] = 8;
  M['W'] = M['X'] = M['Y'] = M['Z'] = 9;
  string s;
  while(cin >> s){
    for(int i=0; i<s.size(); ++i){
      if(isalpha(s[i]))cout << M[s[i]];
      else cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
