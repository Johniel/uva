#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  char m[100][100];
  int tc, cs = 0;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s, t;
    getline(cin, t);
    for(int i=0; i<t.size(); ++i)
      if(isalpha(t[i]))s += t[i];
    int size = sqrt((int)s.size());
    bool flg = size * size == s.size();
    for(int i=0, cnt = 0; i<size && flg; ++i){
      for(int j=0; j<size; ++j)
	m[i][j] = s[cnt++];
    }
    t = "";
    for(int j=0; j<size && flg; ++j){
      for(int i=0; i<size; ++i)
	t += m[i][j];
    }
    flg = flg && s == t;
    t = "";
    for(int j=0; j<size && flg; ++j){
      for(int i=0; i<size; ++i)
	t += m[size - i - 1][size - j - 1];
    }
    flg = flg && s == t;
    t = "";
    for(int i=0; i<size; ++i)
      for(int j=0; j<size && flg; ++j){
	t += m[size - i - 1][size - j - 1];
    }
    cout << "Case #" << ++cs << ":" << endl;
    if(flg)cout << size << endl;
    else cout << "No magic :(" << endl;
  }
  return 0;
}
