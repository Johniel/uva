#include <iostream>
#include <algorithm>

using namespace std;

inline bool isnum(char c)
{
  return ('0' <= c && c <= '9');
}

const int adj = 4;
const int di[] = { 0, 0, -1, 1};
const int dj[] = {-1, 1,  0, 0};

bool num(int h, int w, string s[])
{  
  bool flg = true;
  for(int i=0; i<h && flg; ++i){
    for(int j=0; j<w && flg; ++j){
      if(!isnum(s[i][j]))continue;
      int cnt = 0;
      for(int d=0; d<adj; ++d){
	int ni = i + di[d], nj = j + dj[d];
	if(s[ni][nj] == '-' || s[ni][nj] == '|')++cnt;
      }
      flg = (cnt == (s[i][j] - '0') && cnt < 4);
    }
  }
  return flg;
}

inline bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

#include <stack>
#include <utility>
bool loop(int h, int w, string s[])
{
  static const int H = 101, W = 101;
  static bool visited[H][W];
  int color = 1, si, sj;
  fill(&visited[0][0], &visited[H-1][W], false);
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      if(s[i][j] == '-' || s[i][j] == '|'){
	si = i;
	sj = j;
	j = i = 1 << 20;
      }
    }
  }
  stack< pair<int, int> > S;
  for(S.push(make_pair(si, sj)); !S.empty(); ){
    pair<int, int> n = S.top();
    S.pop();
    visited[n.first][n.second] = color;
    int cnt = 0;
    for(int d=0; d<adj; ++d){
      int ni = n.first + di[d], nj = n.second + dj[d]; 
      if(!isIn(ni, nj, h, w) || s[ni][nj] == ' ' || isnum(s[ni][nj]))continue;
      ++cnt;
      if(visited[ni][nj])continue;
      S.push(make_pair(ni, nj));
    }
    //cout << cnt << endl;
    if(!(cnt == 2 || cnt == 0))return false;
  }
  for(int k=0; k<h; ++k){
    for(int l=0; l<w; ++l){
      if(!visited[k][l] && (s[k][l] == '|' || s[k][l] == '-'))return false;
    }
  }
  return true;
}

int main(void)
{  
  string s[200];
  int tc;
  for(cin >> tc; tc--; ){
    int h, w;
    cin >> h >> w;
    h = h * 2 + 1;
    w = w * 2 + 1;
    cin.ignore();
    for(int i=0; i<h; ++i)
      getline(cin, s[i]);
    bool f1 = loop(h, w, s), f2 = num(h, w, s);
    //cout << (int)f1 << ' ' << (int)f2 << endl;
    cout << ((f1 && f2)? "Valid" : "Invalid") << endl;
  }
  return 0;
}
