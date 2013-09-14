#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int D = 500 + 1;
const string FACE[] = {"front", "back", "left", "right", "top", "bottom"};

int face[D][6];
int t[D][6];
pair<int, int> path[D][6];

int rev(int n)
{
  return n%2? n-1 : n+1;
}

void rec(pair<int, int> root)
{
  if(t[root.first][root.second] != 1){
    rec(path[root.first][root.second]);
  }
  cout << root.first+1 << ' ' << FACE[root.second] << endl;
  return ;
}

void dp(int size)
{
  int result = 0;
  pair<int, int> root;
  fill(&t[0][0], &t[size-1][6], 1);
  for(int i=0; i<size; ++i){
    for(int fi=0; fi<6; ++fi){
      for(int j=i+1; j<size; ++j){
	for(int fj=0; fj<6; ++fj){
	  int r = face[i][rev(fi)];
	  if(face[j][fj] == r){
	    if(t[j][fj] < t[i][fi] + 1){
	      t[j][fj] = t[i][fi] + 1;
	      path[j][fj] = make_pair(i, fi);
	      if(t[j][fj] > result){
		result = t[j][fj];
		root = make_pair(j, fj);
	      }
	    }
	  }
	}
      }
    }
  }
  cout << result << endl;
  rec(root);
  return ;
}

int main(void)
{
  int tc = 0;
  for(int n; cin >> n; ){
    if(n == 0)break;
    if(tc)cout << endl;
    for(int i=0; i<n; ++i){
      for(int j=0; j<6; ++j){
	cin >> face[i][j];
      }
    }
    cout << "Case #" << ++tc << endl;
    dp(n); 
  }
  return 0;
}
