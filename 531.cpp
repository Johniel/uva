#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define REP(i, n) for(int i=0; i<(int)n; ++i)

#define UP 1
#define LEFT 2
#define SLANT 3

using namespace std;

inline
void LCS(vector<string> a, vector<string> b)
{
  int t[a.size()+1][b.size()+1];
  int move[a.size()+1][b.size()+1];
  fill(&move[0][0], &move[a.size()][b.size()+1], 0);
  fill(&t[0][0], &t[0][b.size()+1], 0);
  for(int i=1; i<a.size()+1; i++){
    t[i][0] = 0;
  }

  for(int i=1; i<a.size()+1; i++){
    for(int j=1; j<b.size()+1; j++){
      if(a[i-1] == b[j-1]){
	t[i][j] = t[i-1][j-1] + 1;
	move[i][j] = SLANT;
      }
      else if(t[i-1][j] >= t[i][j-1]){
	t[i][j] = t[i-1][j];
	move[i][j] = UP;
      }
      else if(t[i-1][j] < t[i][j-1]){
	t[i][j] = t[i][j-1];
	move[i][j] = LEFT;
      }
    }
  }

  vector<string> result;
  int i = a.size(), j = b.size();
  while(i != 0 && j != 0){
    if(move[i][j] == SLANT){
      result.push_back(a[i-1]);
      i--;
      j--;
    }
    else if(move[i][j] == UP)
      i--;
    else if(move[i][j] == LEFT)
      j--;
  }
  reverse(result.begin(), result.end());
  REP(i, result.size()){
    if(i != 0)cout << ' ';
    cout << result[i];
  }
  cout << endl;
  return ;
}

int main(void)
{
  while(true){
    vector<string> s, t, result;
    for(string a = ""; ; ){
      if(!(cin >> a))return 0;
      if(a == "#")break;
      s.push_back(a);
    }    
    for(string a = ""; ; ){
      if(!(cin >> a))return 0;
      if(a == "#")break;
      t.push_back(a);
    }
    LCS(s, t);
  }
  return 0;
}
