#include <iostream>
#include <algorithm>

using namespace std;

const int S = 1000 + 1;
const int C = 'z' + 1;
int u[C], t[S][C];

int main(void)
{
  string s;
  int size = 0;
  while(true){
    getline(cin, s);
    if(s == "#")break;
    for(int i=0; i<s.size(); ++i){
      ++t[size][s[i]];
    }
    ++size;
  }
  while(true){
    getline(cin, s);
    if(s == "#")break;    
    fill(u, u + C, 0);
    for(int i=0; i<s.size(); ++i){
      ++u[s[i]];
    }
    int r = 0;
    for(int i=0; i<size; ++i){
      bool flg = true;
      for(int j='a'; j<='z'; ++j){
	if(t[i][j] > u[j]){
	  flg = false;
	  break;
	}
      }
      r += flg;
    }
    cout << r << endl;
  }
  return 0;
}
