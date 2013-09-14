#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

map<int, int> visited;

pair<int, string> calcHash(char s[], int i, int size)
{
  int sum = 0;
  string t;
  for(int j=0; j<size; ++j){
    t += s[i + j];
    sum = (sum + s[i + j] - 'A' + 1) * 107;
    sum %= 10000007;
  }
  return make_pair(sum, t);
}

int main(void)
{
  const int S = 1000 + 1;
  int tc;
  char s[S];
  scanf("%d\n", &tc);
  while(tc--){    
    scanf("%s\n", s);
    const int size = strlen(s);
    int freq;
    string a;
    visited.clear();
    REP(i, size){
      REP(j, size || true){
	if(!j)continue;
	if(size < i + j)break;
	pair<int, string> p = calcHash(s, i, j);
	int h = p.first;
	string b = p.second;
	if(visited.find(h) == visited.end()){
	  visited.insert(make_pair(h, 0));
	}
	int tmp = ++visited[h];
	//cout << b << ' ' << tmp << ' ' << h << endl;
	if(tmp < 2)continue;
	if(a.size() < b.size()){
	  a = b;
	  freq = tmp;
	}
	else if(a.size() == b.size()){
	  if(a >= b){
	    a = b;
	    freq = tmp;
	  }
	}
      }     
    }
    if(a.size())cout << a << ' ' << freq << endl;
    else cout << "No repetitions found!" << endl;
  }
  return 0;
}
