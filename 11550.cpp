#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 8 * 8;
bool m[SIZE][SIZE];
int node, edge;

bool check1(void)
{
  static int cnt[SIZE];
  fill(cnt, cnt + SIZE, 0);
  for(int i=0; i<edge; ++i){
    for(int j=0; j<node; ++j){
      cnt[i] += m[j][i];
    }
  }
  return count(cnt, cnt + edge, 2) == edge;
}

bool check2(void)
{
  return true;
  int sum = 0;
  for(int i=0; i<node; ++i){
    for(int j=0; j<edge; ++j){
      sum += m[i][j];
    }
  }
  return sum % 2 == 0;
}

bool check3(void)
{
  static int cnt[SIZE][SIZE];
  fill(&cnt[0][0], &cnt[node-1][edge], 0);
  for(int i=0; i<edge; ++i){
    int j, src, dst;
    for(j=0; !m[j][i]; ++j);
    src = j;
    for(++j; !m[j][i]; ++j);
    dst = j;
    ++cnt[src][dst];
    ++cnt[dst][src];
  }

  for(int i=0; i<node; ++i){
    for(int j=0; j<edge; ++j){      
      if(1 < cnt[i][j])return false;
    }
  }
  return true;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    cin >> node >> edge;
    for(int i=0; i<node; ++i){
      for(int j=0; j<edge; ++j){
	cin >> m[i][j];
      }
    }
    cout << (check1() && check2() && check3() ? "Yes" : "No") << endl;
  }
  return 0;
}
