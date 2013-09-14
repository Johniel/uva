#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 100;
  int votes[N][N];
  bool win[N][N], flg[N];
  int c, v, w;
  while(true){
    cin >> c >> v >> w;
    if(c == 0 && w == 0 && v == 0)break;
    --w;
    for(int i=v; i--;){
      for(int j=0; j<c; ++j){
	int no;
	cin >> no;
	votes[i][no-1] = j;
      }
    }
    for(int i=0; i<c; ++i){
      for(int j=i+1; j<c; ++j){
	int a = 0, b = 0;
	for(int k=v; k--; )
	  if(votes[k][i] < votes[k][j])++a;
	  else ++b;
	win[i][j] = !(a < b);
	win[j][i] = !win[i][j];
      }
    }
    vector<int> L, W;
    for(int i=c; i--; ){
      if(i == w)continue;
      if(win[w][i])W.push_back(i);
      else L.push_back(i);
    }
    
    fill(flg, flg + L.size(), false);
    for(int i=0; i<L.size(); ++i){
      for(int j=0; j<W.size(); ++j)
	if(win[W[j]][L[i]])flg[i] = true;
      for(int j=0; j<L.size(); ++j)
	if(win[L[j]][L[i]])flg[i] = true;
    }
    cout << ((count(flg, flg + L.size(), false))? "no" : "yes") << endl;
  }
  return 0;
}
