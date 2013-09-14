#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

const int N = 10 + 1;

int adj[N][N];
int p[N], tmp[N];
int len, size;

bool visited[N];

vector<string> v;
map<int, string> m;

int hash(void)
{
  int sum = 0;
  for(int i=0; i<len+1; ++i){
    sum = (sum + p [i] + 1) * 101;
  }
  return sum;
}

void rec(int node, int d)
{
  visited[node] = true;
  p[d] = node;

  if(d == len){
    int h = hash();    
    ostringstream oss;
    oss << '(';
    for(int i=0; i<len+1; ++i){
      if(i)oss << ',';
      oss << p[i] + 1;
    }
    oss << ')';
    //cout << h << ' ' << oss.str() << endl;
    v.push_back(oss.str());
    //m.insert(make_pair(h, oss.str()));
  }
  else{
    for(int i=0; i<size; ++i){
      if(visited[i])continue;
      if(adj[node][i] == 0)continue;
      //cout << node+1 << " => " << i+1 << endl;
      rec(i, d + 1);
    }
  }
  visited[node] = false;
  return ;
}

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

int main(void)
{
  int _9999 = 1;
  do{
    cin >> size >> len;
    if(cin.eof())break;
    if(0 < _9999);
    else cout << endl;
    for(int i=0; i<size; ++i){
      visited[i] = false;
      for(int j=0; j<size; ++j){
	cin >> adj[i][j];
      }
    }
    m.clear();
    v.clear();
    rec(0, 0);
    if(v.size()){
      FOR(i, v){
	cout << *i << endl;
      }
    }
    else cout << "no walk of length " << len  << endl;
      
    /*
    map<int, string>::iterator itr;
    for(itr = m.begin(); itr != m.end(); ++itr){
      cout << itr->second << endl;
    }
    */
  }while(cin >> _9999);
  return 0;
}
