#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int adj = 4;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int no[50][50];
char g[50][50];
int h, w;

void rec(int i, int j)
{
  g[i][j] = '@';
  for(int d=0; d<adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(ni < 0 || nj < 0)continue;
    if(h <= ni || w <= nj)continue;
    if(g[ni][nj] != 'X')continue;
    rec(ni, nj);
  }
  return ;
}

void die(int i, int j, int num)
{
  no[i][j] = num;
  for(int d=0; d<adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(ni < 0 || nj < 0)continue;
    if(h <= ni || w <= nj)continue;
    if(g[ni][nj] == '.')continue;
    if(0 <= no[ni][nj])continue;
    die(ni, nj, num);
  }
  return ;
}

int main(void)
{
  while(cin >> w >> h && h){
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	cin >> g[i][j];
	no[i][j] = -1;
      }
    }
    
    int num = 0;
    map<int, int> m;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(0 <= no[i][j])continue;
	if(g[i][j] == '*' || g[i][j] == 'X'){
	  die(i, j, num);
	  m.insert(make_pair(num, 0));
	  ++num;
	}
      }
    }

    static int cnt = 0;
    bool flg = false;
    cout << "Throw " << ++cnt << endl;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	if(g[i][j] == '@')continue;
	if(g[i][j] == 'X'){
	  ++m[no[i][j]];
	  rec(i, j);
	  flg = true;
	}
      }
    }
    map<int, int>::iterator itr;
    static int a[50 * 50];
    if(flg){
      int i = 0;
      for(itr = m.begin(); itr != m.end(); ++itr){
	a[i++] = itr->second;
      }
      sort(a, a + i);
      for(i = 0; i<m.size(); ++i){
	if(i)cout << ' ';
	cout << a[i];
      }
    }
    cout << endl;
    cout << endl;
  }
  return 0;
}
