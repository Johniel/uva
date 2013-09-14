#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

static const int N = 11;
static const int M = 101;

long long  num[N][M];
int route[N][M];
long long sum;

string root(int ri, int rj, string s)
{
  if(route[ri][rj] == -1)
    return s;
  else{
    s +=  ('a' + route[ri][rj]);
    return root(route[ri][rj], rj+1, s);
  }
}

int main(void)
{
  while(true){
    int n, m;
    cin >> n >> m;
    if(cin.eof() == true)
      break;
    REP(i, n)REP(j, m)
      cin >> num[i][j];
    long long re[n][m];
    fill(&re[0][0], &re[n-1][m], INT_MAX);
    REP(i, n){
      re[i][m-1] = num[i][m-1];
      route[i][m-1] = -1;
    }
    const int si[3] = {-1, 0, 1};
    for(int j=m-1; j>0; j--){
      REP(i, n){
	REP(k, 3){
	  int ni = i + si[k];
	  int nj = j - 1;
	  ni = (ni < 0)? n-1 : ni%n;
	  if(re[ni][nj] > re[i][j] + num[ni][nj]){
	    re[ni][nj] = re[i][j] + num[ni][nj];
	    route[ni][nj] = i;
	  }
	}
      }
    }
    vector<int> to;
    long long v = INT_MAX;
    REP(i, n){
      if(re[i][0] < v){
	to.clear();
	to.push_back(i);
	v = re[i][0];
      }
      else if(re[i][0] == v)
	to.push_back(i);
    }
    string result;
    REP(i, to.size()){
      string tmp = "a";
      tmp[0] += to[i];
      tmp = root(to[i], 0, tmp);
      if(result.size())
	result = (result < tmp)? result : tmp;
      else
	result = tmp;
    }
    REP(i, result.size()){
      cout << result[i] - 'a' + 1;
      if(result.size() - 1 - i)cout << ' ' ;
    }
    cout << endl << v << endl;
  }
  return 0;
}
