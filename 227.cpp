#include <iostream>
#include <algorithm>

using namespace std;

inline 
bool isIn(int i, int j)
{
  return !(i < 0 || 5 <= i || j < 0 || 5 <= j);
}

int main(void)
{
  char t[5][5];
  int tc = 0;
  while(true){    
    pair<int, int> p;
    for(int i=0; i<5; ++i){
      string s;
      getline(cin, s);
      if(s == "Z")return 0;
      for(int j=0; j<5; ++j){
	t[i][j] = s[j];
	if(t[i][j] == ' ')p = make_pair(i, j);
      }
    }
    if(tc)cout << endl;
    bool flg = true;
    string s, u;
    while(true){
      getline(cin, u);
      s += u;
      if(count(s.begin(), s.end(), '0'))break;
    }
    //cout << s << endl;
    for(int i=0; s[i] != '0'; ++i){
      int ni = p.first, nj = p.second;
      if(s[i] == 'A')--ni;
      else if(s[i] == 'B')++ni;
      else if(s[i] == 'L')--nj;
      else ++nj;
      if(!(flg = isIn(ni, nj)))break;
      swap(t[p.first][p.second], t[ni][nj]);
      p.first = ni;
      p.second = nj;
    }    
    cout << "Puzzle #" << ++tc << ":" << endl;
    if(!flg){
      cout << "This puzzle has no final configuration." << endl;
      continue;
    }
    for(int i=0; i<5; ++i){
      for(int j=0; j<5; ++j){
	if(j)cout << ' ';
	cout << t[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
