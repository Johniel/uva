#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

const int N = 100 + 1;

int field[N][N];

const int M = 8;
const int ni[M] = {-1, -1, -1,  0, 0,  1, 1 ,1};
const int nj[M] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main(void)
{
  int cnt = 0;
  while(true){
    int h, w;
    cin >> h >> w;
    if(h == 0 && w == 0)
      break;
    if(cnt)cout << endl;
    fill(&field[0][0], &field[N-1][N], 0);
    REP(i, h)REP(j, w){
      char c;
      cin >> c;
      if(c == '*'){
	field[i][j] = -1 * 1<<20;
	REP(k, M){
	  int si = i + ni[k];
	  int sj = j + nj[k];
	  if(0 <= si && si < h && 0 <= sj && sj < w)
	    field[si][sj]++;
	}
      }
    }
    cout << "Field #" << ++cnt << ':' << endl;
    REP(i, h){
      REP(j, w){
	if(field[i][j] < 0)
	  cout <<'*';
	else
	  cout << field[i][j];
      } 
      cout << endl;
    }
  }
  return 0;
}
