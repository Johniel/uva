#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstring>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int NODE = 100 + 1;

int path[NODE];
int adj[NODE][NODE];
int m[NODE][NODE];
int size;

void rec(int i, int j)
{
  if(m[i][j] < 0){
    path[size++] = i;
  }
  else{
    rec(i, m[i][j]);
    rec(m[i][j], j);
  }
  return ;
}

int main(void)
{
  string s;
  map<string, int> name;
  map<int, string> rev;
  map< pair<string, string>, string > edge;
  int cnt = 0;
  fill(&adj[0][0], &adj[NODE-1][NODE], 1 << 22);
  fill(&m[0][0], &m[NODE-1][NODE], -1);
  while(getline(cin, s) && s.size()){
    string t, u, v, w;
    int i;
    for(i=0; s[i] != ','; ++i){
      t += s[i];
    }
    for(++i; s[i] != ','; ++i){
      u += s[i];
    }
    for(++i; s[i] != ','; ++i){
      v += s[i];
    }
    for(++i; i < s.size(); ++i){
      w += s[i];
    }
    t.resize(strlen("-------------------- "), ' ');
    u.resize(strlen("-------------------- "), ' ');
    v.resize(strlen("---------- "), ' ');

    if(name.find(t) == name.end()){
      name[t] = cnt;
      rev[cnt] = t;
      ++cnt;
    }
    if(name.find(u) == name.end()){
      name[u] = cnt;
      rev[cnt] = u;
      ++cnt;
    }
    int tmp = atoi(w.c_str());
    int src = name[t], dst = name[u];
    if(adj[src][dst] < tmp)continue;
    adj[src][dst] = adj[dst][src] = tmp;
    edge[make_pair(t, u)] = v;
    edge[make_pair(u, t)] = v;
  }
  REP(k, cnt)REP(i, cnt)REP(j, cnt){
    if(adj[i][j] > adj[i][k] + adj[k][j]){
      adj[i][j] = adj[i][k] + adj[k][j];
      m[i][j] = k;
    }
  }
  char buff[100];
  while(getline(cin, s)){ 
    puts("");
    puts("");
    cout << "From                 To                   Route      Miles" << endl;
    cout << "-------------------- -------------------- ---------- -----" << endl;
    string t, u;
    int i;
    for(i=0; s[i] != ','; ++i){
      t += s[i];
    }
    for(++i; i < s.size(); ++i){
      u += s[i];
    }
    t.resize(strlen("-------------------- "), ' ');
    u.resize(strlen("-------------------- "), ' ');

    size = 0;
    int sum = 0;
    rec(name[t], name[u]);
    path[size] = name[u];
    for(int i=0; i<size; ++i){
      string s = rev[path[i]];
      string t = rev[path[i + 1]];
      sprintf(buff, "%5d", adj[path[i]][path[i + 1]]);
      cout << s << t << edge[make_pair(s, t)] << buff << endl;
      sum += adj[path[i]][path[i + 1]];
    }
    puts("                                                     -----");
    printf("                                          Total      %5d\n", sum);
  }
  return 0;
}
