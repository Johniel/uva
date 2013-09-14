#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int N = 3;

struct State{
  char g[N][N];
  int cnt;
  State(){ cnt = 0; }
  State(char h[N][N]){
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
	g[i][j] = h[i][j];
      }
    }
  }
};

bool operator < (const State &a, const State &b)
{
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      if(a.g[i][j] != b.g[i][j]){
	return a.g[i][j] < b.g[i][j];
      }
    }
  }
  return false;
}

bool fin(State s)
{
  for(int i=0; i<N; ++i){
    if(s.g[i][0] != '.' && s.g[i][0] == s.g[i][1] && s.g[i][1] == s.g[i][2]){
      return true;
    }
    if(s.g[0][i] != '.' && s.g[0][i] == s.g[1][i] && s.g[1][i] == s.g[2][i]){
      return true;
    }
  }
  if(s.g[1][1] == '.')return false;
  if(s.g[0][0] == s.g[1][1] && s.g[1][1] == s.g[2][2])return true;
  if(s.g[2][0] == s.g[1][1] && s.g[1][1] == s.g[0][2])return true;
  return false;
}

State rot90(State s)
{
  char t[N][N];
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      t[j][N - i - 1] = s.g[i][j];
    }
  }
  return State(t);
}

void insert(set<State> &s, State t)
{
  s.insert(t);
  for(int i=0; i<3; ++i){
    t = rot90(t);
    s.insert(t);
  }
  return ;
}

set<State> generate(void)
{
  set<State> visited;
  State ini;
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      ini.g[i][j] = '.';
    }
  }
  queue<State> q;
  visited.insert(ini);
  for(q.push(ini); !q.empty(); q.pop()){
    State s = q.front();

    if(fin(s))continue;    

    char c = s.cnt % 2 ? 'O' : 'X';
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
	if(s.g[i][j] != '.')continue;
	State t = s;
	++t.cnt;
	t.g[i][j] = c;
	if(visited.count(t))continue;
	q.push(t); 
	insert(visited, t);
      }
    }
  }
  return visited;
}

int main(void)
{
  int tc;
  char g[N][N];
  set<State> s = generate();  
  for(cin >> tc; tc--; ){
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
	cin >> g[i][j];
      }
    }
    cout << (s.count(State(g))? "yes" : "no") << endl;
  }
  return 0;
}
