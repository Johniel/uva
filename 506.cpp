#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const string SPACE = "   ";

map<string, int> name;
map<int, string> rev;
vector< vector<int> > need;
vector<int> cons;
int cnt;
queue<int> q;

inline
void clear(void)
{ 
  cnt = 0;
  while(!q.empty())q.pop();
  name.clear();
  rev.clear();
  need.clear();
  cons.clear();
  return ;
}

inline
void depend(string com)
{
  string s, t;
  istringstream iss(com);
  iss >> t >> t;  
  vector<int> edge;
  while(iss >> s){
    if(name.find(s) == name.end()){
      name[s] = cnt;
      rev[cnt] = s;
      ++cnt;
    }
    edge.push_back(name[s]);
  } 
  if(name.find(t) == name.end()){
    name[t] = cnt;
    rev[cnt] = t;
    ++cnt;
  }
  int idx = name[t];
  need.resize(max(cnt, (int)need.size()));
  need[idx].insert(need[idx].begin(), ALL(edge));
  int tmp = cons.size();
  if(tmp < need.size()){
    cons.resize(need.size(), 0);
  }
  return ;
}

inline
stack<int> ls(bool output)
{
  queue<int> tmp;
  stack<int> rm;
  while(!q.empty()){    
    int f = q.front();
    q.pop();
    if(cons[f]){
      if(output){
	printf("%s%s\n", SPACE.c_str(), rev[f].c_str());
      }
      tmp.push(f);
    }
    else rm.push(f);
  }
  q = tmp;
  return rm;
}

inline
void rec(int no, bool visited[], string msg, int add, int lim, bool flg)
{
  visited[no] = true;
  FOR(i, need[no]){
    if(visited[*i])continue;
    rec(*i, visited, msg, add, lim, flg);
  }
  if(flg && cons[no] == lim){
    cout << SPACE << msg << rev[no] << endl;
    q.push(no);
  }
  cons[no] += add;
  return ;
}

inline
void install(string com)
{
  string s;
  const string msg = "Installing ";
  istringstream iss(com);
  bool visited[cons.size()];
  fill(visited, visited + cons.size(), false);
  iss >> s >> s;
  if(name.find(s) == name.end()){
    depend("FOO " + s);
  }
  int no = name[s];
  if(cons[no]){
    printf("%s%s is already installed.\n", SPACE.c_str(), s.c_str());
  }
  else{
    rec(no, visited, msg, 2, 0, true);
    cons[no] -= 1;
  }
  return ;
}

inline
void remove(string com)
{
  string s;
  const string msg = "Removing ";
  istringstream iss(com);
  bool visited[cons.size()];
  fill(visited, visited + cons.size(), false);
  iss >> s >> s;
  int no = name[s];
  if(cons[no] == 0){
    printf("%s%s is not installed.\n", SPACE.c_str(), s.c_str());
  }
  else if(cons[no] != 1){
    printf("%s%s is still needed.\n", SPACE.c_str(), s.c_str());
  }
  else{
    rec(no, visited, msg, -2, 2, false);
    cons[no] += 1;
    stack<int> rm = ls(false);
    while(!rm.empty()){
      printf("%s%s%s\n", SPACE.c_str(), msg.c_str(), rev[rm.top()].c_str());
      rm.pop();
    }
  }
  return ;
}

int main(void)
{
  while(!cin.eof()){
    clear();
    for(string s; getline(cin, s); ){
      printf("%s\n", s.c_str());
      if(s[0] == 'E')break;
      else if(s[0] == 'D')depend(s);
      else if(s[0] == 'I')install(s);
      else if(s[0] == 'L')ls(true);
      else if(s[0] == 'R')remove(s);
    }
  }
  return 0;
}
