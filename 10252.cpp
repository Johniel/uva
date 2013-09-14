#include <iostream>
#include <string>
#include <algorithm>

#define UP 1
#define LEFT 2
#define SLANT 3

using namespace std;

string LCS(string a, string b)
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

  string result;
  int i = a.size(), j = b.size();
  while(i != 0 && j != 0){
    if(move[i][j] == SLANT){
      result += a[i-1];
      i--;
      j--;
    }
    else if(move[i][j] == UP)
      i--;
    else if(move[i][j] == LEFT)
      j--;
  }
  reverse(result.begin(), result.end());
  return result;
}

int main(void)
{
  string a, b, result;
  int cntA['z' + 1], cntB['z' + 1];
  while(getline(cin, a) && getline(cin, b)){
    //result = LCS(a, b);
    fill(cntA, cntA + 'z' + 1, 0);
    fill(cntB, cntB + 'z' + 1, 0);
    for(int i=0; i<a.size(); ++i)++cntA[a[i]];
    for(int i=0; i<b.size(); ++i)++cntB[b[i]];
    for(int i=0; i<='z'; ++i){
      if(cntA[i] && cntB[i]){
	cout << string(min(cntA[i], cntB[i]), i);
      }
    }
    cout << endl;
  }
  return 0;
}
