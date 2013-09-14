#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>

#define REP(i, n) for(int i=0; i<n; ++i)

using namespace std;

const int H = 25, W = 25;

bool ver[H][W], hol[H][W]; 
int t[H][W], no[H][W], cnt;

const int adj = 4;
const int UP = 2, DOWN = 3, LEFT = 0, RIGHT = 1;
const int di[] = {0, 0, -1, 1, 1, -1, 1, -1};
const int dj[] = {-1, 1, 0, 0, 1, -1, -1, 1};

void test(int h, int w)
{
  static int L = 0;
  cout << L++ << endl;
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      printf("%2d ", no[i][j]);
    }
    puts("");
  }  
  
  puts("");
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      printf("%2d ", ver[i][j]);
    }
    puts("");
  }
  puts("");
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      printf("%2d ", hol[i][j]);
    }
    puts("");
  }
}

bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

bool putable(int i, int j, int h, int w, const int d1, const int d2)
{
  int ni, nj;
  ni = i + di[d1], nj = j + dj[d1];
  //cout << "test0 : " << isIn(ni, nj, h, w) << ' ' <<  t[ni][nj]<< endl;
  if(isIn(ni, nj, h, w) && t[ni][nj] == 0){
    return false;
  }
  //cout << "test1 : " << isIn(ni, nj, h, w) << ' ' <<  t[ni][nj]<< endl;
  ni = i + di[d2], nj = j + dj[d2];
  return isIn(ni, nj, h, w) && t[ni][nj] == 0;
}

bool putV(int i, int j, int h, int w)
{
  return putable(i, j, h, w, UP, DOWN) && !ver[i][j];
}

bool putH(int i, int j, int h, int w)
{
  return putable(i, j, h, w, LEFT, RIGHT) && !hol[i][j];
}

void put(int i, int j, int dir, int v, int h, int w)
{
  for(int l=0; ; ++l){
    int ni = i + di[dir] * l;
    int nj = j + dj[dir] * l;
    if(!isIn(ni, nj, h, w))break;
    if(t[ni][nj])break;
    if(dir == DOWN || dir == UP)ver[ni][nj] = v;
    else hol[ni][nj] = v;
  }
  return ;
}

bool bt(int h, int w, int bi, int bj)
{  
  //test(h, w);

  for(int i=bi; i<h; ++i){
    for(int j=bj; j<w; ++j){

      if(no[i][j] || t[i][j])continue;

      //cout << "(" << i << ", " << j << ") V" << endl;
      if(putV(i, j, h, w)){
	no[i][j] = ++cnt;
	put(i, j, DOWN, cnt, h, w);
	if(bt(h, w, i, j))return true;
	put(i, j, DOWN, 0, h, w);
	--cnt;
	no[i][j] = 0;
      }
      
      //cout << "(" << i << ", " << j << ") H" << endl;
      if(putH(i, j, h, w)){
	no[i][j] = ++cnt;
	put(i, j, RIGHT, cnt, h, w);
	if(bt(h, w, i, j))return true;
	put(i, j, RIGHT, 0, h, w);
	--cnt;
	no[i][j] = 0;
      }
    }
    bj = 0;
    if(i == h-1)return true;
  }
  return false;
}

char buff[H * 5][W * 7];
int num[H * 5];
bool visited[H*5][W*7];

void rec(int i, int j, int h, int w)
{
  visited[i][j] = true;
  buff[i][j] = ' ';
  for(int d=0; d<adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(!isIn(ni, nj, h, w) || visited[ni][nj])continue;
    if(buff[ni][nj] == '$')rec(ni, nj, h, w);
  }
  return;
}

void output(int h, int w)
{
  char tmp[4];
  fill(&buff[0][0], &buff[H*4-1][W], '$');
  fill(&visited[0][0], &visited[H*4-1][W], false);
  /*
  REP(i, h){ REP(j, w) cout << t[i][j] << ' '; cout << endl;}
  cout << endl;
  REP(i, h){ REP(j, w) cout << no[i][j] << ' '; cout << endl;}
  cout << endl;
  */
  for(int i=0; i<h; ++i){
    num[i] = 0;
    for(int j=0; j<w; ++j){
      if(!t[i][j]){
	++num[i];
      }
    }
  }

  for(int i=0, pi=0; i<h; ++i, pi+=3){
    int ini = num[i];
    for(int j=0, pj=0; j<w; ++j, pj+=5){
      if(t[i][j]){
	if(num[i] == 0)break;
	continue;
	if(num[i] != ini){
	  for(int k=0; k<4; ++k){
	    buff[pi+2][pj+k+1] = buff[pi+1][pj+k+1] = '*';
	  }
	}
      }
      else{
	sprintf(tmp, "%03d ", no[i][j]);
	for(int k=0; k<4; ++k){
	  if(no[i][j])buff[pi+1][pj+k+1] = tmp[k]; 
	  else buff[pi+1][pj+k+1] = ' '; 
	  buff[pi+2][pj+k+1] = ' ';
	  buff[pi+3][pj+k+1] = '+';
	  buff[pi][pj+k+1] = '+';
	  buff[pi+k][pj] = '+';
	  buff[pi+k][pj+5] = '+';
	}
	if(--num[i] == 0)break;
      }
    }
    num[i] = ini;
  }

  for(int i=0; i<h*3+1; ++i){
    if(buff[i][0] == '$'){
      rec(i, 0, h*3+1, w*5+1);
    }
    if(buff[i][w*5] == '$'){
      rec(i, w*5, h*3+1, w*5+1);
    }
  }

  for(int j=0; j<w*5+1; ++j){
    if(buff[0][j] == '$'){
      rec(0, j, h*3+1, w*5+1);
    }
    if(buff[h*3][j] == '$'){
      rec(h*3, j, h*3+1, w*5+1);
    }
  }

  for(int i=0; i<h*3+1; ++i){
    num[i] = 0;
    for(int j=0; j<w*5+1; ++j){
      if(buff[i][j] == '$')buff[i][j] = '+';
      if(buff[i][j] == '+'){
	++num[i];
      }
    }
  }

  for(int i=0; i<h*3+1; ++i){
    for(int j=0; j<w*5+1; ++j){
      if(num[i] == 0)break;
      cout << buff[i][j];
      if(buff[i][j] == '+')--num[i];
    }
    cout << endl;
  }

  return ;
}

int main(void)
{
  for(int n, m; ; ){
    cin >> n >> m;
    if(n + m == 0)break;
    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
	cin >> t[i][j];
      }
    }

    fill(&ver[0][0], &ver[n-1][m], false);
    fill(&hol[0][0], &hol[n-1][m], false);
    fill(&no[0][0], &no[n-1][m], 0);
    cnt = 0;
    bt(n, m, 0, 0);
    output(n, m);

    cout << endl;
  }
  return 0;
}
