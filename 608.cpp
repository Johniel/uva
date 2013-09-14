#include <iostream>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int main(void)
{
  const int H = 0, L = 1, N = 2;
  int tc;
  int state[CHAR_MAX][3];
  for(cin >> tc; tc--; ){
    string s, t, e;
    int a, b;
    fill(&state[0][0], &state[CHAR_MAX - 1][3], false);
    for(int cnt = 3; cnt--; ){
      cin >> s >> t >> e;
      if(e == "up"){
	for(int i=0; i<s.size(); ++i){
	  ++state[s[i]][L];
	  ++state[t[i]][H];
	}
      }
      else if(e == "down"){
	for(int i=0; i<s.size(); ++i){
	  ++state[s[i]][H];
	  ++state[t[i]][L];
	}
      }
      else{
	for(int i=0; i<s.size(); ++i){
	  state[s[i]][N] = -1;
	  state[t[i]][N] = -1;
	}
      }
    }
    int c, mx = -1, r;
    for(int i=0; i<CHAR_MAX; ++i){
      if(state[i][N])continue;
      for(int j=0; j<3; ++j){
	if(j == N)continue;
	if(state[i][j] > mx){
	  mx = state[i][j];
	  c = i;
	  r = j;
	}
      }
    }
    if(r == H)
      cout << (char)c << " is the counterfeit coin and it is light." << endl;
    else 
      cout << (char)c << " is the counterfeit coin and it is heavy." << endl;
  }
  return 0;
}
