#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;

const int NUM = 8;

struct State{
  int num[NUM], cnt;
  State(){}
  State(int _num[], int _cnt){
    cnt = _cnt;
    copy(_num, _num + NUM, num);
  }
};

inline
int calc_hash(State s)
{
  int sum = 0;
  sum += abs(s.num[0] * 11);
  sum += abs(s.num[1] * 11 * 11);
  sum += abs(s.num[2] * 11 * 11 * 11);
  sum += abs(s.num[3] * 11 * 11 * 11 * 11);
  sum += abs(s.num[4] * 11 * 11 * 11 * 11 * 11);
  sum += abs(s.num[5] * 11 * 11 * 11 * 11 * 11 * 11);
  sum += abs(s.num[6] * 11 * 11 * 11 * 11 * 11 * 11 * 11);
  sum += abs(s.num[7] * 11 * 11 * 11 * 11 * 11 * 11 * 11 * 11);
  return sum;
}

const bool p[] = {false,
		  false,
		  true,
		  true,
		  false,
		  true,
		  false,
		  true,
		  false,
		  false,
		  false,
		  true,
		  false,
		  true,
		  false,
		  false,
		  false};

void make(queue<State> &q, set<int> &visited, State n, int idx)
{
  static int tmp[NUM];
  int c, h;
  State s;
  REP(i, NUM){
    if(n.num[idx] < 0 && n.num[i] < 0)continue;
    if(0 < n.num[idx] && 0 < n.num[i])continue;
    if(!p[abs(n.num[idx]) + abs(n.num[i])])continue;
    int asign = 0;

    REP(j, i){
      if(j == idx)continue;
      tmp[asign++] = n.num[j];
    }

    c = asign;
    tmp[asign++] = n.num[idx];
    for(int j=i; j<NUM; ++j){
      if(j == idx)continue;
      tmp[asign++] = n.num[j];
    }
    s = State(tmp, n.cnt + 1);

    h = calc_hash(s);
    if(visited.count(h) == 0){
      visited.insert(h);
      q.push(s);
    } 

    asign = c;
    tmp[asign++] = n.num[i];
    tmp[asign++] = n.num[idx];
    for(int j=i+1; j<NUM; ++j){
      if(j == idx)continue;
      tmp[asign++] = n.num[j];
    }
    s = State(tmp, n.cnt + 1); 

    h = calc_hash(s);
    if(visited.count(h) == 0){
      visited.insert(h);
      q.push(s);
    } 

  }
  return ;
}

int bfs(State ini)
{
  queue<State> q;
  set<int> visited;  
  visited.insert(calc_hash(ini));
  for(q.push(ini); !q.empty(); q.pop()){
    State n = q.front();
    if(calc_hash(n) == 1862778676)return n.cnt;
    REP(i, NUM){
      make(q, visited, n, i);
    }
  }
  return -1;
}

int main(void)
{
  int num[NUM], tc = 0;
  while(scanf("%d", num + 0) && num[0]){
    scanf("%d%d%d%d%d%d%d", 
	  num + 1, 
	  num + 2, 
	  num + 3, 
	  num + 4, 
	  num + 5, 
	  num + 6, 
	  num + 7);
    printf("Case %d: %d\n", ++tc, bfs(State(num, 0)));
  }
  return 0;
}
