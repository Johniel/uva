#include <iostream>
#include <algorithm>

using namespace std;

const int H = 60, W = 60;
char maze[H][W];

inline bool isIn(int h, int w, int i, int j)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

void walk(int h, int w, int i, int j)
{
  static const int adj = 4;
  static const char dir[] = {'N', 'E', 'S', 'W'};
  static const int di[] = {-1, 0, 1, 0};
  static const int dj[] = {0, 1, 0, -1};
  int d = 0;
  for(char c;; ){
    cin >> c;
    if(c == 'Q')break;
    else if(c == 'R')d = (d + 1) % adj;
    else if(c == 'L')d = (d + adj - 1) % adj;
    else if(c == 'F'){
      for(int l=1; ; ++l){
	int ni = i + di[d] * l, nj = j + dj[d] * l;
	if(isIn(h, w, ni, nj) && maze[ni][nj] == ' '){
	  i = i + di[d] * l;
	  j = j + dj[d] * l;
	  break;
	}
	else break;	
      }
    }
  }
  cout << i + 1 << ' ' << j + 1 << ' ' << dir[d] << endl;
  return ;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int h, w;
    cin >> h >> w;
    cin.ignore();
    for(int i=0; i<h; ++i){
      string s;
      getline(cin, s);
      for(int j=0; j<w; ++j){
	maze[i][j] = s[j];
      }
    }
    int i, j;
    cin >> i >> j;
    //walk(h, w, i, j);
    walk(h, w, i-1, j-1);
    //walk(h, w, j-1, i-1);
    //walk(h, w, j, i);
    if(tc)cout << endl;
  }
  return 0;
}
