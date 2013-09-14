#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

static const int N = 100;
static int cell[N][N];
static bool visited[N][N];
int n;

inline 
bool isIn(int i, int j)
{
  return !(i < 0 || n <= i || j < 0 || n <= j);
}

void floodFill(int i, int j, int num)
{
  const int adj = 4;
  static int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
  visited[i][j] = true;
  for(int d=0; d<adj; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(!isIn(ni, nj))continue;    
    if(cell[ni][nj] == num && !visited[ni][nj])
      floodFill(ni, nj, num);
  }
  return ;
}

int main(void)
{
  while(cin >> n){
    cin.ignore();
    if(n == 0)break;
    int color = 0;
    fill(&cell[0][0], &cell[n-1][n], color);
    fill(&visited[0][0], &visited[n-1][n], false);
    for(int i=0; i<n-1; ++i){
      ++color;
      string s;
      getline(cin, s);
      int a, b;
      istringstream iss(s);
      while(iss >> a >> b){
	--a; --b;
	cell[a][b] = color;
      }
    }
    set<int> S;
    bool flg = true;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	if(visited[i][j])continue;
	if(S.count(cell[i][j])){
	  flg = false;
	  i = j = (1 << 20);
	}
	else{
	  S.insert(cell[i][j]);
	  floodFill(i, j, cell[i][j]);
	}
      }
    }
    cout << (flg? "good" : "wrong") << endl;
  }
  return 0; 
}
